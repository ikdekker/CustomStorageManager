/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ExternalGHSConnection.cpp
 * Author: nick
 * 
 * Created on December 14, 2016, 12:00 PM
 */

#include "ExternalGHSConnection.h"

/**
 * Construct a connection with the external data source from GHS.
 * Establishes connection and posts to the credentials endpoint to
 * retrieve a session id which will be used in all further calls.
 * @param db DatabaseAdapter* pointer to the DatabaseAdapter to make db calls with
 */
ExternalGHSConnection::ExternalGHSConnection(DatabaseAdapter* db) : dbAdapter(db) {
    //establish connection with ghs site
    conn = new RestClient::Connection("https://api2.ghs-automotive.nl/api");
    RestClient::HeaderFields headers;
    headers["Accept"] = "application/json";
    headers["Content-Type"] = "application/json";
    headers["X-ApiKey"] = "f8408869-4c8e-49dc-8dda-fcf5332d9a7f";
    conn->SetHeaders(headers);
    RestClient::Response r = conn->post("/auth/credentials", "{\"username\": \"10769\", \"password\": \"07122007digo\"}");
    
    switch (r.code) {
        case 200:
        {
            json authResponse = json::parse(r.body);
            string ssId = authResponse["sessionId"];
            conn->AppendHeader("ss-id", ssId);
            conn->AppendHeader("Cookie", "ss-id=" + ssId);
            break;
        }
        case 401: 
        {
            throw std::runtime_error("401 in API"); 
            break;
        }
        case 404: 
            throw std::runtime_error("404 in API"); 
            break;
        default:
//            throw r.code;
            break;
    }
}

ExternalGHSConnection::~ExternalGHSConnection() {
}

/**
 * Retrieve a single order.
 * @param order string the order id
 * @return orderData
 */
orderData ExternalGHSConnection::fetchOrderData(string order) {
    orderData od;
    vector<string> orderIds = dbAdapter->fetchOrders("ghs_id");
    auto it = find(orderIds.begin(), orderIds.end(), order);
    if (it == orderIds.end()) {
        bool newOrders = fetchOrders();
        if (!newOrders) {
            //throw except
            throw "No such order " + order;
        }
        vector<string> orderIds = dbAdapter->fetchOrders("ghs_id");
        auto it2 = find(orderIds.begin(), orderIds.end(), order);
        if (it2 == orderIds.end()) {
            throw "No such order " + order;
        }
    }
    
    string data = dbAdapter->fetchOrderByExternalId(order);
    if (data == "") {
        throw "Data of order is empty";
    }
    json orderJson = json::parse(dbAdapter->fetchOrderByExternalId(order));

    string routeStr = orderJson["deliveryRoute"];
    od.deliveryRoute = routeStr.substr(6,13);
    
    od.extId = orderJson["orderId"];
    string digoIdStr = orderJson["externalOrderId"];
    od.intId = "";
    od.ref = digoIdStr;
    stringstream ss(digoIdStr);
    string intId = "";
    string license = "";
    string cur;
    int i = 0;
    while (getline(ss, cur, ',')) {
        if (i == 0) {
            //probably license ?
            license = cur;
        }
        if (i == 1) {
            //probably a workorder id here
            intId = cur.substr(3);
        }
        i++;
    }
    if (i == 1) {
        //probably not a license plate in the intid, what to do?
        od.license = "";
    }
    od.intId = intId;
    od.license = license;
//    @todo call parsedata
//    store orderdata into struct + loop over product ids and store in struct as well.
    json productJson = orderJson["/items"_json_pointer];
    
    for (auto elem : productJson) {
        string prodId = elem["productId"];
        string prodName = elem["productName"];
        int prodQuant = elem["quantity"];
        productData *pd = new productData;
        pd->amount = prodQuant;
        pd->productId = prodId;
        pd->productName = prodName;
        od.products.push_back(pd);
    }
    
    return od;
}

/**
 * Fetch only the product from the external connection.
 * @param productId
 * @return 
 */
productData ExternalGHSConnection::fetchOrderProduct(string productId) {
    
}

/**
 * Create a usable orderData struct with all the relevant data parsed from json
 * @param j The json data to be parsed
 * @return orderData
 */
orderData ExternalGHSConnection::parseData(json j) {

}

/**
 * Fetches new orders from the GHS API connection.
 * Updates the orders in the database when new orders have been found.
 * @param offset
 * @return bool stating whether the orders have been updated
 */
bool ExternalGHSConnection::fetchOrders() {
    bool newOrder = false;
    vector<string> orderIds = dbAdapter->fetchOrders("ghs_id");
    bool exists = 0;
    int offset = 0;
    while (!exists && offset < 100) {
        stringstream orderCall;
        orderCall << "/orders?skip=" << offset << "&take=10";
        RestClient::Response r = conn->get(orderCall.str());
        json orders = json::parse(r.body);
        orders = orders["orders"];
        for (auto it = orders.begin(); it != orders.end(); it++) {
            stringstream orderJ;
            orderJ << *it;
            json a = json::parse(orderJ.str());
            string extId = a["orderId"];
            string intIdStr = a["externalOrderId"];
            stringstream ss(intIdStr);
            string intId = "";
            string cur;
            int i = 0;
            while (getline(ss, cur, ',')) {
                if (i == 1) {
                    //probably a workorder id here
                    intId = cur.substr(3);
                }
                i++;
            }
            
//            string intId = 
            auto findOrder = find(orderIds.begin(), orderIds.end(), extId);
            if (findOrder != orderIds.end()) {
                //the order already exists
                exists = 1;
                break;
            }
            dbAdapter->addExternalOrder(extId, intId, orderJ.str());
        }
        offset += 10;
        newOrder = true;
    }
    return newOrder;
}

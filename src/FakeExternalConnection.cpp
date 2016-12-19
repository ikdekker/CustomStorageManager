/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FakeExternalConnection.cpp
 * Author: nick
 * 
 * Created on December 6, 2016, 12:03 PM
 */

#include "FakeExternalConnection.h"

FakeExternalConnection::FakeExternalConnection() {
}

FakeExternalConnection::~FakeExternalConnection() {
}

productData FakeExternalConnection::fetchOrderProduct(string productId) {
    productData prod;
    // @todo: make API call here
    
    ifstream f("data/productDataGHS.json");
    
    json j;
    j << f;
    
    prod.amount = j["unitsPerSale"];
    prod.productId = productId;
    prod.productName = j["name"];
//    cout << prod;
    return prod;
}

orderData FakeExternalConnection::parseData(json j) {
    orderData order;
    order.extId = j["ghs_id"];
    order.intId = j["dms_id"];
    order.license = j["license"];
    order.mechanic = j["mechanic"];
    order.status = j["status"];
    json prodJson = j["/products"_json_pointer];
//    cout << order.id << " thats an order!" << endl;
//    cout << order.license << " thats a license!" << endl;
//    cout << order.mechanic << " thats a mechanic!" << endl;
//    cout << order.status << " thats a status!" << endl;
    for (auto prods = prodJson.begin(); prods != prodJson.end(); prods++) {
        string id = (*prods)["id"];
        productData *prd = order.getProductById(id);
        if (prd != nullptr) {
            prd->amount++;
        } else {
            productData *pData = new productData;
            pData->productId = id;
            pData->productName = (*prods)["name"];
            pData->amount = 1;
            order.products.push_back(pData);
        }
//        pData->print();
    }
//    order.getProductById(1);
    return order;
}

/**
 * Retrieve data from the External connection and store results in the 
 * local database
 * \param order
 */
orderData FakeExternalConnection::fetchOrderData(string order) {    
    //retrieve data from CarSystems
    
    ifstream f("config/externalData.json");
    json moduleJson;
    try {
        moduleJson << f;
    } catch (const exception& ex) {
        // specific handling for all exceptions extending std::exception
        cerr << "Error occurred: " << ex.what() << endl;
    }
    //parseData with retrieved data
    orderData od = parseData(moduleJson);
    //store parsed data in database    
    return od;
}
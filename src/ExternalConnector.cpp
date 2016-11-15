/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Connector.cpp
 * Author: nick
 * 
 * Created on November 8, 2016, 3:14 PM
 */

#include "ExternalConnector.h"

ExternalConnector::ExternalConnector() {

}

ExternalConnector::~ExternalConnector() {

}
/**
 * Retrieve data from the External connection and store results in the 
 * local database
 * \param order
 */
void ExternalConnector::fetchOrderData(int order) {
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
    productData pd = parseData(moduleJson);
    //store parsed data in database    
    productData.print();
}

orderData ExternalConnector::parseData(json j) {
    orderData order;
    j = j["/data_entry"_json_pointer];
    order->id = j["/id"_json_pointer];
    order->license = j["/license"_json_pointer];
    order->mechanic = j["/mechanic"_json_pointer];
    order->status = j["/status"_json_pointer];
    json prodJson = j["/id"_json_pointer];
    cout << order->id << " thats an order!" << endl;
    
}

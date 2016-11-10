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
    
    //parseData with retrieved data
    
    //store parsed data in database    
}

productData ExternalConnector::parseData(string data) {

}

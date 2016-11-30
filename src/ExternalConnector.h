/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Connector.h
 * Author: nick
 *
 * Created on November 8, 2016, 3:14 PM
 */

#ifndef EXTERNALCONNECTOR_H
#define EXTERNALCONNECTOR_H

#include <src/DatabaseAdapter.h>
#include <string>
#include "include/json.hpp"
using json = nlohmann::json;

class ExternalConnector {
public:
    ExternalConnector();
    void fetchOrderData(int order);
    productData parseData(string data);
    virtual ~ExternalConnector();
private:
    
};

#endif /* CONNECTOR_H */


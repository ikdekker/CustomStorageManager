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
#include <vector>
#include "include/json.hpp"
#include <fstream>

using json = nlohmann::json;
using namespace std;

struct orderData {
    int id;
    string license;
    string mechanic;
    int status;
    vector<productData*> products;
};

class ExternalConnector {
public:
    ExternalConnector();
    void fetchOrderData(int order);
    orderData parseData(json j);
    virtual ~ExternalConnector();
private:
    
};

#endif /* CONNECTOR_H */


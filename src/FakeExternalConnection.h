/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   FakeExternalConnection.h
 * Author: nick
 *
 * Created on December 6, 2016, 12:03 PM
 */

#ifndef FAKEEXTERNALCONNECTION_H
#define FAKEEXTERNALCONNECTION_H

#include "ExternalConnector.h"

class FakeExternalConnection: public ExternalConnector {
public:
    FakeExternalConnection();
    virtual ~FakeExternalConnection();
    virtual orderData fetchOrderData(string order);
    virtual productData fetchOrderProduct(string productId);
    virtual orderData parseData(json j);
private:

};

#endif /* FAKEEXTERNALCONNECTION_H */


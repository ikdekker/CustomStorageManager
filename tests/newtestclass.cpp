/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   newtestclass.cpp
 * Author: nick
 *
 * Created on Oct 19, 2016, 12:16:32 PM
 */

#include "newtestclass.h"
#include "../StorageManagement.h"


CPPUNIT_TEST_SUITE_REGISTRATION(newtestclass);

newtestclass::newtestclass() {

}

void newtestclass::setUp() {
    this->storageMock = new StorageManagement();
}

void newtestclass::tearDown() {
    free(this->storageMock);
}

newtestclass::~newtestclass() {

}


void newtestclass::testMethod() {
    
    CPPUNIT_ASSERT_EQUAL(4, this->storageMock->testThis());
}

void newtestclass::testFailedMethod() {
    CPPUNIT_ASSERT(false);
}


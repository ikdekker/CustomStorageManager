
/*
 * File:   MatrixControlTest.cpp
 * Author: Gebruiker
 *
 * Created on Oct 26, 2016, 11:34:39 AM
 */

#include "MatrixControlTest.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/SimpleString.h"
#include "CppUTestExt/MockSupport.h"
#include "../src/ConfigFactory.h"
#include "data/TestResources.h"
#include <string>

CPPUNIT_TEST_SUITE_REGISTRATION(MatrixControlTest);

MatrixControlTest::MatrixControlTest() {
}

MatrixControlTest::~MatrixControlTest() {
}

void MatrixControlTest::setUp() {
}

void MatrixControlTest::tearDown() {
}

void MatrixControlTest::testTurnOn() {
//    matrixs
    
//    ConfigFactory *ab = new ConfigFactory();
    mock().expectOneCall("getModule");    
//    ab->getModule(TestResources::validJsonModule());
    mock().checkExpectations();
}

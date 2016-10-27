
/*
 * File:   MatrixControlTest.cpp
 * Author: Gebruiker
 *
 * Created on Oct 26, 2016, 11:34:39 AM
 */

#include "CppUTest/SimpleString.h"
#include "MatrixControlTest.h"
#include "CppUTest/TestHarness.h"
#include "CppUTest/SimpleString.h"
#include "CppUTestExt/MockSupport.h"
#include "../src/ConfigFactory.h"
#include "../src/MatrixControl.h"
#include "../src/ModuleEntity.h"
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

void MatrixControlTest::testCreationWithModuleServer() {
//    matrixs
    ModuleServer m;
    ConfigFactory cf;
    ModuleEntity e(cf.parseModuleJson(TestResources::validJsonModule()));
    m.addModule(&e);
    
    MatrixControl *mControl = new MatrixControl(&m);
    mock().expectOneCall("getServer");
    
    ModuleEntity *b = mControl->getServer()->getModuleById(3);
    mock().checkExpectations();
//    CPPUNIT_ASSERT_EQUAL(3, b->getId());
    delete mControl;
}
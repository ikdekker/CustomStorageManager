
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
    ModuleServer m;
    
    vector<int> vc {2};
    ModuleEntity e(3,3,3,vc);
    m.addModule(&e);
    
    MatrixControl *mControl = new MatrixControl(&m);
    
    Point actualPoint = mControl->indexToLocation(4,1);
    Point expectedPoint;
    expectedPoint.x = 1;
    expectedPoint.y = 2;
    //@todo:overload struct comparator 
    CPPUNIT_ASSERT_EQUAL(expectedPoint.x == actualPoint.x);
    CPPUNIT_ASSERT_EQUAL(expectedPoint.y == actualPoint.y);
    delete mControl;
}

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

void MatrixControlTest::testCreationWithModuleServer() {
//    matrixs
    ModuleServer *m = new ModuleServer();
    ModuleEntity *e = new ModuleEntity(TestResources::validJsonModule());
    m->addModule(e);
    MatrixControl mControl(m);
    
    ModuleEntity *b = MatrixControl->getServer()->getModuleById(3);
    
    CPPUNIT_ASSERT_EQUAL(3, b->getId());
    
    delete e, m, b;
}


/*
 * File:   ModuleServerTest.cpp
 * Author: Gebruiker
 *
 * Created on Oct 25, 2016, 3:00:15 PM
 */

#include "ModuleServerTest.h"
#include <vector>


CPPUNIT_TEST_SUITE_REGISTRATION(ModuleServerTest);

ModuleServerTest::ModuleServerTest() {
}

ModuleServerTest::~ModuleServerTest() {
}

void ModuleServerTest::setUp() {
    mServer = new ModuleServer();
}

void ModuleServerTest::tearDown() {
}

void ModuleServerTest::testAddModule() {
    std::vector<int> vect {2};
    ModuleEntity modEntity(1,2,3,vect);
    CPPUNIT_ASSERT(nullptr == mServer->getModuleById(modEntity.getId()));
    mServer->addModule(&modEntity);
    CPPUNIT_ASSERT(&modEntity == mServer->getModuleById(modEntity.getId()));
}


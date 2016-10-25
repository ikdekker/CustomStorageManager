
/*
 * File:   EntityTest.cpp
 * Author: Gebruiker
 *
 * Created on Oct 25, 2016, 9:14:27 AM
 */

#include "EntityTest.h"
#include "data/TestResources.h"
#include <vector>

#include "../src/ConfigFactory.h"
struct moduleData;
CPPUNIT_TEST_SUITE_REGISTRATION(EntityTest);

EntityTest::EntityTest() {
}

EntityTest::~EntityTest() {
}

void EntityTest::setUp() {
}

void EntityTest::tearDown() {
}

void EntityTest::testEntityValidFromStruct() {
    vector<int> vect {1};
    moduleData modData = TestResources::getModuleData(1,2,3, vect);
    ModuleEntity testEntity(&modData);
    
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "The expected id was not equal to the actual id. (EnitityTest)" ,1,testEntity.getId());
    
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "The expected amount of rows was not equal to the actual amount. (EnitityTest)" ,2,testEntity.getRows());
    CPPUNIT_ASSERT_MESSAGE("The disabled rows were not as expected. (EnitityTest)", vect == testEntity.getDisabledRows());
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "The expected amount of columns was not equal to the actual amount. (EnitityTest)" ,3,testEntity.getCols());
}

void EntityTest::testEntityValidFromVars() {
    vector<int> vect {2};
    ModuleEntity testEntity(1,2,3, vect);
    
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "The expected id was not equal to the actual id. (EnitityTest)" ,1,testEntity.getId());
    
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "The expected amount of rows was not equal to the actual amount. (EnitityTest)" ,2,testEntity.getRows());
    CPPUNIT_ASSERT_MESSAGE("The disabled rows were not as expected. (EnitityTest)", vect == testEntity.getDisabledRows());
    CPPUNIT_ASSERT_EQUAL_MESSAGE( "The expected amount of columns was not equal to the actual amount. (EnitityTest)" ,3,testEntity.getCols());
}

void EntityTest::testEntityInvalidData() {
    vector<int> vect {4};
    moduleData modData = TestResources::getModuleData(1,2,3, vect);
    
    CPPUNIT_ASSERT_THROW(ModuleEntity testEntity(1,3,3,vect), std::out_of_range);
    CPPUNIT_ASSERT_THROW(ModuleEntity testEntity(&modData);, std::out_of_range);
}


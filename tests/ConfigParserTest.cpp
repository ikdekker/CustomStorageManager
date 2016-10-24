
/*
 * File:   ConfigParser.cpp
 * Author: Gebruiker
 *
 * Created on Oct 24, 2016, 2:26:27 PM
 */

#include "ConfigParserTest.h"
#include <vector>

CPPUNIT_TEST_SUITE_REGISTRATION(ConfigParser);

ConfigParser::ConfigParser() {
}

ConfigParser::~ConfigParser() {
}

void ConfigParser::setUp() {
    factory = new ConfigFactory();
}

void ConfigParser::tearDown() {
}

void ConfigParser::testMethod() {
    const json j = R"(
    {
    "id" : 0,
    "rows": 5,
    "columns": 11,
    "disableRows": "1,2,3"
  }
    )"_json;
    moduleData result = factory->parseModuleJson(j);
    moduleData expectedModule;
    vector<int> disableVect;
    disableVect.push_back(1);
    disableVect.push_back(2);
    disableVect.push_back(3);
    expectedModule.id = 0;
    expectedModule.rows = 5;
    expectedModule.cols = 11;
    expectedModule.disabled = disableVect;
    CPPUNIT_ASSERT_EQUAL(expectedModule.id, result.id);
    CPPUNIT_ASSERT_EQUAL(expectedModule.rows, result.rows);
    CPPUNIT_ASSERT_EQUAL(expectedModule.cols, result.cols);
    CPPUNIT_ASSERT_NO_THROW(result.disabled.at(2));
    CPPUNIT_ASSERT_THROW(result.disabled.at(2), std::out_of_range);
    CPPUNIT_ASSERT(expectedModule.disabled == result.disabled);
}

void ConfigParser::testFailedMethod() {
    CPPUNIT_ASSERT(false);
}


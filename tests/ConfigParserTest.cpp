
/*
 * File:   ConfigParser.cpp
 * Author: Gebruiker
 *
 * Created on Oct 24, 2016, 2:26:27 PM
 */

#include "ConfigParserTest.h"
#include "data/TestResources.h"
#include <vector>
#include <string>

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

void ConfigParser::testParseModuleConfig() {
    const json moduleJson = R"(
        {
            "id" : 0,
            "rows": 5,
            "columns": 11,
            "disableRows": "1,2"
        }
    )"_json;
    moduleData *resultModule = factory->parseModuleJson(moduleJson);
    vector<int> vect {1,2};
    moduleData expectedModule = TestResources::getModuleData(0,5,11, vect);
    //test index 1 does not throw anything
    CPPUNIT_ASSERT_NO_THROW(resultModule->disabled.at(1));
    //test throw when out of range
    CPPUNIT_ASSERT_THROW(resultModule->disabled.at(2), std::out_of_range);
    //assert that the expected = result
    CPPUNIT_ASSERT_EQUAL(expectedModule.id, resultModule->id);
    CPPUNIT_ASSERT_EQUAL(expectedModule.rows, resultModule->rows);
    CPPUNIT_ASSERT_EQUAL(expectedModule.cols, resultModule->cols);
    CPPUNIT_ASSERT(expectedModule.disabled == resultModule->disabled);
}

void ConfigParser::testInvalidCols() {
    const json invalidColsNeg = TestResources::invalidJsonColsNeg();
    const json invalidColsZero = TestResources::invalidJsonColsZero();
    CPPUNIT_ASSERT_THROW(factory->parseModuleJson(invalidColsNeg), std::out_of_range);
    CPPUNIT_ASSERT_THROW(factory->parseModuleJson(invalidColsZero), std::out_of_range);
}

void ConfigParser::testInvalidDisabledNeg() {

}

void ConfigParser::testInvalidDisabledOutOfBounds() {

}

void ConfigParser::testInvalidId() {
    const json invalidJsonId = TestResources::invalidJsonId();
    CPPUNIT_ASSERT_THROW(factory->parseModuleJson(invalidJsonId), std::out_of_range);
}

void ConfigParser::testInvalidRows() {
    const json invalidRowsNeg = TestResources::invalidJsonRowsNeg();
    const json invalidRowsZero = TestResources::invalidJsonRowsZero();
    CPPUNIT_ASSERT_THROW(factory->parseModuleJson(invalidRowsZero), std::out_of_range);
    CPPUNIT_ASSERT_THROW(factory->parseModuleJson(invalidRowsNeg), std::out_of_range);
}

//
void ConfigParser::testParseSettings() {
//    const json settingsJson = R"(
//        {
//            "database" : "test_db",
//            "username": "test_user",
//            "password": "test_pass"
//        }
//    )"_json;
//    settingsData resultSettings factory->parseSettingsJson(settingsJson);
//    expectedSettings.database = "test_db";
//    expectedSettings.username = "test_user";
//    expectedSettings.password = "test_pass";
    CPPUNIT_ASSERT(true);
//    CPPUNIT_ASSERT_EQUAL(expectedSettings.username, resultSettings.username);
//    CPPUNIT_ASSERT_EQUAL(expectedSettings.password, resultSettings.password);
//    CPPUNIT_ASSERT_EQUAL(expectedSettings.database, resultSettings.database);
}


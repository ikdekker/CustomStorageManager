
/*
 * File:   ConfigParser.cpp
 * Author: Gebruiker
 *
 * Created on Oct 24, 2016, 2:26:27 PM
 */

#include "ConfigParserTest.h"
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
    moduleData resultModule = factory->parseModuleJson(moduleJson);
    moduleData expectedModule;
    vector<int> disableVect;
    disableVect.push_back(1);
    disableVect.push_back(2);
    expectedModule.id = 0;
    expectedModule.rows = 5;
    expectedModule.cols = 11;
    expectedModule.disabled = disableVect;
    //test index 1 does not throw anything
    CPPUNIT_ASSERT_NO_THROW(resultModule.disabled.at(1));
    //test throw when out of range
    CPPUNIT_ASSERT_THROW(resultModule.disabled.at(2), std::out_of_range);
    //assert that the expected = result
    CPPUNIT_ASSERT(expectedModule.disabled == resultModule.disabled);
}

void ConfigParser::testParseSettings() {
    const json settingsJson = R"(
        {
            "database" : "test_db",
            "username": "test_user",
            "password": "test_pass"
        }
    )"_json;
    settingsData resultSettings factory->parseSettingsJson(settingsJson);
    expectedSettings.database = "test_db";
    expectedSettings.username = "test_user";
    expectedSettings.password = "test_pass";

    CPPUNIT_ASSERT(expectedSettings == resultSettings);
}


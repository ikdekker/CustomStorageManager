
/*
 * File:   ConfigParser.h
 * Author: Gebruiker
 *
 * Created on Oct 24, 2016, 2:26:27 PM
 */

#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/ConfigFactory.h"

class ConfigParser : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ConfigParser);

    CPPUNIT_TEST(testParseModuleConfig);
    CPPUNIT_TEST(testParseSettings);
    CPPUNIT_TEST(testInvalidCols);
    CPPUNIT_TEST(testInvalidRows);
    CPPUNIT_TEST(testInvalidId);

    CPPUNIT_TEST_SUITE_END();

public:
    ConfigParser();
    virtual ~ConfigParser();
    void setUp();
    void tearDown();

private:
    void testParseModuleConfig();
    void testInvalidId();
    void testInvalidRows();
    void testInvalidCols();
    void testInvalidDisabledNeg();
    void testInvalidDisabledOutOfBounds();
    void testParseSettings();
    ConfigFactory *factory;
};

#endif /* CONFIGPARSER_H */


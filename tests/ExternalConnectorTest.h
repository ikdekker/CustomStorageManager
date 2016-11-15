/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ExternalConnectorTest.h
 * Author: nick
 *
 * Created on Nov 8, 2016, 1:36:38 PM
 */

#ifndef EXTERNALCONNECTORTEST_H
#define EXTERNALCONNECTORTEST_H

#include <cppunit/extensions/HelperMacros.h>

class ExternalConnectorTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ExternalConnectorTest);

    CPPUNIT_TEST(testParseExternalData);

    CPPUNIT_TEST_SUITE_END();

public:
    ExternalConnectorTest();
    virtual ~ExternalConnectorTest();
    void setUp();
    void tearDown();

private:
    void testParseExternalData();
};

#endif /* EXTERNALCONNECTORTEST_H */


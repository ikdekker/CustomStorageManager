
/*
 * File:   ModuleServerTest.h
 * Author: Gebruiker
 *
 * Created on Oct 25, 2016, 3:00:15 PM
 */

#ifndef MODULESERVERTEST_H
#define MODULESERVERTEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "../src/ModuleEntity.h"
#include "../src/ModuleServer.h"

class ModuleServerTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(ModuleServerTest);

    CPPUNIT_TEST(testAddModule);

    CPPUNIT_TEST_SUITE_END();

public:
    ModuleServerTest();
    virtual ~ModuleServerTest();
    void setUp();
    void tearDown();

private:
    void testAddModule();
    ModuleServer *mServer;
};

#endif /* MODULESERVERTEST_H */


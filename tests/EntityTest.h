
/*
 * File:   EntityTest.h
 * Author: Gebruiker
 *
 * Created on Oct 25, 2016, 9:14:26 AM
 */

#ifndef ENTITYTEST_H
#define ENTITYTEST_H

#include <cppunit/extensions/HelperMacros.h>

class EntityTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(EntityTest);

    CPPUNIT_TEST(testEntityValidFromVars);
    CPPUNIT_TEST(testEntityValidFromStruct);
    CPPUNIT_TEST(testEntityInvalidData);

    CPPUNIT_TEST_SUITE_END();

public:
    EntityTest();
    virtual ~EntityTest();
    void setUp();
    void tearDown();

private:
    void testEntityValidFromVars();
    void testEntityValidFromStruct();
    void testEntityInvalidData();
};

#endif /* ENTITYTEST_H */


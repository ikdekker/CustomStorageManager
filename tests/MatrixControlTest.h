
/*
 * File:   MatrixControlTest.h
 * Author: Gebruiker
 *
 * Created on Oct 26, 2016, 11:34:39 AM
 */

#ifndef MATRIXCONTROLTEST_H
#define MATRIXCONTROLTEST_H
#include <stdio.h>

#include <cppunit/extensions/HelperMacros.h>

class MatrixControlTest : public CPPUNIT_NS::TestFixture {
    CPPUNIT_TEST_SUITE(MatrixControlTest);

    CPPUNIT_TEST(testTurnOn);

    CPPUNIT_TEST_SUITE_END();

public:
    MatrixControlTest();
    virtual ~MatrixControlTest();
    void setUp();
    void tearDown();

private:
    void testTurnOn();
};

#endif /* MATRIXCONTROLTEST_H */


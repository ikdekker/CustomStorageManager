/* 
 * File:   IndexAllocationTest
 * Author: Gebruiker
 *
 * Created on Oct 31, 2016, 3:10:58 PM
 */

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <vector>

using namespace std;
class DatabaseMock : public DBAdapter
{
public:
    virtual void getEntriesByModule()
    {
        vector<int> *nextEmpty {0,1,2,3,4};
        vector<int> *gapEmpty {0,1,2,3,5};
        vector<int> *disabledNextEmpty {0,1,2,3,6};
        mock().actualCall("getEntriesByModule").onObject(this).withIntParameter("moduleId",3).returnPointerValueOrDefault(nextEmpty);
    }
};

TEST_GROUP(TestSuite) {
};

TEST(TestSuite, IndexAllocationFindNext) {
    FAIL("Nothing to test yet ...");
}

void setup() {
   
}

void teardown() {
    mock().clear();
}
/* 
 * File:   IndexAllocationTest
 * Author: Gebruiker
 *
 * Created on Oct 31, 2016, 3:10:58 PM
 */

#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <vector>
#include <src/DatabaseAdapter.h>
#include <string>
#include "src/StorageManagement.h"
using namespace std;
class DatabaseMock : public DatabaseAdapter {
public:
    DatabaseMock(string db, string user, string pass) : DatabaseAdapter(db,user,pass){};
    virtual void getEntriesByModule()
    {
        vector<int> nextEmpty = {0,1,2,3,4};
        vector<int> gapEmpty ={0,1,2,3,5};
        vector<int> disabledNextEmpty ={0,1,2,3,6};
        vector<int> fullIndex ={0,1,2,3,4,5,6};
        mock().actualCall("getEntriesByModule").onObject(this).withIntParameter("moduleId",1).returnPointerValueOrDefault(&nextEmpty);
        mock().actualCall("getEntriesByModule").onObject(this).withIntParameter("moduleId",2).returnPointerValueOrDefault(&gapEmpty);
        mock().actualCall("getEntriesByModule").onObject(this).withIntParameter("moduleId",3).returnPointerValueOrDefault(&disabledNextEmpty);
        mock().actualCall("getEntriesByModule").onObject(this).withIntParameter("moduleId",4).returnPointerValueOrDefault(&fullIndex);
    }
};

TEST_GROUP(TestSuite) {
};

TEST(TestSuite, IndexAllocationFindNext) {
    DatabaseAdapter* dbMock = new DatabaseMock("a","b","c");
    dbMock->getEntriesByModule(1);
    
    StorageManagement s;
    s.setDbAdapter(dbMock);
    int freeIndex = s.findFreeSpot();
    
    CHECK_EQUAL(5, freeIndex);
}

TEST(TestSuite, IndexAllocationFindNeithGap) {
    DatabaseAdapter* dbMock = new DatabaseMock("a","b","c");
    dbMock->getEntriesByModule(2);
    
    StorageManagement s;
    s.setDbAdapter(dbMock);
    int freeIndex = s.findFreeSpot();
    
    CHECK_EQUAL(4, freeIndex);
}


TEST(TestSuite, IndexAllocationFindNWithGap) {
    DatabaseAdapter* dbMock = new DatabaseMock("a","b","c");
    dbMock->getEntriesByModule(3);
    
    StorageManagement s;
    s.setDbAdapter(dbMock);
    int freeIndex = s.findFreeSpot();
    
    CHECK_EQUAL(7, freeIndex);
}

TEST(TestSuite, IndexAllocationFindNexWithGap) {
    DatabaseAdapter* dbMock = new DatabaseMock("a","b","c");
    dbMock->getEntriesByModule(4);
    
    StorageManagement s;
    s.setDbAdapter(dbMock);
    int freeIndex = s.findFreeSpot();
    
    CHECK_EQUAL(-1, freeIndex);
}

void setup() {
}

void teardown() {
    mock().clear();
}
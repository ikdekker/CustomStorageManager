/* 
 * File:   IndexAllocationTest
 * Author: Gebruiker
 *
 * Created on Oct 31, 2016, 3:10:58 PM
 */

#include <src/DatabaseAdapter.h>
#include "src/StorageManagement.h"
#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include <tests/data/TestResources.h>
#include <vector>
#include <string>

using namespace std;

class DatabaseMock : public DatabaseAdapter {
public:

    DatabaseMock(string db, string user, string pass) : DatabaseAdapter(db, user, pass) {
    };

    virtual vector<int>* getEntriesByModule(int moduleId) {
        //        vector<int> disabledNextEmpty =;
        //        vector<int> fullIndex ={0,1,2,3,4,5,6};
        mock().actualCall("getEntriesByModule").onObject(this).withIntParameter("moduleId", 1).returnValue().getPointerValue();
        return (vector<int>*) mock().returnPointerValueOrDefault(nullptr);
    }
};

TEST_GROUP(TestSuite) {
    DatabaseAdapter *dbMock = new DatabaseMock("a", "b", "c");
    StorageManagement *storage;

    void setup() {
        storage = new StorageManagement();
        storage->setDbAdapter(dbMock);
    }
    void teardown() {
        mock().clear();
        delete dbMock;
    }
};

TEST(TestSuite, IndexAllocationFindNext) {
    vector<int> disabled {};
    ModuleServer *server = new ModuleServer();
    ModuleEntity *entity = TestResources::getModule(1, 3, 3, disabled);
    server->addModule(entity);
    storage->setModuleServer(server);
    vector<int> *nextEmpty = new vector<int>{0, 1, 2, 3, 4};

    mock().expectOneCall("getEntriesByModule").onObject(dbMock).withIntParameter("moduleId", 1).andReturnValue(nextEmpty);
    int freeSpot = storage->findFreeSpot(1);
    CHECK_EQUAL(5, freeSpot);
}

TEST(TestSuite, IndexAllocationFindNextGap) {
    vector<int> disabled {};
    ModuleServer *server = new ModuleServer();
    server->addModule(TestResources::getModule(1, 3, 3, disabled));
    storage->setModuleServer(server);
    vector<int> *nextEmpty = new vector<int>{0, 1, 2, 3, 5};

    mock().expectOneCall("getEntriesByModule").onObject(dbMock).withIntParameter("moduleId", 1).andReturnValue(nextEmpty);
    int freeSpot = storage->findFreeSpot(1);

    delete server, nextEmpty,storage;
    CHECK_EQUAL(4, freeSpot);
}

TEST(TestSuite, IndexAllocationFindDisabledNextEmpty) {
    vector<int> disabled {2};
    ModuleServer *server = new ModuleServer();
    server->addModule(TestResources::getModule(1, 3, 3, disabled));
    storage->setModuleServer(server);
    vector<int> *nextEmpty = new vector<int>{0,1,2,6};

    mock().expectOneCall("getEntriesByModule").onObject(dbMock).withIntParameter("moduleId", 1).andReturnValue(nextEmpty);
    int freeSpot = storage->findFreeSpot(1);

    delete server, nextEmpty,storage;
    CHECK_EQUAL(7, freeSpot);
}

TEST(TestSuite, IndexAllocationFindNexWithGap) {
    vector<int> disabled {};
    ModuleServer *server = new ModuleServer();
    server->addModule(TestResources::getModule(1, 3, 3, disabled));
    storage->setModuleServer(server);
    vector<int> *nextEmpty = new vector<int>{0,1,2,3,4,5,6,7,8};

    mock().expectOneCall("getEntriesByModule").onObject(dbMock).withIntParameter("moduleId", 1).andReturnValue(nextEmpty);
    int freeSpot = storage->findFreeSpot(1);

    delete server, nextEmpty,storage;
    CHECK_EQUAL(-1, freeSpot);
}

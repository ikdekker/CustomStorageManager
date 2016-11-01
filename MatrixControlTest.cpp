/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "CppUTest/TestHarness.h"
#include "CppUTestExt/MockSupport.h"
#include "src/MatrixControl.h"
#include <vector>
#include <iostream>
class Mocked : public MatrixControl {
public:
    Mocked(ModuleServer *mServer) : MatrixControl(mServer){}
    virtual ModuleServer* getServer() override {
        mock().actualCall("getServer").onObject(this);
    }
};

TEST_GROUP(MatrixTests) {
};

TEST(MatrixTests, AddTest) {
    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    ModuleServer m;
    
    MatrixControl *mControl = new Mocked(&m);
    vector<int> vc {2};
    ModuleEntity e(3,3,3,vc);
    m.addModule(&e);

    mock().expectOneCall("getServer").onObject(mControl);
    
    ModuleServer *b = mControl->getServer();

    mock().checkExpectations();
    delete mControl;
    MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
}

void teardown() {
    mock().clear();
}
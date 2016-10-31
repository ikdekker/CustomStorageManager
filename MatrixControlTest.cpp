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
//class Mocked : public MatrixControl {
//public:
//    Mocked(ModuleServer *mServer) : MatrixControl(mServer){}
//    virtual ModuleServer* getServer() override {
//        mock().actualCall("getServer").onObject(this);
//    }
//};

TEST_GROUP(MatrixTests) {
    void teardown () {
        mock().clear();
    }
};

TEST(MatrixTests, IndexToRowNormal) {
    ModuleServer m;
    
    MatrixControl *mControl = new MatrixControl(&m);
    vector<int> vc {2};
    ModuleEntity e(3,3,3,vc);
    m.addModule(&e);

//    mControl->indexToLocation(4,1);
    
//    CHECK(1,1);
    delete mControl;
}

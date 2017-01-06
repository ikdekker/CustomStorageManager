/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on October 19, 2016, 12:12 PM
 */

#include <cstdlib>

#include "src/StorageManagement.h"
#include "src/MatrixControl.h"
#include "src/DatabaseAdapter.h"
#include "src/ExternalConnector.h"
#include "src/FakeExternalConnection.h"
#include "src/ExternalGHSConnection.h"
#include "src/LabelDriver.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
LabelDriver l;
l.printLabel("a && rm");
//    StorageManagement *s = new StorageManagement();
  //  MatrixControl *a = new MatrixControl(s->getServer());
   // s->setMatrix(a);
//while(1)
  //  a->runThrough(-1);
//    s->run();
    return 0;
}


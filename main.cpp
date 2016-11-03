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

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    StorageManagement *s = new StorageManagement();
    MatrixControl *a = new MatrixControl(s->getServer());
    a->ledOn(10, 0);
    a->update();
    return 0;
}


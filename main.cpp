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
#include "src/ScannerReader.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    ScannerReader *scanner = new ScannerReader();
    
    StorageManagement *s = new StorageManagement();
    s->setScanner(scanner);
    s->watchScanner();
    return 0;
}


/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LabelDriver.cpp
 * Author: nick
 * 
 * Created on January 6, 2017, 11:19 AM
 */

#include "LabelDriver.h"
#include <sstream>
#include <iostream>
#include <fstream>

LabelDriver::LabelDriver() {
    
}

LabelDriver::~LabelDriver() {
}

void LabelDriver::printLabel(string text) {
    ofstream labelFile;
    labelFile.open ("/home/pi/label.txt", ios::out || ios::trunc);
    labelFile << text;
    labelFile.close();
    system("lp -o orientation-requested=4 -o fit-to-page -d stickers /home/pi/label.txt -o cpi=4 lpi=1 -o media=Custom.50x85    mm -o job-sheets=none");
}

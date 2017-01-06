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

LabelDriver::LabelDriver() {
    
}

LabelDriver::~LabelDriver() {
}

void LabelDriver::printLabel(string text) {
    stringstream ss;
    ss << "echo " << text << " > /home/pi/label.txt";
    system(ss.str().c_str());
    system("lp -o orientation-requested=4 -o fit-to-page -d stickers /home/pi/label.txt -o cpi=6 lpi=2 -o media=Custom.28x89mm -o job-sheets=none");
}

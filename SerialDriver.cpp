/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SerialDriver.cpp
 * Author: nick
 * 
 * Created on November 2, 2016, 2:27 PM
 */

#include "SerialDriver.h"
#include <iostream>
SerialDriver::SerialDriver() {
    wiringPiSetup();
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
}

SerialDriver::~SerialDriver() {
}

void SerialDriver::sendShiftData(shiftData shift) {
    std::cout << shift.reg2 << endl;
    std::cout << shift.reg1 <<endl;
    shiftOut(dataPin, clockPin, MSBFIRST, shift.reg2);
    shiftOut(dataPin, clockPin, MSBFIRST, shift.reg1);
}

void SerialDriver::setLatch(bool state) {
    digitalWrite(latchPin, state);
}

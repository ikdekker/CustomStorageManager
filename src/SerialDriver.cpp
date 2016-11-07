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
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, OUTPUT);
    pinMode(latchPin, OUTPUT);
}

SerialDriver::~SerialDriver() {
}

void SerialDriver::sendShiftData(unsigned char data) {
	cout << (int) data;
        shiftOut(dataPin, clockPin, MSBFIRST, data);
//        printf("test\r\n%02X\r\n", data);
}

void SerialDriver::setLatch(bool state) {
    digitalWrite(latchPin, state);
}

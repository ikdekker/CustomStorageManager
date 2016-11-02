/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SerialDriver.h
 * Author: nick
 *
 * Created on November 2, 2016, 2:27 PM
 */

#ifndef SERIALDRIVER_H
#define SERIALDRIVER_H

#include "src/MatrixControl.h"
#include <wiringPi.h>
#include <wiringShift.h>
#include <map>

class SerialDriver {
public:
    SerialDriver();
    virtual ~SerialDriver();
    void sendShiftData(shiftData);
    void setLatch(bool state);
private:
    int latchPin = 2;
    int clockPin= 14;
    int dataPin = 0;
};

#endif /* SERIALDRIVER_H */


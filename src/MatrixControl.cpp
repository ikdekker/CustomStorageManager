
/* 
 * File:   MatrixControl.cpp
 * Author: Gebruiker
 * 
 * Created on October 26, 2016, 4:52 PM
 */

#include "MatrixControl.h"
#include "SerialDriver.h"
#include <algorithm>
#include <iostream>

using namespace std;

MatrixControl::~MatrixControl() {
}

MatrixControl::MatrixControl(ModuleServer* serv) : server(serv) {
    //create Control with server holding modules

    list<ModuleEntity*> mods = server->getModules();
    for (auto it = mods.begin(); it != mods.end(); it++) {
        shiftData *s = new shiftData();
        s->id = (*it)->getId();
        s->reg1 = 0;
        s->reg2 = 0;
        moduleData.push_back(s);
    }
}

Point MatrixControl::indexToLocation(int index, int modId) {
    Point pt;
    ModuleEntity* ent = server->getModuleById(modId);
    if (ent->checkDisabled(index)) {
        pt.x = -1;
        pt.y = -1;
        return pt;
    }
    int cols = ent->getCols();
    int rows = ent->getRows();

    pt.y = floor(index / cols);
    pt.x = index - (pt.y * rows);
    cout << pt.x;

    return pt;
}

void MatrixControl::ledOn(int index, int modId) {
    // call indextolocation
    //update the shiftData registers
    Point pt = {1,1};//indexToLocation(index, modId);
    list<ModuleEntity*> mods = server->getModules();
    for (auto it = mods.begin(); it != mods.end(); it++) {
        shiftData *s = new shiftData();
        s->id = (*it)->getId();
        s->reg1 = getFirstByte(pt.x, pt.y);
        s->reg2 = getSecondByte(pt.x, pt.y);
        moduleData.push_back(s);
    }
}

void MatrixControl::reset() {
    //reset all the leds to off-mode
}

void MatrixControl::runThrough(int modId) {
    //loops through all leds to test 
    
}

void MatrixControl::update() {
    //send shiftData to SPI
    SerialDriver sd;
    sd.setLatch(false);
    for (auto it = moduleData.begin(); it != moduleData.end(); it++) {
        sd.sendShiftData(*(*it));
    }
    sd.setLatch(true);
}

unsigned char MatrixControl::getFirstByte(int xPin, int yPin) {
    unsigned char pinVal;
    if (xPin <= 7) {
        auto finder = pinMapping.find(xPin);
        pinVal = finder->second;
    }
    if (yPin <= 7) {
        auto finder = pinMapping.find(yPin);
        pinVal |= finder->second;
    }
    return pinVal;
}

unsigned char MatrixControl::getSecondByte(int xPin, int yPin) {
    unsigned char pinVal;
    if (xPin > 8) {
        auto finder = pinMapping.find(xPin);
        pinVal = finder->second;
    }
    if (yPin > 8) {
        auto finder = pinMapping.find(yPin);
        pinVal |= finder->second;
    }
    return pinVal;
}

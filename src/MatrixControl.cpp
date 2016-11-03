
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
#include <math.h>

using namespace std;

MatrixControl::~MatrixControl() {
}

MatrixControl::MatrixControl(ModuleServer* serv) : server(serv) {
    //create Control with server holding modules

    wiringPiSetup();
    list<ModuleEntity*> mods = server->getModules();
    for (auto it = mods.begin(); it != mods.end(); it++) {
        shiftData *s = new shiftData();
        s->id = (*it)->getId();
        //        cout << s->id << "id";
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
    //    cout << pt.x;

    return pt;
}

void MatrixControl::ledOn(int index, int modId) {
    // call indextolocation
    //update the shiftData registers
    Point pt = {1, 1}; //indexToLocation(index, modId);
    list<ModuleEntity*> mods = server->getModules();

    shiftData *s;
    for (auto moduleIterator = moduleData.begin(); moduleIterator != moduleData.end(); moduleIterator++) {
        if ((*moduleIterator)->id == modId) {
            s = (*moduleIterator);
        }
    }
    if (s == nullptr) {
        printf("module doesnt exist");
        return;
    }
    setByte(pt.x, s);
    setByte(pt.y + 10, s);
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
        unsigned char firstByte = (*it)->reg1;
        unsigned char secondByte = (*it)->reg2;
        for (int flipBit = 11; flipBit <= 16; flipBit++) {
            auto findMappedPin = pinMapping.find(flipBit);
            int mapPin = findMappedPin->second;
            //flip pin to be Y
                            printf("%d\n",mapPin);
                            printf("noflip %02x\n",firstByte);
                            printf("noflip %02x\n",secondByte);
            if (mapPin <= 8) {
                unsigned char flipByte = pow(2, mapPin - 1);
                firstByte ^= flipByte;
            } else {
                unsigned char flipByte = pow(2, mapPin - 9);
                secondByte ^= flipByte;
            }
                            printf("flip %02x\n",firstByte);
                            printf("flip %02x\n",secondByte);
        }
        sd.sendShiftData(firstByte);
        sd.sendShiftData(secondByte);
    }
    sd.setLatch(true);
}

void MatrixControl::setByte(int pin, shiftData *sData) {
    auto finder = pinMapping.find(pin);
    int actualPin = finder->second;
    int shift = 1;
    if (actualPin > 8) {
        shift = 9;
    }
    unsigned char pinVal = (unsigned char) pow(2, actualPin - shift);

    if (actualPin < 8) {
        sData->reg1 |= pinVal;
    } else {
        sData->reg2 |= pinVal;
        //        printf("\n%02x 128 act%dpin shift = %d \n", pinVal, actualPin, shift);
    }
}


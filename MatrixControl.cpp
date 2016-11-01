
/* 
 * File:   MatrixControl.cpp
 * Author: Gebruiker
 * 
 * Created on October 26, 2016, 4:52 PM
 */

#include "MatrixControl.h"

MatrixControl::~MatrixControl() {
}

MatrixControl::MatrixControl(ModuleServer* server) {
    //create Control with server holding modules
}

Point MatrixControl::indexToLocation() {
    //retrieve point from index
}

void MatrixControl::ledOn(int) {
    // call indextolocation
    //update the shiftData registers
}

void MatrixControl::reset() {
    //reset all the leds to off-mode
}

void MatrixControl::runThrough(int) {
    //loops through all leds to test 
}

void MatrixControl::update() {
    //send shiftData to SPI

}

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   LabelDriver.h
 * Author: nick
 *
 * Created on January 6, 2017, 11:19 AM
 */

#ifndef LABELDRIVER_H
#define LABELDRIVER_H

#include <string>
using namespace std;

class LabelDriver {
public:
    LabelDriver();
    virtual ~LabelDriver();
    void printLabel(string text);
private:

};

#endif /* LABELDRIVER_H */


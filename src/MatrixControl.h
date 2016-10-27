/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MatrixControl.h
 * Author: nick
 *
 * Created on October 27, 2016, 2:08 PM
 */

#ifndef MATRIXCONTROL_H
#define MATRIXCONTROL_H

#include "ModuleServer.h"
#include "CppUTest/CommandLineTestRunner.h"

class MatrixControl {
public:
    MatrixControl(ModuleServer *mServer);
    virtual ~MatrixControl();
    virtual ModuleServer* getServer() { return server; };
private:
    ModuleServer *server;
};

#endif /* MATRIXCONTROL_H */


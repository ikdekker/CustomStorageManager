/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ScannerReader.h
 * Author: nick
 *
 * Created on November 10, 2016, 1:49 PM
 */

#ifndef SCANNERREADER_H
#define SCANNERREADER_H


#include <iostream>
#include "hidapi.h"
#include <thread>
#include <map>
#include <string>
#include <sstream>

using namespace std;

class ScannerReader {
public:
	ScannerReader();
	void start();
	void stop();
	bool isRunning();
	bool hasRead();
	string getLastRead();
        virtual ~ScannerReader();
private:
	thread watcherThread;
	bool running;
	bool read;
	void scanRead();
	string lastRead;
	hid_device *scannerHandle;
};

#endif /* SCANNERREADER_H */


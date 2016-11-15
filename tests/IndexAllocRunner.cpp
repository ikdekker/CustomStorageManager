/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MatrixControlRunner.cpp
 * Author: nick
 *
 * Created on October 27, 2016, 2:55 PM
 */

#include "CppUTest/CommandLineTestRunner.h"
#include <vector>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    std::vector<const char*> args(argv, argv + argc); // Insert all arguments
    args.push_back("-v"); // Set verbose mode
    args.push_back("-r"); // Set verbose mode
    args.push_back("-c"); // Set color output (OPTIONAL)
    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    return RUN_ALL_TESTS(argc, &args[0]);
}


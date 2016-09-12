/* 
 * File:   IEB_Configure.cpp
 * Author: pjd
 *
 * Created on October 14, 2015, 3:47 PM
 */

#include <unistd.h>
#include <string.h>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include "SerialPort/SerialPort.hxx"

using namespace std;

SerialPort* sp = 0;

#define NORMAL "\033[0m"
#define BOLD   "\033[1m"
#define ITALIC "\033[4m"
#define CLEAR  "\033[2J\033[H"



int main(int argc, char** argv) {

  if ((argc < 2) | strcmp(argv[1], "-h") == 0) {
    showHelp(basename(argv[0]));
    exit(0);
  }

  sp = new SerialPort(argv[1]);
  sp->open();
  while (1) {
	echo sp->read();
  }
  if (argc > 2) {
    if (strcmp(argv[2],"?")==0) {
      cout << endl << BOLD"Available commands:"NORMAL << endl;
      say("?");
      sleep(1);
      exit(0);
    }
    else 
      cout << endl << BOLD"Applying settings:"NORMAL << endl;
  }

  sleep(1);
  showSettings();
  sleep(1);
  sp->close();

  return 0;
}


/* 
 * File:   SerialPort.cxx
 * Author: pjd
 * 
 * Created on October 14, 2015, 3:54 PM
 */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <termios.h>
#include <iostream>
#include "SerialPort.hxx"

extern "C" {

    void* readerThreadStarter(void* arg) {
        ((SerialPort*) arg)->reader();
    }
}

SerialPort::SerialPort(string device, int baudrate, int databits, int stopbits, char parity)
: _device(device), _baudrate(baudrate), _databits(databits), _stopbits(stopbits), _parity(parity) {
    _fd = 0;
}

SerialPort::SerialPort(const SerialPort& orig) {
}

SerialPort::~SerialPort() {
}

int SerialPort::open() {

    _fd = ::open(_device.c_str(), O_RDWR);

    if (_fd == -1) {
        cerr << "Could not open " << _device << " " << strerror(errno) << endl;
        exit(0);
    }
    if (isatty(_fd) == 0) {
        cerr << "This is not a tty! " << strerror(errno) << endl;
        exit(0);
    }
    struct termios term;
    if (tcgetattr(_fd, &term) == -1) {
        cerr << "Could not retrieve serial port settings." << endl;
        exit(0);
    }

    term.c_iflag = 0;
    term.c_oflag = 0;
    term.c_lflag = 0;
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0; // 
    term.c_cflag = CREAD | CLOCAL;
    term.c_cflag &= ~CRTSCTS;
    term.c_cflag &= ~CSIZE;

    if (tcsetattr(_fd, TCSANOW, &term) == -1) {
        cerr << "Could not make port settings." << endl;
        exit(0);
    }

    _continue = true;
    pthread_create(&_rThr, 0, readerThreadStarter, (void*) this);

    return 0;
}

int SerialPort::close() {
    _continue = false;
    pthread_cancel(_rThr);
    pthread_join(_rThr, 0);
}

int SerialPort::write(char* buffer, size_t n) {

    ::write(_fd, buffer, n);

    return n;
}

int SerialPort::read(char* buffer, size_t n) {

    return ::read(_fd, buffer, n);
}

void SerialPort::reader() {

    const int MAX_RBUF_SIZE = 1024;
    char rBuf[MAX_RBUF_SIZE];

    while (_continue) {
        int s = read(rBuf, MAX_RBUF_SIZE);
        for (int c = 0; c < s; c++) 
            cout << rBuf[c];
    }
}


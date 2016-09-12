/* 
 * File:   SerialPort.hxx
 * Author: pjd
 *
 * Created on October 14, 2015, 3:54 PM
 */

#ifndef SERIALPORT_HXX
#define	SERIALPORT_HXX

#include <pthread.h>
#include <string>

using namespace std;

class SerialPort {
public:
    SerialPort(string device, int baudrate=9600, int databits=8, int stopbits=1, char parity='N');
    SerialPort(const SerialPort& orig);
    virtual ~SerialPort();
    
    int open();
    int close();
    
    int write(char* buffer, size_t n);
    int read(char* buffer, size_t n);
    void reader();
    
private:
    string _device;
    int _baudrate;
    int _databits;
    int _stopbits;
    char _parity;
    
    int _fd;
    bool _continue;
    pthread_t _rThr;
    
};

#endif	/* SERIALPORT_HXX */


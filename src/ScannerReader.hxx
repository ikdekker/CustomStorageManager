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
private:
	thread watcherThread;
	bool running;
	bool read;
	void scanRead();
	string lastRead;
	hid_device *scannerHandle;
};

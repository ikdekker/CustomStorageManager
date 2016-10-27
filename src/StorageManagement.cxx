#include "StorageManagement.h"
#include <iostream>
#include <string>

using namespace std;
using json = nlohmann::json;


StorageManagement::StorageManagement() {
         ConfigFactory* config = new ConfigFactory();
                modules = new ModuleServer();
        json j = config->getModuleJson();

        for (auto it = j.begin(); it != j.end(); ++it) {
                modules->addModule(config->getModule(*it));
        }

//cout <<	modules->getModuleById(0)->getRows();


}

void StorageManagement::setScanner(ScannerReader* sr) {
    scanner = sr;
}

void StorageManagement::watchScanner() {
	scanner->start();
        cout << "started watching scanner" << endl;
	string lastCode;
	while (1) {
		if (scanner->isRunning()) {
			if (scanner->hasRead()) {
				lastCode = scanner->getLastRead();
				cout << lastCode << endl;
			}
		}
	}
}

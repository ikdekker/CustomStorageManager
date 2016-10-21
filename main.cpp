/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: nick
 *
 * Created on October 21, 2016, 1:10 PM
 */

#include <cstdlib>
#include "src/StorageManagement.h"
#include "src/ScannerReader.h"
#include "src/ConfigFactory.h"

using namespace std;

/*
 * 
 */

int main() {
		cout << "start1";

        StorageManagement* storage = new StorageManagement();
        ConfigFactory* config = new ConfigFactory();
	ScannerReader* scanReader = new ScannerReader();
	json j = config->getModuleJson();

	for (auto it = j.begin(); it != j.end(); ++it) {
  		storage->addModule(config->parseModuleJson(*it));
	}
	ModuleEntity* mod = storage->getModuleById(1);


	if (mod) {
//		cout << mod->getId();
	}
	scanReader->start();
	string lastCode;
	while (1) {
		if (scanReader->isRunning()) {
			if (scanReader->hasRead()) {
				lastCode = scanReader->getLastRead();
				cout << lastCode << endl;
			}
		}
	}

	return 0;
}


StorageManagement::StorageManagement() {
	cout << "I'm alive!";
}

void StorageManagement::addModule(ModuleEntity* module) {
	modules.push_back(module);
	// vector<int> aids = module->getDisabledRows();
	// for(int i = 0; i < aids.size(); i++ ){
		// cout << aids.at(i) << endl;
	// }
}


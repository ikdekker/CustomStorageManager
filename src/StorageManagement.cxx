#include "StorageManagement.hxx"
#include "ConfigFactory.hxx"
#include "ScannerReader.hxx"
#include <iostream>
#include <string>

using namespace std;
using json = nlohmann::json;

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

ModuleEntity* StorageManagement::getModuleById(int id) {
	for (auto it = modules.begin(); it != modules.end(); it++) {
		if ((*it)->getId() == id) {
			return *it;
		}
	}
	return nullptr;
}

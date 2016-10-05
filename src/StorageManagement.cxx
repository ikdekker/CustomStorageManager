#include "StorageManagement.hxx"
#include "ConfigFactory.hxx"

#include <iostream>

using namespace std;
using json = nlohmann::json;

int main() {
		cout << "start1";

        StorageManagement* storage = new StorageManagement();
        ConfigFactory* config = new ConfigFactory();

	json j = config->getModuleJson();

	for (json::iterator it = j.begin(); it != j.end(); ++it) {
  		storage->addModule(config->parseModuleJson(*it));
	}
	ModuleEntity* mod = storage->getModuleById(1);
	if (mod) {
		cout << mod->getId();
	}
	return 0;
}


StorageManagement::StorageManagement() {

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
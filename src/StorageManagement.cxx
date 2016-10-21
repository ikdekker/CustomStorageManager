#include "StorageManagement.h"
#include "ConfigFactory.h"
#include "ScannerReader.h"
#include <iostream>
#include <string>

using namespace std;
using json = nlohmann::json;


ModuleEntity* StorageManagement::getModuleById(int id) {
	for (auto it = modules.begin(); it != modules.end(); it++) {
		if ((*it)->getId() == id) {
			return *it;
		}
	}
	return nullptr;
}

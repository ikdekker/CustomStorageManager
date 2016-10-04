#include "StorageManagement.hxx"
#include "ConfigFactory.hxx"
#include "ModuleEntity.hxx"

#include <iostream>

using namespace std;
using json = nlohmann::json;

int main() {

        StorageManagement* storage = new StorageManagement();
        ConfigFactory* config = new ConfigFactory();

	json j = config->getModuleJson();

	for (json::iterator it = j.begin(); it != j.end(); ++it) {
  		storage->addModule(config->parseModule(*it));
	}

	return 0;
}


StorageManagement::StorageManagement() {

}


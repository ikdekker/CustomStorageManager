#include "StorageManagement.hxx"
#include "ConfigFactory.hxx"
#include "ModuleEntity.hxx"

#include <iostream>

using namespace std;
using json = nlohmann::json;

int main() {

        StorageManagement* storage = new StorageManagement();
        ConfigFactory* config = new ConfigFactory();
        json conf = config->getModuleJson();
		cout << conf;
		return 0;
}


StorageManagement::StorageManagement() {

}

void StorageManagement::getJson() {
	json j;
	ifstream f("../data/config.json");
        j << f;
	
for (json::iterator it = j.begin(); it != j.end(); ++it) {
  std::cout << *it << '\n';
}
}

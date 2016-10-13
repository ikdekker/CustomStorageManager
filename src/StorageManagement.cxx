#include "StorageManagement.hxx"

#include <iostream>

using namespace std;
using json = nlohmann::json;

int main() {
        StorageManagement* storage = new StorageManagement();
        return 0;
}


StorageManagement::StorageManagement() {
        ConfigFactory* config = new ConfigFactory();
	modules = new ModuleServer();
        json j = config->getModuleJson();

        for (auto it = j.begin(); it != j.end(); ++it) {
                modules->addModule(config->parseModuleJson(*it));
        }
//cout <<	modules->getModuleById(0)->getRows();


}

//void StorageManagement::addModule(ModuleEntity* module) {
//      modules.push_back(module);
        // vector<int> aids = module->getDisabledRows();
        // for(int i = 0; i < aids.size(); i++ ){
                // cout << aids.at(i) << endl;
        // }
//}

//ModuleEntity* StorageManagement::getModuleById(int id) {
//      for (auto it = modules.begin(); it != modules.end(); it++) {
//              if ((*it)->getId() == id) {
//                      return *it;
//              }
//      }
//      return nullptr;
//}






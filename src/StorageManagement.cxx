#include "StorageManagement.h"

#include <iostream>

using namespace std;
using json = nlohmann::json;


StorageManagement::StorageManagement() {
//        ConfigFactory* config = new ConfigFactory();
//		modules = new ModuleServer();
//        json j = config->getModuleJson();
//        for (auto it = j.begin(); it != j.end(); ++it) {
//                modules->addModule(config->getModule(*it));
//        }
        
        //@todo: change into digo_user
        dbAdapter = new DatabaseAdapter("digo_parts_db", "root", "digo_secret");
        ConfigFactory* config = new ConfigFactory();
        modules = new ModuleServer();
        json j = config->getModuleJson();

        for (auto it = j.begin(); it != j.end(); ++it) {
                modules->addModule(config->getModule(*it));
        }
//cout <<	modules->getModuleById(0)->getRows();

}

void StorageManagement::setDbAdapter(DatabaseAdapter* db) {
    dbAdapter = db;
}

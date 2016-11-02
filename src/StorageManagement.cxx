#include "StorageManagement.h"
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;
using json = nlohmann::json;

StorageManagement::StorageManagement() {
    //@todo: change into digo_user
    //        dbAdapter = new DatabaseAdapter("digo_parts_db", "root", "digo_secret");
    ConfigFactory config;
    modules = new ModuleServer();
    json j = config.getModuleJson();

    for (auto it = j.begin(); it != j.end(); ++it) {
        ModuleEntity *mod = config.getModule(*it);
        modules->addModule(mod);
        delete mod;
    }
    //cout <<	modules->getModuleById(0)->getRows();

}

void StorageManagement::setDbAdapter(DatabaseAdapter* db) {
    dbAdapter = db;
}

bool StorageManagement::checkDisabled(int modId, int index) {
    ModuleEntity *mod = modules->getModuleById(modId);
    int cols = mod->getCols();
    
    vector<int> disabled = mod->getDisabledRows();
    
    int row = floor(index / cols);
    row++;
    if (std::find(disabled.begin(), disabled.end(), -1) != disabled.end())
        return false;
    //check if row is disabled by looking in the disabled vector
    if (std::find(disabled.begin(), disabled.end(), row) != disabled.end())
        return true;
    return false;
}

int StorageManagement::findFreeSpot(int modId) {
    cout << modId;
    vector<int> *res = dbAdapter->getEntriesByModule(modId);
    ModuleEntity *mod = modules->getModuleById(modId);

    int nextSpot = 0;
    int spotTotal = mod->getCols() * mod->getRows();
    spotTotal--;
    for (; nextSpot < spotTotal; nextSpot++) {
        //check if spot has been taken, if so skip.
        if (std::find(res->begin(), res->end(), nextSpot) != res->end())
            continue;

        //check if row is disabled, if not, return the open spot
        if (checkDisabled(modId, nextSpot) == false) {
            delete res;
            return nextSpot;
        }

    }

    delete res;
    return -1;
}

void StorageManagement::setModuleServer(ModuleServer* mServer) {
    modules = mServer;
}

StorageManagement::~StorageManagement() {
    delete modules;
    delete dbAdapter;
}

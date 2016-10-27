#include "ModuleServer.h"

void ModuleServer::addModule(ModuleEntity* module) {
        modules.push_back(module);
        // vector<int> aids = module->getDisabledRows();
        // for(int i = 0; i < aids.size(); i++ ){
                // cout << aids.at(i) << endl;
        // }
}

ModuleEntity* ModuleServer::getModuleById(int id) {
        for (auto it = modules.begin(); it != modules.end(); it++) {
                if ((*it)->getId() == id) {
                        return *it;
                }
        }
        return nullptr;
}

bool ModuleServer::removeModuleById(int id) {
//remove
}

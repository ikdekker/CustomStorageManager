#include "ModuleServer.h"
#include <iostream>
void ModuleServer::addModule(ModuleEntity* module) {
        modules.push_back(module);
        moduleAmount++;
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

ModuleServer::~ModuleServer() {
        while(!modules.empty()) delete modules.front(), modules.pop_front();
}

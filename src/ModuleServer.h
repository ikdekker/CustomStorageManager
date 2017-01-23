#include <list>
#include "ModuleEntity.h"

#ifndef MODULESERVER_H

#define MODULESERVER_H

class ModuleServer {
public:
        ModuleServer() { int moduleAmount = 0; };
	void addModule(ModuleEntity*);
	bool removeModuleById(int);
	ModuleEntity* getModuleById(int);
        virtual ~ModuleServer();
        std::list<ModuleEntity*> getModules() {return modules;};
        int getModuleAmount() {return moduleAmount;};
private:
	void removeModule();
        int moduleAmount;
	std::list<ModuleEntity*> modules;
};


#endif




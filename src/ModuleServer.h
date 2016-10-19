#include <list>
#include "ModuleEntity.hxx"

#ifndef MODULESERVER_H

#define MODULESERVER_H

class ModuleServer {
public:
//        ModuleServer();
	void addModule(ModuleEntity*);
	bool removeModuleById(int);
	ModuleEntity* getModuleById(int);
private:
	void removeModule();
	std::list<ModuleEntity*> modules;
};


#endif




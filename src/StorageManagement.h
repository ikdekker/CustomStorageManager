#include "../include/json.hpp"
#include <list>

class ModuleEntity;
using namespace std;

class StorageManagement {
	public:
		StorageManagement();
		void addModule(ModuleEntity*);
		ModuleEntity* getModuleById(int);
	private:
		list<ModuleEntity*> modules;
};


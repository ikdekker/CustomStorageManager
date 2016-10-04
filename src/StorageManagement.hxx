#include "../include/json.hpp"
#include <list>

class StorageManagement {
	public:
		StorageManagement();
		void addModule();
		ModuleEntity* getModule(int);
	private:
		list<ModuleEntity*> mylist;
};


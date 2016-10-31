#include "../include/json.hpp"
#include "ConfigFactory.h"
#include "ModuleServer.h"
#include <list>

using namespace std;

class StorageManagement {
	public:
		StorageManagement();
		findFreeSpot();
		checkDisabled();
	private:
		ModuleServer *modules;
};


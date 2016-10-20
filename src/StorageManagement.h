#include "../include/json.hpp"
#include "ConfigFactory.h"
#include "ModuleServer.h"
#include "DatabaseAdapter.h"
#include <list>

using namespace std;

class StorageManagement {
	public:
		StorageManagement();
	private:
		ModuleServer *modules;
                DatabaseAdapter *dbAdapter;
};


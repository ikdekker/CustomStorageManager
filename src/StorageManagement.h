#include "../include/json.hpp"
#include "ConfigFactory.hxx"
#include "ModuleServer.hxx"
#include <list>

using namespace std;

class StorageManagement {
	public:
		StorageManagement();
	private:
		ModuleServer *modules;
};


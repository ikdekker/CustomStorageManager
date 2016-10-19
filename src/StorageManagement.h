#include "../include/json.hpp"
#include "ConfigFactory.hxx"
#include "ModuleServer.hxx"
#include "MatrixControl.hxx"
#include <list>

using namespace std;

class StorageManagement {
	public:
		StorageManagement();
		void watch();
	private:
		ModuleServer *modules;
		MatrixControl *matrix;
};


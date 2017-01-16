#include "include/json.hpp"
#include "ModuleEntity.h"
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;
using json = nlohmann::json;

#ifndef CONFIGFACTORY_H
#define CONFIGFACTORY_H

struct moduleData {
	int id;
	int rows;
	int cols;
	std::vector<int> disabled; 
};

class ConfigFactory {
public:
	json getModuleJson();
	ModuleEntity* getModule(json);
	moduleData* parseModuleJson(json);
	vector<string> getSkips();
private:
	json configJson;
};

#endif

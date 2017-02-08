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

struct apiCredentials {
	string endpoint;
	string username;
	string password;
	string key;
};

struct dbCredentials {
	string db;
	string name;
	string pass;
};

class ConfigFactory {
public:
	json getModuleJson();
	json getCredentialsJson();
	apiCredentials getAPIConfig();
	dbCredentials getDbConfig();
	ModuleEntity* getModule(json);
	moduleData* parseModuleJson(json);
	vector<string> getSkips();
private:
	json configJson;
	json credentialsJson;
};

#endif

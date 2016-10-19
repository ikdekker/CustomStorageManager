#pragma once
#include "../include/json.hpp"
#include <fstream>
#include <cstdio>
#include "ModuleEntity.hxx"

using namespace std;
using json = nlohmann::json;

class ConfigFactory {
public:
	json getModuleJson();
	ModuleEntity* parseModuleJson(json);
private:
	json configJson;
};

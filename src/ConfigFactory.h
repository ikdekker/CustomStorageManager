#include "../include/json.hpp"
#include "ModuleEntity.hxx"
#include <fstream>
#include <cstdio>

using namespace std;
using json = nlohmann::json;

class ConfigFactory {
public:
	json getModuleJson();
	ModuleEntity* parseModuleJson(json);
private:
	json configJson;
};
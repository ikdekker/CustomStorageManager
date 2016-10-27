#include "../include/json.hpp"
#include <fstream>
#include <cstdio>
#include "ModuleEntity.h"
#include <vector>

using namespace std;
using json = nlohmann::json;

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
	moduleData parseModuleJson(json);
private:
	json configJson;
};
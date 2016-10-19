/*
   _____ __                                    __  ___                            __ 
  / ___// /_____  _________ _____ ____        /  |/  /___  ____ _____ ___  ____  / /_
  \__ \/ __/ __ \/ ___/ __ `/ __ `/ _ \______/ /|_/ / __ \/ __ `/ __ `__ \/ __ \/ __/
 ___/ / /_/ /_/ / /  / /_/ / /_/ /  __/_____/ /  / / / / / /_/ / / / / / / / / / /_  
/____/\__/\____/_/   \__,_/\__, /\___/     /_/  /_/_/ /_/\__, /_/ /_/ /_/_/ /_/\__/  
                          /____/                        /____/                       

		Author: Nick Dekker

		The ConfigFactory Parses Json and returns data which can be used
		to return classes which can be used to manage the system through
		calling functions on these classes.
*/

#include "../include/json.hpp"
#include <fstream>
#include <cstdio>
#include "ModuleEntity.hxx"

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

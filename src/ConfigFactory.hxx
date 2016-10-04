#include "../include/json.hpp"
#include <fstream>
#include <cstdio>
using namespace std;
using json = nlohmann::json;

class ConfigFactory {
public:
	json getModuleJson();
	List getModules();
	void parseJson();
private:
	json moduleJson;
	json configJson;
};
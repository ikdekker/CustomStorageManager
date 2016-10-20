#include "ConfigFactory.h"
#include <stdexcept>
#include <sstream>
#include <vector>

json ConfigFactory::getModuleJson() {
	cout << "Reading config file" << endl;

	ifstream f("../config/modules.json");
	cout << "Reading config file" << endl;
	json moduleJson;
	try {
		moduleJson << f;
	}
	catch(const exception& ex)
	{
		// specific handling for all exceptions extending std::exception
		cerr << "Error occurred: " << ex.what() << endl;
	}
	cout << "git";
	return moduleJson;
}

ModuleEntity* ConfigFactory::getModule(json j) {
	
	moduleData modData = parseModuleJson(j);
	
	ModuleEntity* module = new ModuleEntity(modData.id, modData.cols, modData.rows, modData.disabled);
	cout << "returning " << modData.id;
	return module;
}

moduleData ConfigFactory::parseModuleJson(json j) {
	stringstream ss;
	ss << j["/disableRows"_json_pointer];
	
	int cols = j["/columns"_json_pointer];
	int rows = j["/rows"_json_pointer];
	int id = j["/id"_json_pointer];
	
    std::vector<int> vect;
	
    int i;

	if (ss.peek() == ',' || ss.peek() == ' ' || ss.peek() == '"')
		ss.ignore();
    while (ss >> i)
    {
        vect.push_back(i);

        if (ss.peek() == ',' || ss.peek() == ' ' || ss.peek() == '"')
            ss.ignore();
    }
	
    // for (i=0; i< vect.size(); i++)
        // std::cout << vect.at(i)<<std::endl;
	
	moduleData modData;
	modData.id = id;
	modData.cols = cols;
	modData.rows = rows;
	modData.disabled = vect;
	return modData;
}

#include "ConfigFactory.hxx"
#include <stdexcept>

json ConfigFactory::getModuleJson() {
	cout << "Reading config file" << endl;

	ifstream f("../config/modules.json");
	json moduleJson;
	try {
		moduleJson << f;
	}
	catch(const std::exception& ex)
	{
		// speciffic handling for all exceptions extending std::exception, except
		// std::runtime_error which is handled explicitly
		std::cerr << "Error occurred: " << ex.what() << std::endl;
	}

	return moduleJson;
}

ModuleEntity* ConfigFactory::parseModuleJson(json j) {
	cout << j << "d";
}

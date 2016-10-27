#include "ConfigFactory.h"
#include <stdexcept>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <fstream>
#include <iosfwd>

json ConfigFactory::getModuleJson() {
    cout << "Reading config file" << endl;

    cout << "a";
    ifstream f("config/modules.json");
    json moduleJson;
    try {
        moduleJson << f;
    } catch (const std::exception& ex) {
        // specific handling for all exceptions extending std::exception
        std::cerr << "Error occurred: " << ex.what() << std::endl;
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
    while (ss >> i) {
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

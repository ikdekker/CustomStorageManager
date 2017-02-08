#include "ConfigFactory.h"
#include <stdexcept>
#include <sstream>
#include <vector>

/**
 * Reads module config file in config folder.
 * @return json The moduledata from the file as a json object
 */
json ConfigFactory::getModuleJson() {
    ifstream f("config/modules.json");
    json moduleJson;
    try {
        configJson << f;
    } catch (const exception& ex) {
        // specific handling for all exceptions extending std::exception
        cerr << "Error occurred: " << ex.what() << endl;
    }
    //    cout << moduleJson;

    return configJson["modules"];
}

dbCredentials ConfigFactory::getDbConfig() {
    json credJson = getCredentialsJson();
    dbCredentials dbc;
    return dbc;
}

apiCredentials ConfigFactory::getAPIConfig() {
    json credJson = getCredentialsJson();
    apiCredentials apic;
    apic.endpoint = credJson["ghs"]["endpoint"];
    apic.username = credJson["ghs"]["username"];
    apic.password = credJson["ghs"]["password"];
    apic.key = credJson["ghs"]["key"];
    return apic;
}

json ConfigFactory::getCredentialsJson() {
    ifstream f("config/config.json");
    credentialsJson << f;
    return credentialsJson;
}

/**
 * @param j Data with id, columns, rows and disabled rows
 * @return ModuleEntity* Pointer to the parsed module data object
 */
ModuleEntity* ConfigFactory::getModule(json j) {

    moduleData *modData = parseModuleJson(j);

    ModuleEntity* module = new ModuleEntity(modData);
    //	cout << "returning " << modData->id;
    delete modData;
    return module;
}

/**
 * @param j Json data to be parsed into a module
 * @return moduleData struct with all module data.
 */
moduleData* ConfigFactory::parseModuleJson(json j) {
    stringstream ss;
    ss << j["/disableRows"_json_pointer];

    int cols = j["/columns"_json_pointer];
    int rows = j["/rows"_json_pointer];
    int id = j["/id"_json_pointer];

    if (id < 0) {
        throw std::out_of_range("No valid id");
    }
    if (rows <= 0) {
        throw std::out_of_range("No valid amount of rows");
    }
    if (cols <= 0) {
        throw std::out_of_range("No valid amount of columns");
    }

    std::vector<int> vect;

    int i;

    if (ss.peek() == ',' || ss.peek() == ' ' || ss.peek() == '"')
        ss.ignore();
    while (ss >> i) {
        if (i <= 0) {
            throw std::out_of_range("No valid disabled row number");
        }
        vect.push_back(i);

        if (ss.peek() == ',' || ss.peek() == ' ' || ss.peek() == '"')
            ss.ignore();
    }

    // for (i=0; i< vect.size(); i++)
    // std::cout << vect.at(i)<<std::endl;

    moduleData *modData = new moduleData;
    modData->id = id;
    modData->cols = cols;
    modData->rows = rows;
    modData->disabled = vect;
    //	cout << "returning2 " << modData->id;

    return modData;
}

vector<string> ConfigFactory::getSkips() {
    vector<string> skips;
    string s = configJson["skips"];
    std::istringstream ss(s);
    std::string token;

    while(std::getline(ss, token, ',')) {
        skips.push_back(token);
    }

    return skips;
}

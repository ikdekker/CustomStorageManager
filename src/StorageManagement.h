#include "../include/json.hpp"
#include "ConfigFactory.h"
#include "ModuleServer.h"
#include "ScannerReader.h"
#include <list>

using namespace std;

class StorageManagement {
public:
    StorageManagement();
    void setScanner(ScannerReader*);
    void watchScanner();
private:
    ScannerReader *scanner;
    ModuleServer *modules;
};


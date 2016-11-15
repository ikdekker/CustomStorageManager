#include "StorageManagement.h"
#include "src/DatabaseAdapter.h"
#include "ScannerReader.h"
#include <math.h>
#include <iostream>
#include <algorithm>

using namespace std;
using json = nlohmann::json;

StorageManagement::StorageManagement() {
    //@todo: change into digo_user
    //        dbAdapter = new DatabaseAdapter("digo_parts_db", "root", "digo_secret");
    ConfigFactory config;
    modules = new ModuleServer();
    scanReader = new ScannerReader();
    json j = config.getModuleJson();

    for (auto it = j.begin(); it != j.end(); ++it) {
        ModuleEntity *mod = config.getModule(*it);
        modules->addModule(mod);
    }
    //cout <<	modules->getModuleById(0)->getRows();

}

void StorageManagement::setDbAdapter(DatabaseAdapter* db) {
    dbAdapter = db;
}

int StorageManagement::findFreeSpot(int modId) {
    vector<int> *res = dbAdapter->getEntriesByModule(modId);
    ModuleEntity *mod = modules->getModuleById(modId);

    int nextSpot = 0;
    int spotTotal = mod->getCols() * mod->getRows();
    spotTotal--;
    for (; nextSpot < spotTotal; nextSpot++) {
        //check if spot has been taken, if so skip.
        if (std::find(res->begin(), res->end(), nextSpot) != res->end())
            continue;

        //check if row is disabled, if not, return the open spot
        if (mod->checkDisabled(nextSpot) == false) {
            return nextSpot;
        }

    }
    delete res;
    return 1;
}

void StorageManagement::setModuleServer(ModuleServer* mServer) {
    modules = mServer;
}

StorageManagement::~StorageManagement() {
    delete modules;
    delete dbAdapter;
}

ModuleServer* StorageManagement::getServer() {
    return modules;
}

int StorageManagement::addLicenseEmpty(bool print, int modId) {
    string license;
    cin >> license;
    int free = findFreeSpot(modId);
    int realIndex = dbAdapter->addOrder(free, license, modId);
    if (print) {
        printLicenseLocation(realIndex, license, modId);
    } 
    return 1;
}

void StorageManagement::printLicenseLocation(int index, string license, int modId) {
    productData p;
    Point loc = matrix->indexToLocation(index, modId);
    cout << "De locatie voor onderdelen voor de auto met kenteken " << license;
        printf(" is: rij %d kolom %d\n", loc.y + 1, loc.x + 1);
}

void StorageManagement::setMatrix(MatrixControl* mControl) {
    matrix = mControl;
}

void StorageManagement::run() {
    
	scanReader->start();
	string lastCode;
	int change = 1;
	while (1) {
		if (scanReader->isRunning()) {
			if (scanReader->hasRead()) {
				lastCode = scanReader->getLastRead();
//				cout << lastCode << endl;
                                //todo test for external connection result
                                int modId = 0;
                                int index = dbAdapter->addOrder(findFreeSpot(modId), lastCode, modId);
                                matrix->ledOn(index, modId);
                                change = 1;
				cout << index << endl;
			}
		}
		if (change) {
                matrix->update(); change = 0;
		}
	}
}

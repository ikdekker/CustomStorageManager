#include "StorageManagement.h"
#include "src/DatabaseAdapter.h"
#include "ScannerReader.h"
#include "ExternalGHSConnection.h"
#include <math.h>
#include <iostream>
#include <algorithm>
#include <time.h>

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
    DatabaseAdapter *db = new DatabaseAdapter("digo_parts_db", "digo_user", "such_secret_many_wow");
    dbAdapter = db;
    externalConnection = new ExternalGHSConnection(db);
    //    cout <<	modules->getModuleById(0)->getRows();
    labelDriver = new LabelDriver();
}

void StorageManagement::setDbAdapter(DatabaseAdapter* db) {
    dbAdapter = db;
}

int StorageManagement::findFreeSpot(int modId) {
    vector<int> res = dbAdapter->getEntriesByModule(modId);
    ModuleEntity *mod = modules->getModuleById(modId);

    int nextSpot = 0;
    int spotTotal = mod->getCols() * mod->getRows();
    spotTotal--;
    for (; nextSpot < spotTotal; nextSpot++) {
        //check if spot has been taken, if so skip.
        if (std::find(res.begin(), res.end(), nextSpot) != res.end())
            continue;

        //check if row is disabled, if not, return the open spot
        if (mod->checkDisabled(nextSpot) == false) {
            return nextSpot;
        }

    }
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
    orderData order;
    string license;
    cin >> license;
    order.license = license;
    int free = findFreeSpot(modId);
    int realIndex = dbAdapter->addOrder(free, order, modId);
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
        string printOrder = dbAdapter->doPrint();
        if (printOrder != "0") {
            orderData od = dbAdapter->getOrderData(printOrder);
            if (od.license != "0") {
                labelDriver->printLabel(od.license);
            }
        }
        if (scanReader->isRunning() && scanReader->hasRead()) {
            lastCode = scanReader->getLastRead();
            //cout << lastCode << endl;
            //todo test for external connection result
            int modId = 0;
            int ext = true;
            int index = -1;
            try {
                orderData od = externalConnection->fetchOrderData(lastCode);
                index = dbAdapter->addOrder(findFreeSpot(modId), od, modId);
            } catch (string a) {
                //no order
		cout << a;
                ext = false;
            }

            if (!ext) {
                try {
                    orderData od = dbAdapter->getOrderData(lastCode);
                    index = od.index;
                    modId = od.module;
		    ext = true;
                } catch (string a) {
                    //no order
                }
            }

            matrix->reset();
	    if (ext)
              matrix->ledOn(index, modId);
            change = 1;

            //				cout << index << endl;
        }
//        time_t seconds;
//        seconds = (int) (time(NULL));
//        bool blinker = !!(seconds % 2);
//        if (change || blinker != matrix->getBlink()) {
//            //  if (seconds % 2 == 0) {
//            matrix->setBlink(blinker);
//            //}
//            matrix->update();
//            change = 0;
//        }

    }
}

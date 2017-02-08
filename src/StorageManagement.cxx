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
    apiCredentials apiCred = config.getAPIConfig();
    ExternalGHSConnection *extGHS = new ExternalGHSConnection(db, apiCred.endpoint, apiCred.username, apiCred.password, apiCred.key);
    vector<string> skips = config.getSkips();
    extGHS->setSkips(skips);
    externalConnection = extGHS;
    try {
        externalConnection->fetchOrderData("1");
    } catch (string a) {}
    //    cout <<	modules->getModuleById(0)->getRows();
    labelDriver = new LabelDriver();
}

void StorageManagement::setDbAdapter(DatabaseAdapter* db) {
    dbAdapter = db;
}

int StorageManagement::findFreeSpot(int modId) {
    vector<int> res = dbAdapter->getEntriesByModule(modId);
    ModuleEntity *mod = modules->getModuleById(modId);
    if (mod == nullptr) return -1;
    int nextSpot = 0;
    int spotTotal = mod->getCols() * mod->getRows();
    
    for (; nextSpot < spotTotal; nextSpot++) {
        //check if spot has been taken, if so skip.
        if (std::find(res.begin(), res.end(), nextSpot) != res.end())
            continue;

        //check if row is disabled, if not, return the open spot
        if (mod->checkDisabled(nextSpot) == false) {
            return nextSpot;
        }

    }
    return -1;
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
    int change, count = 0;
    time_t ledStart;
    bool noReset = false, timerActive = false;
    time_t now = (int) time(NULL);
    while (1) {
        //    cout << (scanReader->isRunning() && scanReader->hasRead());
        if (scanReader->isRunning() && scanReader->hasRead()) {
            lastCode = scanReader->getLastRead();
            cout << lastCode << endl;
            //todo test for external connection result
            int modId = 0;
            bool ext = true;
            int index = -1;
            try {
                orderData od = dbAdapter->getOrderData(lastCode, 1);
                index = od.index;
                modId = od.module;
                noReset = true;
                ledStart = (int) time(NULL);
                timerActive = true;
            } catch (string a) {
                //no order                    ext = false;
                ext = false;
                cout << a;
            }

            if (!ext) {
                try {
                    orderData od = externalConnection->fetchOrderData(lastCode);
                    int modAmount = modules->getModuleAmount();
                    int curMod = 0;
                    int newIndex;
                    while (curMod < modAmount) {
                        newIndex = findFreeSpot(curMod);
                        if (newIndex != -1) {
                            modId = curMod;
                            break;
                        }
                        curMod++;
                    }
                    if (newIndex == -1) {
                        dbAdapter->updateMessage("Geen plekken meer over in de stelling.");
                        continue;
                    }
                    index = dbAdapter->addOrder(newIndex, od, modId);
                    cout << od.intId << endl;
                    ext = true;
                } catch (string a) {
                    //no order
                    cout << a;
                }
            }
            matrix->reset();
            if (ext) {
                matrix->ledOn(index, modId);
                change = 1;
            }

            //				cout << index << endl;
        }
        //        time_t seconds;
        //        seconds = (int) (time(NULL));
        //        bool blinker = !!(seconds % 2);
        //        if (change || blinker != matrix->getBlink()) {
        //            //  if (seconds % 2 == 0) {
        //            matrix->setBlink(blinker);
        //            //}
        if (change) {
            matrix->update();
            change = 0;
        }
        //        cout << now % 5;

        now = (int) time(NULL);

        if (now != count) {
            bool busy = dbAdapter->getBusy();
            if ((!busy && !noReset) || (difftime(time(NULL), ledStart) >= 30 && timerActive)) {
                matrix->reset();
                noReset = false;
                change = 1;
                if (timerActive) {
                    dbAdapter->updateCurrent("0");
                    timerActive = false;
                }
            }

            string printOrder = dbAdapter->doPrint();
            if (printOrder != "0") {
                try {
                    cout << "print" << printOrder << endl;
                    orderData od = dbAdapter->getOrderData(printOrder, 0);
                    if (od.license != "0" && od.license != "" && od.intId != od.ref && od.intId != "") {
                        labelDriver->printLabel(od.license);
                    } else {
                        labelDriver->printLabel(od.ref);
		    }
                } catch (string a) {
                    cout << a;
                }
            }
            count = now;
        }

    }
}

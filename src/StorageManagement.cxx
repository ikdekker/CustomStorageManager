#include "StorageManagement.hxx"
#include <unistd.h>
#include <iostream>

using namespace std;
using json = nlohmann::json;

int main() {
        StorageManagement* storage = new StorageManagement();
cout << "starting watch";
	storage->watch();
        return 0;
}


StorageManagement::StorageManagement() {
        ConfigFactory* config = new ConfigFactory();
	modules = new ModuleServer();
        json j = config->getModuleJson();

        for (auto it = j.begin(); it != j.end(); ++it) {
                modules->addModule(config->parseModuleJson(*it));
        }
//cout <<	modules->getModuleById(0)->getRows();

}

void StorageManagement::watch() {
cout <<32 ;
int a = 0;
	while (1) {
//nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
	if (a < 4) {
		matrix->ledOn(a);
	
	} else {
		if (a  == 500)
		break;
	}
		a++;

	}
}

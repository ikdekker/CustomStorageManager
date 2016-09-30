#include "StorageManagement.hxx"
#include <iostream>

using namespace std;
using json = nlohmann::json;

int main() {

        StorageManagement* storage = new StorageManagement();
        storage->getJson();

        return 0;
}


StorageManagement::StorageManagement() {

}

void StorageManagement::getJson() {
	json j;
	ifstream f("../data/config.json");
        j << f;
	
for (json::iterator it = j.begin(); it != j.end(); ++it) {
  std::cout << *it << '\n';
}
}

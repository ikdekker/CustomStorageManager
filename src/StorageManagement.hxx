#include ../include/json.hpp


class StorageManagement {
	public:
		StorageManagement();
		void getJson();
	private:
	
};

int main() {
	
	StorageManagement storage = new StorageManagement();
	
	storage->getJson();
	
	exit 0;
}
#include "include/json.hpp"
#include "ConfigFactory.h"
#include "ModuleServer.h"
#include "DatabaseAdapter.h"
#include <list>

using namespace std;

class StorageManagement {
	public:
		StorageManagement();
		virtual ~StorageManagement();
		int findFreeSpot(int modId);
                void setDbAdapter(DatabaseAdapter* db);
                void setModuleServer(ModuleServer* mServer);
                ModuleServer* getServer();
	private:
		ModuleServer *modules;
                DatabaseAdapter *dbAdapter;
};


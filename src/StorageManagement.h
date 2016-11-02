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
		bool checkDisabled(int modId, int index);
                void setDbAdapter(DatabaseAdapter* db);
                void setModuleServer(ModuleServer* mServer);
	private:
		ModuleServer *modules;
                DatabaseAdapter *dbAdapter;
};


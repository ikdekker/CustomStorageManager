#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include <string>
#include <stdlib.h>
#include <iostream>
//#include <cppconn/resultset.h>
//#include <cppconn/statement.h>
//#include <cppconn/driver.h>
//#include <mysql_connection.h>
#include <vector>

using namespace std;

class DatabaseAdapter {
public:
	DatabaseAdapter(string db, string user, string pass);
        virtual vector<int>* getEntriesByModule(int moduleId){};
	void addEntry(int index, int moduleId, string license, string products);
private:
//	sql::Connection *connection;
};


#endif

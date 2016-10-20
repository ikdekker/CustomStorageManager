#include <string>
#include <stdlib.h>
#include <iostream>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/driver.h>
#include <mysql_connection.h>
#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

using namespace std;

class DatabaseAdapter {
public:
	DatabaseAdapter(string db, string user, string pass);
	void addEntry(int index, int moduleId, string license, string products);
private:
	sql::Connection *connection;
};


#endif

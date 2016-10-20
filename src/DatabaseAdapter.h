#include <string>

#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

class DatabaseAdapter {
public:
	DatabaseAdapter(string, string, string);
	addEntry(moduleId, index, orderId);
private:
	string username;
	string password;
	string database;
	MYSQL *connection, mysql;
}


#endif

#include <string>
#ifndef DATABASEADAPTER_H
#define DATABASEADATER_H

class DatabaseAdapter {
public:
	DatabaseAdapter(string,string,string);
	
private:
	MYSQL *connection, mysql;
};

#endif

#ifndef DATABASEADAPTER_H
#define DATABASEADAPTER_H

#include <string>
#include <stdlib.h>
#include <iostream>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/driver.h>
#include <cppconn/prepared_statement.h>
#include <mysql_connection.h>
#include <vector>

using namespace std;

struct productData {
	int productId = -1;
	string productName = "";
	int amount = 0;
	
	bool empty() {
		if (productId == -1 && productName.empty() || amount == 0)
			return true;	
		return false;		
	}
};

class DatabaseAdapter {
public:
	DatabaseAdapter(string db, string user, string pass);
        virtual vector<int>* getEntriesByModule(int moduleId);;
	int addOrder(int index, string werkorder, int moduleId);
private:
	sql::Connection *connection;
};


#endif

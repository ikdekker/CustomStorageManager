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
	string productId = "-1";
	string productName = "";
	int amount = 0;
	
	bool empty();        
    friend ostream& operator<<(ostream& os, const productData& pd) {
        os << "productId: " << pd.productId << endl;
        os << "productName: " << pd.productName << endl;
        os << "amount: " << pd.amount << endl;
       
        return os;
    };
};

struct orderData {
    string extId;
    string intId;
    string license;
    string mechanic;
    string deliveryRoute;
    string ref;
    int status;
    int module;
    int index;
    vector<productData*> products;

    productData* getProductById(string id) {
        for (auto it = products.begin(); it != products.end(); it++) {
            if ((*it)->productId == id)
                return *it;
        }
        return nullptr;
    }
};

class DatabaseAdapter {
public:
	DatabaseAdapter(string db, string user, string pass);
        virtual vector<int> getEntriesByModule(int moduleId);
	int addOrder(int index, orderData werkorder, int moduleId);
	void removeOrder(string werkorder);
	string fetchOrderByExternalId(string id);
	string fetchOrderByInternalId(string id);
	void addExternalOrder(string extId, string intId, string data);
	vector<string> fetchOrders(string column);
        orderData getOrderData(string order);
        void execQueryOnly(string query);
        sql::ResultSet* exec(sql::Statement*, string query);
        void execPrepStmtOnly(sql::PreparedStatement*);
private:
	sql::Connection *connection;
};


#endif

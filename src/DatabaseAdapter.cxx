#include "DatabaseAdapter.h"
#include <iostream>
DatabaseAdapter::DatabaseAdapter(string db, string user, string pass) {
    sql::Driver *driver;
    sql::Statement *stmt;
    sql::ResultSet *res;
    driver = get_driver_instance();
    connection = driver->connect("localhost",user,pass);
    connection->setSchema(db);
    stmt = connection->createStatement();
    res = stmt->executeQuery("Select * from `parts_allocation`");
    
    while (res->next()) {
        cout << "\t" << res->getString("module_id"); 
        cout << "\t" << res->getString("index"); 
        cout << "\t" << res->getString("license_plate");
        cout << "\t" << res->getString("products") << endl; 
    }
}

void DatabaseAdapter::addEntry(int index, int moduleId, string license, string products) {

}

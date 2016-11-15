#include "src/DatabaseAdapter.h"
#include <iostream>

DatabaseAdapter::DatabaseAdapter(string db, string user, string pass) {
    sql::Driver *driver;
    sql::Statement *stmt;
    sql::ResultSet *res;
    driver = get_driver_instance();
    connection = driver->connect("localhost", user, pass);
    connection->setSchema(db);
    stmt = connection->createStatement();
    res = stmt->executeQuery("Select * from `order_indexing`");

    while (res->next()) {
//        cout << "\t" << res->getString("module_id");
//        cout << "\t" << res->getString("index");
//        cout << "\t" << res->getString("license_plate");
//        cout << "\t" << res->getString("products") << endl;
    }
}

int DatabaseAdapter::addOrder(int index, string werkorder, int modId) {
    sql::Driver *driver;
    sql::Statement *stmt;
    sql::ResultSet *res;
    sql::PreparedStatement *pstmt;
    driver = get_driver_instance();
    stmt = connection->createStatement();
    string products;
    res = stmt->executeQuery("Select * from `order_indexing` where werkorder='" + werkorder + "'");
 
    if (!res->next()) {
        cout << "Nieuwe locatie voor " << werkorder << endl;
        //create new entry in DB
        //bind query
        //        bind newIndex + module + license + productData as json;
        pstmt = connection->prepareStatement("INSERT INTO order_indexing(`index`,`module_id`,`werkorder`) VALUES (?,?,?)");
        pstmt->setInt(1, index);
        pstmt->setInt(2, modId);
        pstmt->setString(3, werkorder);
        pstmt->execute();
    } else {
        res->previous();
//        if (!product.empty()) {
//            pstmt = connection->prepareStatement("UPDATE part_allocation SET products=? WHERE werkorder=?");
//            pstmt->setString(1, products);
//            pstmt->setString(2,werkorder);
//            pstmt->execute();
//            //update old query
//            //    update products where license = ..
//        }
        while (res->next()) {
            index = res->getInt("index");
        }
    }
    return index;
}

vector<int>* DatabaseAdapter::getEntriesByModule(int moduleId) {
    vector<int>* entries = new vector<int>;

    sql::Driver *driver;
    sql::Statement *stmt;
    sql::ResultSet *res;
    driver = get_driver_instance();
    stmt = connection->createStatement();
    string products;

    res = stmt->executeQuery("select * from `order_indexing` where module_id=0");


    while (res->next()) {
        entries->push_back(res->getInt("index"));
    }

    return entries;
}

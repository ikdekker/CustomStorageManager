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
    res = stmt->executeQuery("Select * from `part_allocation`");

    while (res->next()) {
//        cout << "\t" << res->getString("module_id");
//        cout << "\t" << res->getString("index");
//        cout << "\t" << res->getString("license_plate");
//        cout << "\t" << res->getString("products") << endl;
    }
}

int DatabaseAdapter::addProduct(int index, string license, productData product, int modId) {
    sql::Driver *driver;
    sql::Statement *stmt;
    sql::ResultSet *res;
    sql::PreparedStatement *pstmt;
    driver = get_driver_instance();
    stmt = connection->createStatement();
    string products;
    res = stmt->executeQuery("Select * from `part_allocation` where license_plate='" + license + "'");
 
    if (!res->next()) {
        cout << "Nieuwe locatie voor " << license << endl;
        //create new entry in DB
        //bind query
        //        bind newIndex + module + license + productData as json;
        pstmt = connection->prepareStatement("INSERT INTO part_allocation(`index`,`module_id`,`license_plate`,`products`) VALUES (?,?,?,?)");
        pstmt->setInt(1, index);
        pstmt->setInt(2, modId);
        pstmt->setString(3, license);
        pstmt->setString(4, products);
        pstmt->execute();
    } else {
        res->previous();
        if (!product.empty()) {
            pstmt = connection->prepareStatement("UPDATE part_allocation SET products=? WHERE license=?");
            pstmt->setString(1, products);
            pstmt->setString(2,license);
            pstmt->execute();
            //update old query
            //    update products where license = ..
        }
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

    res = stmt->executeQuery("select * from `part_allocation` where module_id = 0");


    while (res->next()) {
        entries->push_back(res->getInt("index"));
    }

    return entries;
}

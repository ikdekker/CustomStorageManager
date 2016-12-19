#include "src/DatabaseAdapter.h"
#include <iostream>
#include "ExternalConnector.h"

DatabaseAdapter::DatabaseAdapter(string db, string user, string pass) {
    sql::Driver *driver;
    sql::Statement *stmt;
    sql::ResultSet *res;
    driver = get_driver_instance();
    connection = driver->connect("localhost", user, pass);
    connection->setSchema(db);
}

int DatabaseAdapter::addOrder(int index, orderData werkorder, int modId) {
    sql::Statement *stmt;
    sql::ResultSet *res;
    sql::PreparedStatement *pstmt;
    stmt = connection->createStatement();
    string products;
    sql::mysql::MySQL_Connection * mysql_conn = dynamic_cast<sql::mysql::MySQL_Connection*> (connection);
    if (werkorder.intId == "") {
        werkorder.intId == werkorder.ref;
    }
    string escapedInternal = mysql_conn->escapeString(werkorder.intId);
    string escapedExternal = mysql_conn->escapeString(werkorder.extId);
    res = stmt->executeQuery("Select * from `order_indexing` where werkorder='" + escapedInternal + "'");

    if (!res->next()) {
        cout << "Nieuwe locatie voor " << werkorder.intId << endl;
        //create new entry in DB
        //bind query
        //        bind newIndex + module + license + productData as json;
        pstmt = connection->prepareStatement("INSERT INTO order_indexing(`index`,`module_id`,`werkorder`) VALUES (?,?,?)");
        pstmt->setInt(1, index);
        pstmt->setInt(2, modId);
        pstmt->setString(3, werkorder.intId);
        pstmt->execute();
        pstmt = connection->prepareStatement("INSERT INTO order_info(`werkorder`, `license`) VALUES (?,?)");
        pstmt->setString(1, werkorder.intId);
        pstmt->setString(2, werkorder.license);
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


    pstmt = connection->prepareStatement("INSERT INTO part_allocation(`werkorder`, `product_id`, `amount`, `description`, `sorted`, `external_id`) VALUES (?,?,?,?,?,?)");

    for (auto it = werkorder.products.begin(); it != werkorder.products.end(); it++) {
        string escapedProductId = mysql_conn->escapeString((*it)->productId);
        res = stmt->executeQuery("Select * from `part_allocation` where werkorder='" + escapedInternal + "' and external_id='" + escapedExternal + "' and product_id='" + escapedProductId + "'");
        if (res->next()) {
            continue;
        }

        pstmt->setString(1, werkorder.intId);
        pstmt->setString(2, (*it)->productId);
        pstmt->setInt(3, (*it)->amount);
        pstmt->setString(4, (*it)->productName);
        pstmt->setInt(5, 0);
        pstmt->setString(6, werkorder.extId);
        pstmt->executeUpdate();
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

string DatabaseAdapter::fetchOrderByExternalId(string id) {
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = connection->createStatement();
    res = stmt->executeQuery("Select data from `ghs_orders` where ghs_id=\"" + id + "\"");
    while (res->next()) {
        return res->getString("data");
    }
    return "";
}

string DatabaseAdapter::fetchOrderByInternalId(string id) {
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = connection->createStatement();
    res = stmt->executeQuery("Select data from `ghs_orders` where digo_id=\"" + id + "\"");
    while (res->next()) {
        return res->getString("data");
    }
    return "";
}

vector<string> DatabaseAdapter::fetchOrders(string column) {
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = connection->createStatement();
    sql::mysql::MySQL_Connection * mysql_conn = dynamic_cast<sql::mysql::MySQL_Connection*> (connection);
    string cleanCol = mysql_conn->escapeString(column);
    res = stmt->executeQuery("Select " + cleanCol + " from `ghs_orders`");
    vector<string> orderIds;
    while (res->next()) {
        orderIds.push_back(res->getString(cleanCol));
    }
    return orderIds;
}

void DatabaseAdapter::addExternalOrder(string extId, string intId, string data) {
    sql::Driver *driver;
    sql::Statement *stmt;
    sql::ResultSet *res;
    sql::PreparedStatement *pstmt;

    pstmt = connection->prepareStatement("INSERT INTO ghs_orders(`ghs_id`,`digo_id`,`data`) VALUES (?,?,?)");
    pstmt->setString(1, extId);
    pstmt->setString(2, intId);
    pstmt->setString(3, data);
    pstmt->execute();

}

/**
 * Retrieve the location of an existing order
 * @param order
 * @return 
 */
orderData DatabaseAdapter::getOrderData(string order) {
    sql::Statement *stmt;
    sql::ResultSet *res;

    stmt = connection->createStatement();
    string products;
    sql::mysql::MySQL_Connection * mysql_conn = dynamic_cast<sql::mysql::MySQL_Connection*> (connection);

    string escapedInternal = mysql_conn->escapeString(order);
    res = stmt->executeQuery("Select * from `order_indexing` where werkorder='" + escapedInternal + "'");
    int index, module;
    string intId;
    if (!res->rowsCount()) {
        throw "Did not find the order " + order; 
    }
    while (res->next()) {
        index = res->getInt("index");
        module = res->getInt("module_id");
    }
    
    orderData od;
    od.index = index;
    od.module = module;
    od.intId = order;
    
    return od;
}

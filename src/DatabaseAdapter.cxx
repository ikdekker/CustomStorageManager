#include "src/DatabaseAdapter.h"
#include <iostream>
#include "ExternalConnector.h"

/**
 * Construct the database with the local mysql host.
 * @param db Name of the database
 * @param user Username to access the database
 * @param pass Password to access the database
 */
DatabaseAdapter::DatabaseAdapter(string db, string user, string pass) {
    sql::Driver *driver;
    sql::Statement *stmt;
    sql::ResultSet *res;
    driver = get_driver_instance();
    connection = driver->connect("localhost", user, pass);
    connection->setSchema(db);
}

/**
 * Add a new order to the database if it doesn't exist.
 * @param index
 * @param werkorder A struct with all the orderdata in it,
 * uses the license, external id, internal id, products to enter into the 
 * part_allocation table
 * @param modId Which module to add the order to (only affects database).
 * @return int Index of the added/retrieved order.
 */
int DatabaseAdapter::addOrder(int index, orderData werkorder, int modId) {
    sql::Statement *stmt;
    sql::ResultSet *res;
    sql::PreparedStatement *pstmt;
    stmt = connection->createStatement();

    sql::mysql::MySQL_Connection * mysql_conn = dynamic_cast<sql::mysql::MySQL_Connection*> (connection);
    if (werkorder.intId == "") {
        werkorder.intId == werkorder.ref;
    }
    string escapedInternal = mysql_conn->escapeString(werkorder.intId);
    string escapedExternal = mysql_conn->escapeString(werkorder.extId);
    string query = "Select * from `order_indexing` where werkorder='" + escapedInternal + "'";
    res = exec(stmt, query);

    if (!res->rowsCount()) {
        cout << "Nieuwe locatie voor " << werkorder.intId << endl;
        //create new entry in DB
        //bind query
        //        bind newIndex + module + license + productData as json;
        pstmt = connection->prepareStatement("INSERT INTO order_indexing(`index`,`module_id`,`werkorder`) VALUES (?,?,?)");
        pstmt->setInt(1, index);
        pstmt->setInt(2, modId);
        pstmt->setString(3, werkorder.intId);
        execPrepStmtOnly(pstmt);
        pstmt = connection->prepareStatement("INSERT INTO order_info(`werkorder`, `license`) VALUES (?,?)");
        pstmt->setString(1, werkorder.intId);
        pstmt->setString(2, werkorder.license);
        execPrepStmtOnly(pstmt);
    } else {
        while (res->next()) {
            index = res->getInt("index");
        }
    }


    pstmt = connection->prepareStatement("INSERT INTO part_allocation(`werkorder`, `product_id`, `amount`, `description`, `sorted`, `external_id`) VALUES (?,?,?,?,?,?)");

    for (auto it = werkorder.products.begin(); it != werkorder.products.end(); it++) {
        string escapedProductId = mysql_conn->escapeString((*it)->productId);
        res = exec(stmt, "Select * from `part_allocation` where werkorder='" + escapedInternal + "' and external_id='" + escapedExternal + "' and product_id='" + escapedProductId + "'");
        if (res->next()) {
            continue;
        }

        pstmt->setString(1, werkorder.intId);
        pstmt->setString(2, (*it)->productId);
        pstmt->setInt(3, (*it)->amount);
        pstmt->setString(4, (*it)->productName);
        pstmt->setInt(5, 0);
        pstmt->setString(6, werkorder.extId);
        try {
            pstmt->executeUpdate();
        } catch (...) {
            cout << "Something went wrong here." << endl << "File: " << __FILE__ << endl << "Function: " << __FUNCTION__ << endl << "Line: " << __LINE__ << endl;
        }
    }

    return index;
}

/**
 * Purge an order and it's related rows from the database
 * @param werkorder
 */
void DatabaseAdapter::removeOrder(string werkorder) {
    execQueryOnly("DELETE IGNORE from ghs_orders where digo_id='" + werkorder + "'");
    execQueryOnly("DELETE IGNORE from order_info where werkorder='" + werkorder + "'");
    execQueryOnly("DELETE IGNORE from part_allocation where werkorder='" + werkorder + "'");
    execQueryOnly("DELETE IGNORE from order_indexing where werkorder='" + werkorder + "'");
}

/**
 * Execute a query and catch the error to prevent a program crash.
 * @param query The query to be executed.
 */
void DatabaseAdapter::execQueryOnly(string query) {
    sql::Statement *stmt;
    stmt = connection->createStatement();
    try {
        stmt->executeQuery(query);
    } catch (...) {
        cout << "Something went wrong here." << endl << "File: " << __FILE__ << endl << "Function: " << __FUNCTION__ << endl << "Line: " << __LINE__ << endl;
    }
}

/**
 * Takes a prepared statement and handles the execute function.
 * @param pstmt The pointer to a prepared statement
 */
void DatabaseAdapter::execPrepStmtOnly(sql::PreparedStatement* pstmt) {
    try {
        pstmt->execute();
    } catch (...) {
        cout << "Something went wrong here." << endl << "File: " << __FILE__ << endl << "Function: " << __FUNCTION__ << endl << "Line: " << __LINE__ << endl;
    }
}
/**
 * @param stmt
 * @param query
 * @return sql::ResultSet* Pointer to the result set which can be iterated
 * through.
 * Can be checked on valid result on the validity of the rowsCount function.
 */
sql::ResultSet* DatabaseAdapter::exec(sql::Statement* stmt, string query) {
    try {
        return stmt->executeQuery(query);
    } catch (...) {
        cout << "Something went wrong here." << endl << "File: " << __FILE__ << endl << "Function: " << __FUNCTION__ << endl << "Line: " << __LINE__ << endl;
    }
}

/**
 * Retrieve entries by module id from th order_indexing table.
 * Returns a list containing all the used indexes on the requested module.
 * @param moduleId Id of the module to check the entries on
 * @return vector<int> A list with occupied indexes
 */
vector<int> DatabaseAdapter::getEntriesByModule(int moduleId) {
    vector<int> entries;

    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = connection->createStatement();
    stringstream ss;
    ss << "select * from `order_indexing` where module_id='";
    ss << moduleId;
    ss << "'";
        res = exec(stmt, ss.str());

    while (res->next()) {
        entries.push_back(res->getInt("index"));
    }

    return entries;
}

/**
 * Gets the order data from ghs_orders tables through an external id.
 * @param id The external id to check
 * @return string Json data which was fetched previously by the API connection.
 * Empty when the row was not found.
 */
string DatabaseAdapter::fetchOrderByExternalId(string id) {
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = connection->createStatement();
    res = exec(stmt, "Select data from `ghs_orders` where ghs_id=\"" + id + "\"");

    while (res->next()) {
        return res->getString("data");
    }
    return "";
}

/**
 * Gets the order data from ghs_orders tables through an internal id.
 * @param id The internal id to check
 * @return string Json data which was fetched previously by the API connection.
 * Empty when the row was not found.
 */
string DatabaseAdapter::fetchOrderByInternalId(string id) {
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = connection->createStatement();
    res = exec(stmt, "Select data from `ghs_orders` where digo_id=\"" + id + "\"");

    while (res->next()) {
        return res->getString("data");
    }
    return "";
}

/**
 * Get a list of all the order ids in the ghs_orders table
 * @param column This table has multiple columns which can be used to fetch an 
 * orderlist. "digo_id" for the internal id list, "ghs_id" for the external one
 * @return vector<string> A list containing all the ids existing in the column.
 */
vector<string> DatabaseAdapter::fetchOrders(string column) {
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = connection->createStatement();
    sql::mysql::MySQL_Connection * mysql_conn = dynamic_cast<sql::mysql::MySQL_Connection*> (connection);
    string cleanCol = mysql_conn->escapeString(column);
    res = exec(stmt, "Select " + cleanCol + " from `ghs_orders`");

    vector<string> orderIds;
    while (res->next()) {
        orderIds.push_back(res->getString(cleanCol));
    }
    return orderIds;
}

/**
 * Add an entry to the ghs_orders table.
 * @param extId external id
 * @param intId internal id
 * @param data json data as string.
 */
void DatabaseAdapter::addExternalOrder(string extId, string intId, string data) {
    sql::PreparedStatement *pstmt;

    pstmt = connection->prepareStatement("INSERT INTO ghs_orders(`ghs_id`,`digo_id`,`data`) VALUES (?,?,?)");
    pstmt->setString(1, extId);
    pstmt->setString(2, intId);
    pstmt->setString(3, data);
    execPrepStmtOnly(pstmt);
}

/**
 * Retrieve the location of an existing order
 * @param order
 * @return orderData Struct with the index, module and order id as data
 */
orderData DatabaseAdapter::getOrderData(string order) {
    sql::Statement *stmt;
    sql::ResultSet *resOrderIndexing;
    sql::ResultSet *resOrderInfo;

    stmt = connection->createStatement();
    string products;
    sql::mysql::MySQL_Connection * mysql_conn = dynamic_cast<sql::mysql::MySQL_Connection*> (connection);

    string escapedInternal = mysql_conn->escapeString(order);
    exec(stmt, "Update system_status set orderid='" + escapedInternal + "' where placeholder=0");
    resOrderIndexing = exec(stmt, "Select * from `order_indexing` where werkorder='" + escapedInternal + "'");
    resOrderInfo = exec(stmt, "Select * from `order_info` where werkorder='" + escapedInternal + "'");
    
    int index, module;
    string intId;
    if (!resOrderIndexing->rowsCount()) {
        throw "Did not find the order " + order;
    }
    while (resOrderIndexing->next()) {
        index = resOrderIndexing->getInt("index");
        module = resOrderIndexing->getInt("module_id");
    }

    orderData od;
    if (resOrderInfo->rowsCount()) {
        od.license = resOrderInfo->getString("license");
        od.status = resOrderInfo->getInt("status");
        od.mechanic = resOrderInfo->getString("mechanic");
    }
    od.index = index;
    od.module = module;
    od.intId = order;

    return od;
}

string DatabaseAdapter::doPrint() {
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = connection->createStatement();
    string query = "Select working from `system_status` where placeholder=0";
    res = exec(stmt, query);
    string licenseId = "0";
    bool done = false;
    while (res->next()) {
        licenseId = res->getString("working");
        done = true;
    }
    if (done)
        execQueryOnly("Update system_status set working='0' where placeholder=0");
    return licenseId;
}

bool DatabaseAdapter::getBusy() {
    sql::Statement *stmt;
    sql::ResultSet *res;
    stmt = connection->createStatement();
    string query = "Select orderid from `system_status` where placeholder=0";
    res = exec(stmt, query);
    
    while (res->next()) {
        string orderId = res->getString("orderid");
        if (orderId != "0") {
            return true;
        } else {
            return false;
        }
    }
    return false;
}

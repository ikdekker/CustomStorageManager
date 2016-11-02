#include "ModuleEntity.h"
#include "ConfigFactory.h"
#include <iostream>
#include <stdexcept>

ModuleEntity::ModuleEntity(moduleData *mData) : ModuleEntity(mData->id, mData->cols, mData->rows, mData->disabled) {
//    id = mData->id;
//    rows = mData->rows;
//    cols = mData->cols;
//    disabledRows = mData->disabled;
}

ModuleEntity::ModuleEntity(int id, int x, int y, vector<int> disabled) {
    for (auto it = disabled.begin(); it != disabled.end(); ++it) {
        if (*it > y || *it <= 0 ) {
            throw std::out_of_range("Invalid disabled row");
        }
    }
    ModuleEntity::id = id;
    rows = y;
    cols = x;
    disabledRows = disabled;
}

int ModuleEntity::getRows() const {
    return rows;
}

int ModuleEntity::getCols() const {
    return cols;
}

int ModuleEntity::getId() const {
    return id;
}

vector<int> ModuleEntity::getDisabledRows() const {
    return disabledRows;
}
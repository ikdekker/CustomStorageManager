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

bool ModuleEntity::checkDisabled(int index) const {
    int cols = this->getCols();
    
    vector<int> disabled = this->getDisabledRows();
    int row = floor(index / cols);
    row++;
    if (disabled.empty()) {
        return false;
    }
    //check if row is disabled by looking in the disabled vector
    if (std::find(disabled.begin(), disabled.end(), row) != disabled.end())
        return true;
    return false;
}

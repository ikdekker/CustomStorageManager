#include "ModuleEntity.h"
#include <iostream>

ModuleEntity::ModuleEntity(int id, int x, int y, vector<int> disabled) {
	ModuleEntity::id = id;
	rows = y;
	cols = x;
	disabledRows = disabled;
}

int ModuleEntity::getRows() const{
	return rows;
}

int ModuleEntity::getCols() const{
	return cols;
}

int ModuleEntity::getId() const{
	return id;
}

vector<int> ModuleEntity::getDisabledRows() const{
	return disabledRows;
}

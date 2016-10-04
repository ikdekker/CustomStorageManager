#include "ModuleEntity.hxx"

ModuleEntity::ModuleEntity(int x, int y, int* disabled) {
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
int* ModuleEntity::getDisabledRows() const{
	return disabledRows;
}
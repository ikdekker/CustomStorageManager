#include <vector>

class ConfigFactory;
struct moduleData;
using namespace std;

#ifndef MODULEENTITY_H
#define MODULEENTITY_H

class ModuleEntity {
public:
	ModuleEntity(moduleData* mData);
	ModuleEntity(int id,int x, int y, vector<int> disabled);
	int getId() const;
	int getRows() const;
	int getCols() const;
	vector<int> getDisabledRows() const;
private:
	int id;
	int rows;
	int cols;
	vector<int> disabledRows;
};

#endif

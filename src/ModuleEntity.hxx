#include <vector>
using namespace std;

class ModuleEntity {
public:
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

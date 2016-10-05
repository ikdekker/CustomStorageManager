
class ModuleEntity {
public:
	ModuleEntity(int x, int y, int* disabled);
	int getRows() const;
	int getCols() const;
	int* getDisabledRows() const;
private:
	int rows;
	int cols;
	int* disabledRows;
};

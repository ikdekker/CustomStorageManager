#include <iostream>
#include <map>

class LedControl {
public:
	LedControl();
	void reset();
	bool turnOn();
	MatrixControl* getMatrix();
private:
	MatrixControl *matrix;
};

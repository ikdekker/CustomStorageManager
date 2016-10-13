#include "ModuleServer.hxx"

#ifndef MATRIXCONTROL_H
#define MATRIXCONTROL_H

struct Point
{
    int x, y;
};

class MatrixControl {
public:
	MatrixControl(ModuleServer *server);
	void ledOn(int);
	void runThrough(int);
	void reset();
	void update();
private:
	Point indexToLocation();
	ModuleServer *modules;
};

#endif

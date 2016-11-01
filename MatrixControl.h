
/* 
 * File:   MatrixControl.h
 * Author: Gebruiker
 *
 * Created on October 26, 2016, 4:52 PM
 */

#ifndef MATRIXCONTROL_H
#define MATRIXCONTROL_H

#include <vector>

#include "src/ModuleEntity.h"

struct Point {
    int x, y;
};

struct shiftData {
    unsigned char reg1, reg2;
};

class MatrixControl {
public:
    MatrixControl(ModuleServer *server);
    void ledOn(int);
    void runThrough(int);
    void reset();
    void update();
    virtual ~MatrixControl();
private:
    Point indexToLocation();
    ModuleServer *modules;
    std::vector<int, shiftData>;
};

#endif /* MATRIXCONTROL_H */


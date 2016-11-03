
/* 
 * File:   MatrixControl.h
 * Author: Gebruiker
 *
 * Created on October 26, 2016, 4:52 PM
 */

#ifndef MATRIXCONTROL_H
#define MATRIXCONTROL_H

#include <vector>
#include <map>
#include "src/ModuleEntity.h"
#include "src/ModuleServer.h"
using namespace std;

struct Point {
    int x, y;
};

struct shiftData {
    int id;
    unsigned char reg1, reg2;
};

class MatrixControl {
public:
    MatrixControl(ModuleServer* server);
    void ledOn(int, int);
    void runThrough(int);
    void reset();
    void update();
    virtual ~MatrixControl();
    ModuleServer* getServer() {return server;};
    Point indexToLocation(int index, int modId);
private:
    ModuleServer* server;
    vector<shiftData*> moduleData;
    unsigned char getFirstByte(int,int);
    unsigned char getSecondByte(int,int);
    void setByte(int, shiftData*);
    map<int,int> pinMapping {{8,1},{3,2},{16,3},{5,4},{9,5},{15,6},{10,7},{13,8},{4,9},{11,10},{12,11},{7,12},{14,13},{6,14},{2,15},{1,16}};
};

#endif /* MATRIXCONTROL_H */


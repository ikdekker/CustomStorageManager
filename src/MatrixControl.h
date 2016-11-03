
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
    map<int,int> pinMapping {{7,0},{2,1},{15,2},{4,3},{8,4},{14,5},{9,6},{12,7},{3,8},{10,9},{11,10},{6,11},{13,12},{5,13},{1,14},{0,15}};
};

#endif /* MATRIXCONTROL_H */


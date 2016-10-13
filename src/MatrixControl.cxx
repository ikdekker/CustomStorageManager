#include "MatrixControl.hxx"
#include <iostream>

MatrixControl::MatrixControl(ModuleServer *server) : modules(server) {}

void MatrixControl::ledOn(int index) {
	std::cout << "fictinally turned on " << index;
}
Point MatrixControl::indexToLocation() {}

void MatrixControl::update() {

}

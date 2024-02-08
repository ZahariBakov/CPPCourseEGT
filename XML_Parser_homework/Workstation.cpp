#include "Workstation.h"

Workstation::Workstation(int building, int floor, int desk) {
	setBuilding(building);
	setFloor(floor);
	setDesk(desk);
}

Workstation::~Workstation() {}

void Workstation::setBuilding(int bulding) {
	this->_building = bulding;
}

void Workstation::setFloor(int floor) {
	this->_floor = floor;
}

void Workstation::setDesk(int desk) {
	this->_desk = desk;
}

void Workstation::WorkstationDisplayInfo() const {
	std::cout << "Building: " << getBuilding() << " Floor: " << getFloor() << " Desk: " << getDesk() << std::endl;
}

int Workstation::getBuilding() const {
	return this->_building;
}

int Workstation::getFloor() const {
	return this->_floor;
}

int Workstation::getDesk() const {
	return this->_desk;
}

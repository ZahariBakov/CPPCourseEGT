#pragma once

#include <iostream>

class Workstation {
public:
	Workstation(int building, int floor, int desk);
	~Workstation();

	void setBuilding(int bulding);
	void setFloor(int floor);
	void setDesk(int desk);

	void WorkstationDisplayInfo() const;

private:
	int _building;
	int _floor;
	int _desk;

	int getBuilding() const;
	int getFloor() const;
	int getDesk() const;
};

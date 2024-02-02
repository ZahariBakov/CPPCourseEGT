#pragma once

#include "BaseCar.h"

class SlowCar : public BaseCar {

public:
	SlowCar(std::string);

	void assignRoad(Road*) override;

	bool hasFinished() override;

	void tick(double) override;

	~SlowCar() override {}

private:
	std::string name;
	Road* road;
	double meters;
};

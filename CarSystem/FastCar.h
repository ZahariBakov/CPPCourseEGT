#pragma once

#include "BaseCar.h"

class FastCar : public BaseCar {

public:
	FastCar(std::string);

	void assignRoad(Road*) override;

	bool hasFinished() override;

	void tick(double) override;

	~FastCar() override {}

private:
	std::string name;
	Road* road;
	double meters;
};

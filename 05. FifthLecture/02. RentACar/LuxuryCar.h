#pragma once

#include "Car.h"

class LuxuryCar : public Car {

public:

	LuxuryCar(std::string make, std::string model, std::string type, std::string color,
		std::string vin, std::string plate, double fuelConsumption,
		int taxPerDay=100);

	double calculatePrice() override;

private:

};

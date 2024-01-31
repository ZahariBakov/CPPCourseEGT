#pragma once

#include "Car.h"

class FamilyCar : public Car {

public:

	FamilyCar(std::string make, std::string model, std::string type, std::string color,
		std::string vin, std::string plate, double fuelConsumption,
		int taxPerDay=50);

	double calculatePrice() override;

private:

};

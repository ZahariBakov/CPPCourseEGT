#pragma once

#include "Package.h"

class TwoDayPackage : public Package {
public:
	TwoDayPackage(double, double, Address, Address);

	double calculateCost();
	void print();

private:

};

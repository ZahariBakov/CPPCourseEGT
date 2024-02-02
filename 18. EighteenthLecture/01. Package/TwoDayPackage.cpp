#include "TwoDayPackage.h"

#include <iomanip>

TwoDayPackage::TwoDayPackage(double basePrice, double weight, Address sender, Address recipient)
	: Package(basePrice, weight, sender, recipient) {}

double TwoDayPackage::calculateCost() {
	return getBasePrice() * getWeight();
}

void TwoDayPackage::print() {
	std::cout << "Two Day Package: \n";
	Package::print();

	double result = calculateCost();
	std::cout << "Price: " << std::fixed << std::setprecision(2) << result << "lv." << std::endl;
}

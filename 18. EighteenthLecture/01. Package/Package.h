#pragma once

#include "Address.h"

class Package {
public:
	Package(double, double, Address, Address);

	void setBasePrice(double);
	void setWeight(double);

	double getBasePrice();
	double getWeight();

	virtual double calculateCost();
	void print();

private:
	Address _senderAddress;
	Address _recipientAddress;
	double _basePrice;
	double _weight;
};

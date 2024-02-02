#include "NonAlcoholic.h"

NonAlcoholic::NonAlcoholic(std::string name, double price, int quantity, std::string type, double liters, double cityTax)
						   : Drinks(name, price, quantity, type) {
	setLiters(liters);
	setCityTax(cityTax);
}

void NonAlcoholic::setLiters(double l) {
	if (l <= 0) {
		std::cout << "Liters must be positive number, is set to 0.5" << std::endl;
		l = 0.5;
	}

	this->_liters = l;
}

void NonAlcoholic::setCityTax(double cityTax) {
	if (cityTax < 0) {
		std::cout << "City tax must be positive number, is set to 0" << std::endl;
		cityTax = 0;
	}

	this->_cityTax = cityTax;
}

double NonAlcoholic::getLiters() const {
	return this->_liters;
}

double NonAlcoholic::getCityTax() const {
	return this->_cityTax;
}

void NonAlcoholic::print() {
	Drinks::print();
	std::cout << "Liters " << this->getLiters() << ", total price is: " << this->calculatePrice() << std::endl;
}

double NonAlcoholic::calculatePrice() {
	return this->getQuantity() * (this->getPrice() + this->getCityTax());
}

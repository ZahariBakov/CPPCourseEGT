#include "Drinks.h"

Drinks::Drinks(std::string name, double price, int quantity, std::string type) {
	setName(name);
	setPrice(price);
	setQuantity(quantity);
	setType(type);
}

void Drinks::setName(std::string name) {
	if (name.length() < 3) {
		std::cout << "Name must be more than two symbols. Name is set to 'default'." << std::endl;
		name = "default";
	}

	this->_name = name;
}

void Drinks::setPrice(double price) {
	if (price <= 0) {
		std::cout << "Price must be positive number, bigger from 0. Price is set to 2.00" << std::endl;
		price = 2.00;
	}

	this->_price = price;
}

void Drinks::setQuantity(int num) {
	if (num <= 0) {
		std::cout << "Quntity must be positive number, bigger from 0. Quantity is set to 1" << std::endl;
		num = 1;
	}

	this->_quantity = num;
}

void Drinks::setType(std::string type) {
	if (type.length() < 3) {
		std::cout << "Type must be more than two symbols. Name is set to 'water'." << std::endl;
		type = "water";
	}

	this->_type = type;
}

std::string Drinks::getName() const {
	return this->_name;
}

double Drinks::getPrice() const {
	return this->_price;
}

int Drinks::getQuantity() const {
	return this->_quantity;
}

std::string Drinks::getType() const {
	return this->_type;
}

void Drinks::print() {
	std::cout << "Current drink is: " << this->getType() << ", " << this->getName() << ", " << this->getQuantity() << ", "
		<< this->getPrice() << std::endl;
}

double Drinks::calculatePrice() {
	return 0.0;
}

#include "Package.h"

Package::Package(double basePrice, double weight, Address sender, Address recipient) 
	: _senderAddress(sender), _recipientAddress(recipient) {
	setBasePrice(basePrice);
	setWeight(weight);
}

void Package::setBasePrice(double basePrice) {
	this->_basePrice = basePrice;
}

void Package::setWeight(double weight) {
	this->_weight = weight;
}

double Package::getBasePrice() {
	return this->_basePrice;
}

double Package::getWeight() {
	return this->_weight;
}

double Package::calculateCost() {
	return getBasePrice() * getWeight();
}

void Package::print() {
	std::cout << "Sender: \n";
	this->_senderAddress.print();

	std::cout << "Recepient: \n";
	this->_recipientAddress.print();
}

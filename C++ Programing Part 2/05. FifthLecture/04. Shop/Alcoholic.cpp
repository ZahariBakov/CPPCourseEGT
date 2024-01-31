#include "Alcoholic.h"

Alcoholic::Alcoholic(std::string name, double price, int quantity, std::string type, double volume, int tax) 
				    : Drinks(name, price, quantity, type) {
	setVolume(volume);
	setTax(tax);
}

void Alcoholic::setVolume(double vol) {
	if (vol <= 0) {
		std::cout << "This is alcoholic drink. Volume must be positive. Volume i set to 5.00" << std::endl;
		vol = 5.0;
	}

	this->_volume = vol;
}

void Alcoholic::setTax(int tax) {
	if (tax < 0) {
		std::cout << "Tax must be positive number. Tax is se to 2." << std::endl;
		tax = 2;
	}

	this->_tax = tax;
}

double Alcoholic::getVolume() const {
	return this->_volume;
}

int Alcoholic::getTax() const {
	return this->_tax;
}

void Alcoholic::print() {
	std::cout << "Current drink is: " << this->getType() << ", " << this->getName() << ", " << this->getVolume()<< ", \n" 
		<< " you want " << this->getQuantity() << ", price for one is: " << this->getPrice() << " Total price is: " << this->calculatePrice() << std::endl;
}

double Alcoholic::calculatePrice() {
	return this->getQuantity() * this->getPrice() * this->getTax();
}

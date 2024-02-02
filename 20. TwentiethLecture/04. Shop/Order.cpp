#include "Order.h"

int Order::number = 0;

Order::Order(std::vector<Drinks*> drinks, std::string date) : _drinks(drinks) {
	setDate(date);
	setTotalPrice(0);

	number++;
	setNumber(number);
}

void Order::setDate(std::string date) {
	this->_date = date;
}

void Order::setNumber(int) {
	this->_number = number;
}

void Order::setTotalPrice(double total) {
	this->_totalPrice = total;
}

double Order::calculateTotalPrice() {
	double total = 0.0;
	for (size_t i = 0; i < this->_drinks.size(); ++i) {
		total += _drinks[i]->calculatePrice();
	}

	return total;
}

int Order::getNumber() const {
	return this->_number;
}

std::string Order::getDate() const {
	return this->_date;
}

double Order::getTotalPrice() const {
	return this->_totalPrice;
}

std::vector<Drinks*> Order::getDrinks() const {
	return this->_drinks;
}

void Order::printOrder() {
	std::cout << "Your order number is: " << this->getNumber() << ", total price is: " << this->calculateTotalPrice() << "lv." << std::endl;;
}

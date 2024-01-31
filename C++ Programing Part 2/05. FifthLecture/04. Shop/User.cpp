#include "User.h"

User::User(std::string name, std::vector<Order*> orders) : _orders(orders) {
	setUsername(name);
}

void User::setUsername(std::string name) {
	this->_username = name;
}

std::string User::getUsername() {
	return this->_username;
}

std::vector<Order*> User::getOrders() {
	return this->_orders;
}

void User::printBill() {
	std::cout << "Client: " << this->getUsername() << std::endl;
	std::cout << "Orders: " << std::endl;

	for (size_t i = 0; i < _orders.size(); ++i) {
		_orders[i]->printOrder();
	}
}

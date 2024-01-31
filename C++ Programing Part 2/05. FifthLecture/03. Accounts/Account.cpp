#include "Account.h"

Account::Account(double money) {
	setMoney(money);
}

void Account::setMoney(double money) {
	if (money < 0) {
		std::cout << "Money need to be positive number. You money is set to 0. " << std::endl;
		money = 0;
	}
	
	this->_money = money;
}

double Account::getMoney() const {
	return this->_money;
}

double Account::debit(double num) {
	if (num < 0) {
		std::cout << "The withdrawal amount must be a positive number." << std::endl;
		num = 0;
	}

	if (num > this->getBalance()) {
		std::cout << "You don't have enough funds in your account." << std::endl;
		num = 0;
	}

	return this->_money -= num;
}

double Account::credit(double num) {
	if (num < 0) {
		std::cout << "The withdrawal amount must be a positive number." << std::endl;
		num = 0;
	}

	return this->_money += num;
}

double Account::getBalance() const {

	return this->getMoney();
}

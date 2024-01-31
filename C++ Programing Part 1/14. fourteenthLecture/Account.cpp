#include "Account.h"

#include <iostream>

Account::Account(double balance) {
	if (balance >= 0) {
		this->balance = balance;
	}
	else {
		this->balance = 0;
		std::cerr << "Invalid initial balance" << std::endl;
	}
}

void Account::credit(double amount) {
	this->balance += amount;
}

void Account::debit(double amount) {
	if (amount <= balance) {
		this->balance -= amount;
	}
	else {
		std::cout << "Debit amount exceeded account balance." << std::endl;
	}
}

double Account::getBalance() {
	return this->balance;
}

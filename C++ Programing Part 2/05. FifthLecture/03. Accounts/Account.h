#pragma once

#include <iostream>

class Account {

public:

	Account(double);

	void setMoney(double);

	double getMoney() const;

	virtual double debit(double);
	virtual double credit(double);
	virtual double getBalance() const;

private:

	double _money;
};

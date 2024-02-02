#pragma once

#include "Account.h"

class SavingAccount : public Account {

public:

	SavingAccount(double);

	double debit(double);
	double credit(double);
	double getBalance() const;
	double calculateInterest();

private:

};

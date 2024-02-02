#pragma once

#include "Order.h"
#include "User.h"

class Shop {

public:

	Shop(std::vector<User*>);

	void soldDrinks();
	void bestClient();
	void searchByDrinks(std::string);
	void searchByDrinksAndMoney(std::string, double);

private:

	std::vector<User*> _users;
};

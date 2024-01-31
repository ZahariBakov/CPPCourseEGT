#pragma once

#include "Alcoholic.h"
#include "NonAlcoholic.h"

#include <vector>

class Order {

public:

	static int number;

	Order(std::vector<Drinks*>, std::string);

	void   setNumber(int);
	void   setDate(std::string);
	void   setTotalPrice(double);

	int                  getNumber() const;
	std::string          getDate() const;
	double               getTotalPrice() const;
	std::vector<Drinks*> getDrinks() const;

	double calculateTotalPrice();
	void   printOrder();

private:

	int                  _number;
	std::vector<Drinks*> _drinks;
	std::string          _date;
	double               _totalPrice;
};

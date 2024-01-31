#pragma once

#include "Drinks.h"

class NonAlcoholic : public Drinks {

public:

	NonAlcoholic(std::string, double, int, std::string, double, double);

	void setLiters(double);
	void setCityTax(double);

	double    getLiters() const;
	double    getCityTax() const;

	void   print();
	double calculatePrice();

private:

	double _liters;
	double _cityTax;
};

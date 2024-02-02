#pragma once

#include <iostream>
#include <string>

class Drinks {

public:

	Drinks(std::string, double, int, std::string);

	void setName(std::string);
	void setPrice(double);
	void setQuantity(int);
	void setType(std::string);

	std::string getName() const;
	double      getPrice() const;
	int         getQuantity() const;
	std::string getType() const;

	virtual void   print();
	virtual double calculatePrice();

private:

	std::string _name;
	double      _price;
	int         _quantity;
	std::string _type;
};

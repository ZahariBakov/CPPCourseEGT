#pragma once

#include <iostream>
#include <string>

class Car {

public:

	Car(std::string, std::string, std::string, std::string, std::string, std::string, double, int = 0);

	void setMake(std::string);
	void setModel(std::string);
	void setType(std::string);
	void setColor(std::string);
	void setVin(std::string);
	void setPlate(std::string);
	void setFuelConsum(double);
	void setDayTax(int);

	std::string getMake();
	std::string getModel();
	std::string getType();
	std::string getColor();
	std::string getVin();
	std::string getPlate();
	double      getFuelConsum() const;
	int         getDayTax() const;

	virtual double calculatePrice();

private:

	std::string _make;
	std::string _model;
	std::string _type;
	std::string _color;
	std::string _vin;
	std::string _plate;
	double      _fuelConsumption;
	int         _taxPerDay;
};

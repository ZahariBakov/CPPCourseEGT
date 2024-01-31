#include "Car.h"

Car::Car(std::string make, std::string model, std::string type, std::string color, std::string vin, std::string plate, 
	double fuel, int dayTax) {
	setMake(make);
	setModel(model);
	setType(type);
	setColor(color);
	setVin(vin);
	setPlate(plate);
	setFuelConsum(fuel);
	setDayTax(dayTax);
}

void Car::setMake(std::string make) {
	this->_make = make;
}

void Car::setModel(std::string model) {
	this->_model = model;
}

void Car::setType(std::string type) {
	this->_type = type;
}

void Car::setColor(std::string color) {
	this->_color = color;
}

void Car::setVin(std::string vin) {
	this->_vin = vin;
}

void Car::setPlate(std::string plate) {
	this->_plate = plate;
}

void Car::setFuelConsum(double fuel) {
	this->_fuelConsumption = fuel;
}

void Car::setDayTax(int day) {
	this->_taxPerDay = day;
}

std::string Car::getMake() {
	return this->_make;
}

std::string Car::getModel() {
	return this->_model;
}

std::string Car::getType() {
	return this->_type;
}

std::string Car::getColor() {
	return this->_color;
}

std::string Car::getVin() {
	return this->_vin;
}

std::string Car::getPlate() {
	return this->_plate;
}

double Car::getFuelConsum() const {
	return this->_fuelConsumption;
}

int Car::getDayTax() const {
	return this->_taxPerDay;
}

double Car::calculatePrice() {
	std::cout << "Price is: ";
	return 0.0;
}

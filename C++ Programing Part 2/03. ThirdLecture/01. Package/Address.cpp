#include "Address.h"

Address::Address(std::string name, std::string phone, std::string city, std::string street) {
	setName(name);
	setPhone(phone);
	setCity(city);
	setStreet(street);
}

void Address::setName(std::string name) {
	this->_name = name;
}

void Address::setPhone(std::string phone) {
	this->_phoneNumber = phone;
}

void Address::setCity(std::string city) {
	this->_city = city;
}

void Address::setStreet(std::string street) {
	this->_street = street;
}

std::string Address::getName() {
	return this->_name;
}

std::string Address::getPhone() {
	return this->_phoneNumber;
}

std::string Address::getCity() {
	return this->_city;
}

std::string Address::getStreet() {
	return this->_street;
}

void Address::print() {
	std::cout << getName() << " " << getPhone() << " " << getCity() << " " << getStreet() << std::endl;
}

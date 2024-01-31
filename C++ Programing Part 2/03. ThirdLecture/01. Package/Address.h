#pragma once

#include <iostream>
#include <string>

class Address {
public:
	Address(std::string, std::string, std::string, std::string);

	void setName(std::string);
	void setPhone(std::string);
	void setCity(std::string);
	void setStreet(std::string);

	std::string getName();
	std::string getPhone();
	std::string getCity();
	std::string getStreet();

	void print();

private:
	std::string _name;
	std::string _phoneNumber;
	std::string _city;
	std::string _street;
};

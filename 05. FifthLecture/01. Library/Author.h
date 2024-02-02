#pragma once

#include <iostream>
#include <string>

class Author {

public:

	Author(std::string, std::string, std::string);

	void setFirstName(std::string);
	void setLastName(std::string);
	void setNationality(std::string);

	std::string getFirstName();
	std::string getLastName();
	std::string getNationality();

	void print();

private:

	std::string _firstName;
	std::string _lastName;
	std::string _nationality;
};

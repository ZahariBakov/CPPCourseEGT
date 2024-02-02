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

	void print() const;

private:

	std::string firstName;
	std::string lastName;
	std::string nationality;
};


#pragma once

#include <iostream>

#include <string>

class User {
public:

	User(std::string, std::string);

	void setName(std::string);
	void setPass(std::string);

	std::string getName();
	std::string getPass();

private:

	std::string _name;
	std::string _pass;
};

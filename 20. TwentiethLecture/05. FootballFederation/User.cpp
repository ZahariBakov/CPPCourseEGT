#include "User.h"

User::User(std::string name, std::string pass) {
	setName(name);
	setPass(pass);
}

void User::setName(std::string name) {
	this->_name = name;
}

void User::setPass(std::string pass) {
	if (pass.length() > 4 && pass.length() < 20) {
		this->_pass = pass;
	}
	else {
		while (!(pass.length() > 4 && pass.length() < 20)) {
			std::cout << "Invalid password. Enter new one. " << std::endl;
			std::cin >> pass;
		}
	}
}

std::string User::getName() {
	return this->_name;
}

std::string User::getPass() {
	return this->_pass;
}

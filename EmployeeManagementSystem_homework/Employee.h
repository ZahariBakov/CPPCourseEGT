#pragma once

#include <iostream>

class Employee {

public:

	// constructor
	Employee(std::string, int, std::string);

	// setters
	void setName(std::string);
	void setEmployeeID(int);
	void setPosition(std::string);

	// getters
	std::string getName() const;
	int         getEmployeeID() const;
	std::string getPosition() const;

	// function
	void display() const;

private:

	//Employee attributes
	std::string _name;
	int         _employeeID;
	std::string _position;

};

#pragma once

#include <iostream>

#include "Workstation.h"

class Employee {
public:
	Employee(std::string, std::string, int, Workstation*);

	static Employee* parseEmployee(pugi::xml_node);

	friend std::ostream& operator<<(std::ostream& os, const Employee& employee);

private:
	std::string name;
	std::string type;
	int          age;
	Workstation* workstation;
};

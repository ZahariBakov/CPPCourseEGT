#pragma once

#include "Workstation.h"

class Employee {
public:
	Employee(std::string name, std::string type, int age, Workstation& workstation);
	~Employee();

	void setName(std::string name);
	void setType(std::string type);
	void setAge(int age);

	void EmployeeDisplayInfo() const;

private:
	std::string _name;
	std::string _type;
	int			_age;

	std::string getName() const;
	std::string getType() const;
	int         getAge() const;

	Workstation* _workstation;

};

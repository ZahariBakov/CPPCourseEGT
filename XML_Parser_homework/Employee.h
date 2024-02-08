#pragma once

#include <iostream>

class Employee {
public:
	Employee(std::string name, std::string type, int age);
	~Employee();

	void setName(std::string name);
	void setType(std::string type);
	void setAge(int age);

	void displayInfo() const;

private:
	std::string _name;
	std::string _type;
	int			_age;

	std::string getName() const;
	std::string getType() const;
	int         getAge() const;

};

#pragma once

#include <iostream>
#include <string>

class Student {
public:
	Student(const std::string&, int);

	void setName(std::string);
	void setClassNumber(int);

	std::string getName();
	int getClassNumber();

	void printStudentInfo();

private:
	std::string name;
	int classNumber;
};

#include "Student.h"

Student::Student(const std::string &n, int number) : name(n), classNumber(number) {}

void Student::setName(std::string name) {
	this->name = name;
}

void Student::setClassNumber(int classNumber) {
	this->classNumber = classNumber;
}

std::string Student::getName() {
	return this->name;
}

int Student::getClassNumber() {
	return this->classNumber;
}

void Student::printStudentInfo() {
	std::cout << "Student name " << this->name << " and class number " << this->classNumber << std::endl;
}

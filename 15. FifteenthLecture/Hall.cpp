#include <iostream>

#include "Hall.h"

Hall::Hall(std::string hallname, int capacity) {
	setName(hallname);
	setSeats(capacity);
}

Hall::Hall(std::string name, int seats, std::vector<Screening> screeningList)
	: screeningList(screeningList) {
	setName(name);
	setSeats(seats);
}

void Hall::setName(std::string name) {
	this->name = name;
}

void Hall::setSeats(int capacity) {
	this->seats = capacity;
}

void Hall::addScreening(Screening obj) {
	this->screeningList.push_back(obj);
}

void Hall::print() {
	std::cout << "Hall is: " << this->name << " with " << this->seats
		<< "seats" << std::endl;

	for (size_t i = 0; i < this->screeningList.size(); ++i) {
		this->screeningList.at(i).print();
	}

	std::cout << std::endl;
}

std::vector<Screening> Hall::getScreeningList() {
	return this->screeningList;
}

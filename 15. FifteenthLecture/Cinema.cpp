#include <iostream>

#include "Cinema.h"

Cinema::Cinema(std::string name, std::string adress, std::vector<Hall> halls) {
	setName(name);
	setAdress(adress);
	setHallsList(halls);
}

void Cinema::setName(std::string name) {
	this->name = name;
}

void Cinema::setAdress(std::string adress) {
	this->adress = adress;
}

void Cinema::setHallsList(std::vector<Hall> halls) {
	this->hallsList = halls;
}

std::string Cinema::getName() {
	return this->name;
}

std::string Cinema::getAdress() {
	return this->adress;
}

std::vector<Hall> Cinema::getHallsList() {
	return this->hallsList;
}

void Cinema::addHall(Hall hall) {
	this->hallsList.push_back(hall);
}

void Cinema::print() {
	std::cout << "Cinema name " << this->name << " addres " << this->getAdress() << "\n";

	for (size_t i = 0; i < hallsList.size(); ++i) {
		this->hallsList.at(i).print();
	}

	std::cout << std::endl;
}

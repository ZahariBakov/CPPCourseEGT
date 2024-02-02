#include <iostream>

#include "Screening.h"

Screening::Screening(std::string name, int tickets) {
	setMovieName(name);
	setSoldTickets(tickets);
}

void Screening::setMovieName(std::string name) {
	if (name.length() > 5) {
		this->movieName = name;
	}
	else {
		this->movieName = "";
		std::cerr << "Movie name too short." << std::endl;
	}
}

void Screening::setSoldTickets(int tickets) {
	if (tickets >= 0) {
		this->soldTickets = tickets;
	}
	else {
		this->soldTickets = 0;
	}
}

std::string Screening::getMovieName() {
	return this->movieName;
}

int Screening::getSoldTickets() {
	return soldTickets;
}

void Screening::print() {
	std::cout << "Projection is: "
		<< this->getMovieName() << " "
		<< this->getSoldTickets() << std::endl;
}

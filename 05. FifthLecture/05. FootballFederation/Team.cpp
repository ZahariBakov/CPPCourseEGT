#include "Team.h"

Team::Team(std::string name, std::string city) {
	setName(name);
	setCity(city);
	this->_points = 0;
}

void Team::setName(std::string name) {
	this->_name = name;
}

void Team::setCity(std::string city) {
	this->_city = city;
}

std::string Team::getName() const {
	return this->_name;
}

std::string Team::getCity() const {
	return this->_city;
}

int Team::getPoints() const {
	return this->_points;
}

void Team::updatePoints(int newPoints) {
	this->_points += newPoints;
}

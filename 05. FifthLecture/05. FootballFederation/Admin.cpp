#include "Admin.h"

Admin::Admin(std::string name, std::string pass) : User(name, pass) {}

void Admin::addTeam(Team newTeam) {
	this->_teams.push_back(newTeam);
	std::cout << "Adding new team " << newTeam.getName() << " - " << newTeam.getCity() << std::endl;
}

void Admin::removeTeam(Team t) {
	std::string teamName = t.getName();

	for (size_t i = 0; i < this->_teams.size(); ++i) {
		if (this->_teams[i].getName() == teamName) {
			this->_teams.erase(_teams.begin() + i);
			std::cout << "Deleting team " << teamName << std::endl;
			break;
		}
	}
}

void Admin::updateTeam(Team t) {
	std::string teamName = t.getName();

	for (size_t i = 0; i < _teams.size(); ++i) {
		if (_teams[i].getName() == teamName) {
			_teams.at(i) = t;
			std::cout << "Updating team " << teamName << std::endl;
			break;
		}
	}
}

std::vector<Team> Admin::getTeams() {
	return this->_teams;
}

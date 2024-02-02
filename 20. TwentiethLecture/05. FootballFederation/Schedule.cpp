#include "Schedule.h"

#include <typeinfo>

static int findFreeDay(std::map<int, std::pair<Team*, Team*>> matches) {
	int freeDay = 1;

	std::map<int, std::pair<Team*, Team*>>::iterator it = matches.begin();

	while (it != matches.end()) {
		if (freeDay != it->first) {
			break;
		}

		freeDay++;
		it++;
	}

	return freeDay;
}

void Schedule::addMatch(Admin* user, int day, Team* host, Team* guest) {
	std::string type = typeid(user).name();

	if (type != "class Admin * __ptr64") {
		std::cout << "You do not have permission to do this." << std::endl;
	}
	else {
		int lastDay = 0;

		for (auto& match : this->_matches) {
			lastDay = match.first;
			if (day == match.first) {
				std::cout << day << " day is already taken. \n";
				day = findFreeDay(this->_matches);
				std::cout << "Day is set to " << day << std::endl;
			}
			else if (day <= 0) {
				std::cout << day << " day must be positive number greater than 0. \n";
				day = findFreeDay(this->_matches);
				std::cout << "Day is set to " << day << std::endl;
			}
		}

		if (day > lastDay + 1) {
			std::cout << day << " day is too larger number." << std::endl;
			day = findFreeDay(this->_matches);
			std::cout << "Day is set to " << day << std::endl;
		}

		this->_matches[day] = std::make_pair(host, guest);

		std::cout << "Day " << day << " match between " << this->_matches[day].first->getName() << " and "
			<< this->_matches[day].second->getName() << " teams has been added." << std::endl;
	}
}

void Schedule::updateMatch(Admin* user, int day, Team* host, Team* guest) {
	std::string type = typeid(user).name();

	if (type != "class Admin * __ptr64") {
		std::cout << "You do not have permission to do this." << std::endl;
	}
	else {
		std::cout << "Day " << day << " match between " << this->_matches[day].first->getName() << " and "
			<< this->_matches[day].second->getName() << " teams has been updated." << std::endl;
		this->_matches[day] = std::make_pair(host, guest);
	}
}

void Schedule::deleteMatch(Admin* user, int day) {
	std::string type = typeid(user).name();

	if (type != "class Admin * __ptr64") {
		std::cout << "You do not have permission to do this." << std::endl;
	}
	else {
		std::cout << "Day " << day << " match between " << this->_matches[day].first->getName() << " and "
			<< this->_matches[day].second->getName() << " teams has been deleted." << std::endl;
		this->_matches.erase(day);
	}
}

void Schedule::addReferee(Admin* user, int day, std::string refereeName) {
	std::string type = typeid(user).name();

	if (type != "class Admin * __ptr64") {
		std::cout << "You do not have permission to do this." << std::endl;
	}
	else {
		for (auto& match : this->_matches) {
			if (day == match.first) {
				this->_refereeMatches[day] = refereeName;
				std::cout << "Referee '" << refereeName << "' has been appointed to the football match between '" << match.second.first->getName()
					<< "' and '" << match.second.second->getName() << "', which will be played on day " << match.first << "." << std::endl;
			}
		}
	}
}

void Schedule::addResult(Referee* user, Team* host, Team* guest) {
	std::string type = typeid(user).name();

	if (type != "class Referee * __ptr64") {
		std::cout << "You do not have permission to do this." << std::endl;
	}
	else {
		std::cout << "For match between " << host->getName() << " and "
			<< guest->getName() << std::endl;
		int homeGoals = 0;
		int guestGolas = 0;
		std::cout << "Enter goals of " << host->getName() << std::endl;
		std::cin >> homeGoals;
		std::cout << "Enter goals of " << guest->getName() << std::endl;
		std::cin >> guestGolas;

		if (homeGoals > guestGolas) {
			host->updatePoints(3);
		}
		else if (homeGoals < guestGolas) {
			guest->updatePoints(3);
		}
		else {
			host->updatePoints(1);
			guest->updatePoints(1);
		}
	}
}

int Schedule::getMoneyFromTickets() {
	return this->_moneyFromTickets;
}

void Schedule::updateMoneyFromTickets(int money) {
	this->_moneyFromTickets += money;
}

void Schedule::buyTicket(Fans* user, int day) {
	for (auto& match : this->_matches) {
		if (day == match.first) {
			std::cout << user->getName() <<  " want to buy ticket for day " << match.first << " For match between '" << match.second.first->getName()
				<< "' and '" << match.second.second->getName() << "'" << std::endl;
			std::cout << "Price is 25$. Do you argee? y/n ";
			char answer;
			std::cin >> answer;

			if (answer == 'y' || answer == 'Y') {
				std::cout << user->getName() << " you buy a ticket. Thank you!" << std::endl;
				this->updateMoneyFromTickets(25);
				break;
			}
			else {
				std::cout << "You don't buy a ticket." << std::endl;
				break;
			}
		}
	}
}

void Schedule::printMoneyFromTicket(Admin* user) {
	std::string type = typeid(user).name();

	if (type != "class Admin * __ptr64") {
		std::cout << "You do not have permission to do this." << std::endl;
	}
	else {
		std::cout << "Al money for season is: " << this->getMoneyFromTickets() << std::endl;
	}
}

void Schedule::printSchedule() {
	std::cout << "\n              --- Schedule ---" << std::endl;
	for (auto& match : this->_matches) {
		std::cout << "Day: " << match.first << " Current match is: " << match.second.first->getName() << " - " << match.second.second->getName() << "\n";
	}
	std::cout << std::endl;
}

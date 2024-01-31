#pragma once

#include <string>

class Team {
public:

	Team(std::string, std::string);

	void setName(std::string);
	void setCity(std::string);

	std::string getName() const;
	std::string getCity() const;
	int getPoints() const;

	void updatePoints(int);

private:

	std::string _name;
	std::string _city;
	int         _points;
};

#pragma once

#include <string>

#include "Hall.h"

class Cinema {
public:
	Cinema(std::string, std::string, std::vector<Hall>);

	void setName(std::string);
	void setAdress(std::string);
	void setHallsList(std::vector<Hall>);

	std::string getName();
	std::string getAdress();
	std::vector<Hall> getHallsList();

	void addHall(Hall);

	void print();

private:
	std::string name;
	std::string adress;
	std::vector<Hall> hallsList;
};

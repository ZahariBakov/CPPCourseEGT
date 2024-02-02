#pragma once

#include <string>

class Screening {
public:
	Screening(std::string, int);

	void setMovieName(std::string);
	void setSoldTickets(int);

	std::string getMovieName();
	int getSoldTickets();

	void print();

private:
	std::string movieName;
	int soldTickets;
};

#pragma once

#include <vector>

#include "Screening.h"

class Hall {
public:
	Hall(std::string, int);
	Hall(std::string, int, std::vector<Screening>);

	void setScreeningList(std::vector<Screening>);
	void setName(std::string);
	void setSeats(int);

	std::vector<Screening> getScreeningList();

	void addScreening(Screening);

	void print();

private:
	std::string name;
	int seats;
	std::vector<Screening> screeningList;
};

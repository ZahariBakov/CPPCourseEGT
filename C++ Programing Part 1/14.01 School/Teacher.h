#pragma once

#include "Discipline.h"

class Teacher {
public:
	Teacher(const std::string&, const std::string&, const std::vector<Discipline>&);

	std::string getName();
	std::string getTitle();
	std::vector<Discipline> getDisciplines();

private:
	std::string name;
	std::string title;
	std::vector<Discipline> disciplines;
};

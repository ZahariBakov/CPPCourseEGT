#pragma once

#include <iostream>
#include <string>
#include <vector>

class Discipline {
public:
	Discipline(const std::string&, int, int);

	void setName(std::string);
	void setLecturesNumber(int);
	void setExercisesNumber(int);

	std::string getName();

	int getLectures();

	int getExrcises();

	void printDisciplineIfno();

private:
	std::string name;
	int lectureCount;
	int exerciseCount;
};

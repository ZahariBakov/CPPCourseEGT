#pragma once

#include "Class.h"

class School {
public:
	School(const std::vector<Class>&);

	std::vector<Class> getClasses();

private:
	std::vector<Class> classes;
};

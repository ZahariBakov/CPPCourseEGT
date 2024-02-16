#pragma once

#include <iostream>

class Book {
public:
	Book(std::string title, std::string author, int pages);

	void display();

private:
	std::string title;
	std::string author;
	int         pages;
};

#pragma once

#include "Author.h"

class Book {
public:

	Book(std::string, std::string, int, Author);

	void setTitle(std::string);
	void setGenre(std::string);
	void setYear(int);

	std::string getTitle() const;
	std::string getGenre() const;
	int getYear() const;

	void print() const;

private:

	std::string title;
	std::string genre;
	int year;
	Author author;
};

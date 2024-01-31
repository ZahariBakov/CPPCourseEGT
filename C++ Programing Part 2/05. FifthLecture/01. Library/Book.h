#pragma once

#include "Author.h"

class Book {

public:

	Book(std::string, std::string, int, Author);

	void setBookName(std::string);
	void setGenre(std::string);
	void setYear(int);

	std::string getBookName();
	std::string getGenre();
	int         getYear() const;

	void print();

private:

	std::string _bookName;
	std::string _ganre;
	int			_year;
	Author      _author;
};

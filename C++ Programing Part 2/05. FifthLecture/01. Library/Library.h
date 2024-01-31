#pragma once

#include <vector>

#include "Book.h"

class Library {

public:

	void addBook(Book);
	void print();
	void findBook(std::string);

private:

	std::vector<Book> books;
};

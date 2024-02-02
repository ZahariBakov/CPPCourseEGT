#pragma once

#include <vector>

#include "Book.h"

class Library {
public:

	void addBook(Book);
	void print() const;
	void findBook(std::string) const;

private:

	std::vector<Book> books;
};

#include "Library.h"

void Library::addBook(Book b) {
	this->books.push_back(b);
}

void Library::print() const {
	for (Book book : books) {
		book.print();
	}
}

void Library::findBook(std::string text) const {
	for (Book book : books) {
		//if (book.getTitle().find(text) != -1) { - is same with under
		if (book.getTitle().find(text) != std::string::npos) {
			std::cout << "\nWe found the book " << std::endl;
			book.print();
			break;
		}
	}
}

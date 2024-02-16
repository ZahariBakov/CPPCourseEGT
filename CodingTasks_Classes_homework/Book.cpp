#include "Book.h"

Book::Book(std::string title, std::string author, int pages) : title(title), author(author), pages(pages)  {}

void Book::display() {
	std::cout << "The book: " << this->title << ", by author " << this->author 
		<< " contains " << this->pages << " pages." << std::endl;
}

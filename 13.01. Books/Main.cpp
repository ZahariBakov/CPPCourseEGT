#include <iostream>
#include <vector>

#include "Book.h"
#include "BookService.h"

std::vector<Book> EnterBooks() {
    std::vector<Book> books;
    int booksCount = 0;

    std::cout << "How many books do you want to enter? \n";
    std::cin >> booksCount;

    BookService bs;

    for (int i = 0; i < booksCount; ++i) {
        Book myBook = bs.inputData();
        books.push_back(myBook);
    }

    return books;
}

void theCheapestBook(std::vector<Book>& books) {
    double mostCheapestBook = books.at(0).getPrice();
    size_t idx = 0;

    for (size_t i = 1; i < books.size(); ++i) {
        if (books.at(i).getPrice() < mostCheapestBook) {
            mostCheapestBook = books.at(i).getPrice();
            idx = i;
        }
    }

    std::cout << "Most cheapest book is: ";
    books[idx].displayMessage();
    std::cout << std::endl;
}

void library(std::vector<Book>& books) {
    size_t booksSize = books.size();

    std::cout << "All books" << std::endl;

    for (size_t i = 0; i < booksSize; ++i) {
        books[i].displayMessage();
    }
    std::cout << std::endl;

}

void theMostExpensiveBook(std::vector<Book>& books) {
    double mostExpensiveBook = books[0].getPrice();
    size_t idx = 0;

    for (size_t j = 1; j < books.size(); ++j) {
        if (books[j].getPrice() > mostExpensiveBook) {
            mostExpensiveBook = books[j].getPrice();
            idx = j;
        }
    }

    std::cout << "Most expensive book is: ";
    books.at(idx).displayMessage();
    std::cout << std::endl;

    library(books);
}

void searchBook(std::vector<Book>& books) {
    std::string search;

    std::cout << "Enter the author or book you are looking for. \n";
    std::getline(std::cin >> std::ws, search);

    for (size_t i = 0; i < books.size(); ++i) {
        if (search == books.at(i).getAuthor() || search == books[i].getTitle()) {
            books[i].displayMessage();
        }
    }
}

int main() {
    auto books = EnterBooks();

    theCheapestBook(books);
    theMostExpensiveBook(books);

    searchBook(books);

    return 0;
}

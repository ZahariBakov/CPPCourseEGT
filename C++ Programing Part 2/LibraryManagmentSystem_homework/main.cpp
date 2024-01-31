#include "Book.h"
#include "Member.h"

#include <vector>

int main() {
    // create three books
    Book firstBook("Ten Little Niggers", "Agatha Christie", "9789048824892");
    Book secondBook("Moby Dick", "Herman Melville", "9780763630188");
    Book thirdBook("Don Quixote", "Miguel de Cervantes", "9788408061052");

    // testing functions in Book class
    //std::cout << firstBook.getISBN() << std::endl;
    //firstBook.display();
    //std::cout << secondBook.getAuthor() << std::endl;
    //secondBook.display();
    //std::cout << thirdBook.getTitle() << std::endl;
    //thirdBook.display();

    // create three members
    Member firstMember("James Smith", 23, "1001");
    Member secondMember("Mary Williams", 23, "1013");
    Member thirdMember("David Johnson", 23, "1065");

    // testing functions in Member class
    //firstMember.display();
    //std::cout << secondMember.getMemberID() << std::endl;
    //secondMember.borrowBook(&thirdBook);
    //std::cout << thirdMember.getAge() << std::endl;

    // create vector with books
    std::vector<Book*> books{ &firstBook };
    // add another two books
    books.push_back(&secondBook);
    books.push_back(&thirdBook);

    // testing vector with books
    size_t booksSize = books.size();
    //std::cout << booksSize << std::endl;

    // loop books in vector
    //for (auto book : books) {
    //    std::cout << book->getTitle() << std::endl;
    //}

    // create vector with members
    std::vector<Member*> members;
    members.push_back(&firstMember);
    members.push_back(&secondMember);
    members.push_back(&thirdMember);

    // testing vector with members
    size_t membersSize = members.size();
    //std::cout << membersSize << std::endl;

    // loop members vector
    //for (auto member : members) {
    //    std::cout << member->getName() << std::endl;
    //}

    // two for loops where:
    // First member borrow the last book, 
    // Second member borrow the midle book 
    // Third member borrow the first book.
    for (size_t i = 0; i < membersSize; ++i) {
        for (size_t j = booksSize - 1; j > 0; --j) {
            members[i]->borrowBook(books[j]);
        }
    }

    return 0;
}

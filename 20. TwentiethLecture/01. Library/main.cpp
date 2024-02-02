#include "Author.h"
#include "Book.h"
#include "Library.h"

int main() {

    Author a1("Harper",  "Lee",       "American");
    Author a2("Stephen", "King",      "American");
    Author a3("Joanne",  "Rowling",   "British");
    Author a4("Walter",  "Isaacson",  "American");
    Author a5("Casey",   "McQuiston", "American");

    Book b1("To Kill a Mockingbird",                    "", 1960, a1);
    Book b2("Fairy Tale",                               "", 2022, a2);
    Book b3("Harry Potter and the Philosopher's Stone", "", 1997, a3);
    Book b4("Steve Jobs",                               "", 2011, a4);
    Book b5("Red, White & Royal Blue",                  "", 2019, a5);

    Library library;
    library.print();

    library.addBook(b1);
    library.addBook(b2);

    library.print();

    library.findBook("Tale");

    return 0;
}

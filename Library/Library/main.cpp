#include "Author.h"
#include "Book.h"
#include "Library.h"

int main() {

    enum Genre { CLASSIC, CRIME, FANTASY };

    Author author("John", "Doe", "GB");
    //author.print()

    Book book1("BookTitle", "classic", 2020, author);
    Book book2("Book2Title", "crime", 2021, author);

    Library library;
    library.print();

    library.addBook(book1);
    library.addBook(book2);

    library.print();

    library.findBook("2");

    return 0;
}

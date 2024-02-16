#include "Book.h"

int main() {
    Book firstBook("Shuggie Bain", "Douglas Stuart", 135);
    Book secondBook("White Noise", "Don DeLillo", 250);
    Book thirdBook("American Psycho", "Bret Easton Ellis", 512);

    firstBook.display();
    secondBook.display();
    thirdBook.display();

    return 0;
}

#include <iostream>
#include <iomanip>
#include <time.h>

int main() {
    // nine random dice generator
    //unsigned seed;

    //std::cout << "Enter seed ";
    //std::cin >> seed;
    //srand(seed); // seed random generator

    //for (int counter = 0; counter < 10; ++counter) {
    //    std::cout << std::setw(10) << (1 + rand() % 6);

    //    if (counter % 5 == 0) {
    //        std::cout << std::endl;
    //    }
    //}

    // Ten random nubers
    srand(time(0));

    for (int i = 0; i <= 10; ++i) {
        std::cout << i + rand() << " ";
    }
    std::cout << std::endl;

    return 0;
}

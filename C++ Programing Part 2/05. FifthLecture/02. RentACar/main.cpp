#include "Car.h"
#include "FamilyCar.h"
#include "LuxuryCar.h"

int main() {
    Car c1("Audi", "A6", "sedan", "black", "WVWZZZ....1254", "CB5268PH", 12.5);
    Car c2("BMW", "530", "station wagon", "blue", "NVHURD......5489", "CA5789TH", 15.6);
    Car c3("Citroen", "C3", "hatchback", "silver", "HFTRE.....5487", "PK5498AH", 6.2);
    Car c4("Dacia", "Logan", "sedan", "white", "HGTRED......5469", "PB5487XA", 5.5);

    FamilyCar familyCar("Opel", "Corsa", "hatchback", "red", "123456789", "B5614AH", 10.0);
    std::cout << familyCar.calculatePrice() << std::endl;

    LuxuryCar luxuryCar("Mercedes", "S500", "limo", "black", "WDBJK254", "CA0007PK", 23.8);
    std::cout << luxuryCar.calculatePrice() << std::endl;

    return 0;
}

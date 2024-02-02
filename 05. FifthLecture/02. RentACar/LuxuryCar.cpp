#include "LuxuryCar.h"

static int calculateLuxTax() {
    int luxTax = 0;
    char answer;

    std::cout << "Do you want to use additionalextras? y/n " << std::endl;
    std::cin >> answer;

    if (answer == 'y' || answer == 'Y') {
        std::cout << " MENU " << std::endl;
        std::cout << "Champagne - 100lv. - press 1" << std::endl;
        std::cout << "Wine - 50lv. - press 2" << std::endl;
        std::cout << "Chocolate - 40lv. - press 3" << std::endl;
        std::cin >> luxTax;

        if (luxTax == 1) {
            luxTax = 100;
        }
        else if (luxTax == 2) {
            luxTax = 50;
        }
        else if (luxTax == 3) {
            luxTax = 40;
        }
        else {
            std::cout << "Invalid choise. " << std::endl;
        }
    }
    else {
        std::cout << "You will not enjoy additional comfort. " << std::endl;
    }

    return luxTax;
}

static double calculateKmTax(int dayTax) {
    double km;
    double tax;

    std::cout << "Enter the distance traveled in kilometers." << std::endl;
    std::cin >> km;

    if (km < 200.0) {
        tax = dayTax * 0.6;
    }
    else {
        tax = dayTax * 0.4;
    }

    return tax;
}

LuxuryCar::LuxuryCar(std::string make, std::string model, std::string type, std::string color,
	std::string vin, std::string plate, double fuelConsumption, int taxPerDay)
	: Car(make, model, type, color, vin, plate, fuelConsumption, taxPerDay) {}

double LuxuryCar::calculatePrice() {
    std::cout << "For car " << this->getMake() << ". ";
	int dayTax = this->getDayTax();
    int luxTax = calculateLuxTax();
	double kmTax = calculateKmTax(dayTax);

    Car::calculatePrice();

    return (dayTax * kmTax) + luxTax;
}

#include "FamilyCar.h"

static double getKmTax(int dayTax, std::string car) {
    double km;
    double tax;

    std::cout << "Enter the distance traveled in kilometers for car " << car << ". " << std::endl;
    std::cin >> km;

    if (km < 500.0) {
        tax = dayTax * 0.7;
    }
    else {
        tax = dayTax * 0.4;
    }

    return tax;
}

FamilyCar::FamilyCar(std::string make, std::string model, std::string type, std::string color, 
    std::string vin, std::string plate, double fuelConsumption, int taxPerDay)
    : Car(make, model, type, color, vin, plate, fuelConsumption, taxPerDay) {}

double FamilyCar::calculatePrice() {
    int dayTax = this->getDayTax();
	double kmTax = getKmTax(dayTax, this->getMake());

    Car::calculatePrice();

    return dayTax * kmTax;
}

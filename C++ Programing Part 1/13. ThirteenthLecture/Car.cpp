#include "Car.h"

Car::Car(string model, int year, string color, string fuel, 
    string vin, string transmission, string plate) {
	setModel(model);
	setYear(year);
	this->color = color;
	this->fuel = fuel;
	this->vin = vin;
	this->transmission = transmission;
    this->plate = plate;
}

void Car::setModel(string model)
{
    this->model = model;
}

void Car::setYear(int year)
{
    if (year > 1970 && year < 2024) {
        this->year = year;
    }
    else {
        this->year = 0;
        cout << "Invalid year. Year must be between 1970 and 2024 " << endl;
    }
}

void Car::setColor(string color) {
    this->color = color;
}

void Car::setFuel(string fuel) {
    this->fuel = fuel;
}

void Car::setVin(string vin) {
    this->vin = vin;
}

void Car::setTransmission(string transmission) {
    this->transmission = transmission;
}

void Car::setPlate(string plate) {
    this->plate = plate;
}

void Car::displayMessage()
{
    cout << "model: " << this->model
        << ", year: " << this->year
        << ", color: " << this->color
        << ", fuel: " << this->fuel
        << ", vin: " << this->vin
        << ", transmission: " << this->transmission
        << ", plate: " << this->plate
        << endl;
}

//Car Car::inputData() {
//    string model;
//    int year;
//    string color;
//    string fuel;
//    string vin;
//    string transmission;
//    string plate;
//
//    cout << "Enter Model: " << endl;
//    cin >> model;
//
//    cout << "Enter Year: " << endl;
//    cin >> year;
//
//    cout << "Enter Color: " << endl;
//    cin >> color;
//
//    cout << "Enter Fuel: " << endl;
//    cin >> fuel;
//
//    cout << "Enter VIN: " << endl;
//    cin >> vin;
//
//    cout << "Enter Transmission: " << endl;
//    cin >> transmission;
//
//    cout << "Enter Plate: " << endl;
//    cin >> plate;
//
//    /*setModel(model);
//    setYear(year);
//    setColor(color);
//    setFuel(fuel);
//    setVin(vin);
//    setTransmission(transmission);
//    setPlate(plate);*/
//    Car myCar(model, year, color, fuel, vin, transmission, plate);
//
//    return myCar;
//}

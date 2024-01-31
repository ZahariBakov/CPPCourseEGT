#include "CarService.h"

Car CarService::inputData() {
    string model;
    int year;
    string color;
    string fuel;
    string vin;
    string transmission;
    string plate;

    cout << "Enter Model: " << " ";
    cin >> model;

    cout << "Enter Year: " << " ";
    cin >> year;

    cout << "Enter Color: " << " ";
    cin >> color;

    cout << "Enter Fuel: " << " ";
    cin >> fuel;

    cout << "Enter VIN: " << " ";
    cin >> vin;

    cout << "Enter Transmission: " << " ";
    cin >> transmission;

    cout << "Enter Plate: " << " ";
    cin >> plate;

    cout << endl;

    Car myCar(model, year, color, fuel, vin, transmission, plate);

    return myCar;
}
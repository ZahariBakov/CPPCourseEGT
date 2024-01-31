#include <iostream>
#include <vector>

#include "Car.h"
#include "CarService.h"

//Car inputData() {
//    string model;
//    int year;
//    string color;
//    string fuel;
//    string vin;
//    string transmission;
//    string plate;
//
//    cout << "Enter Model: " << " ";
//    cin >> model;
//
//    cout << "Enter Year: " << " ";
//    cin >> year;
//
//    cout << "Enter Color: " << " ";
//    cin >> color;
//
//    cout << "Enter Fuel: " << " ";
//    cin >> fuel;
//
//    cout << "Enter VIN: " << " ";
//    cin >> vin;
//
//    cout << "Enter Transmission: " << " ";
//    cin >> transmission;
//
//    cout << "Enter Plate: " << " ";
//    cin >> plate;
//
//    cout << endl;
//
//    
//    Car myCar(model, year, color, fuel, vin, transmission, plate);
//
//    return myCar;
//}

int main() {
    vector<Car> cars;

    /*Car firstCar("Citroen", 2020, "green", "diesel", "d3r2hjfsklf", "auto", "CA 47474");
    Car secondCar("Honda", 2022, "blue", "electrik", "gfkjr53jddf", "manual", "CA 34556");

    cars.push_back(firstCar);
    cars.push_back(secondCar);*/

    CarService cs;

    for (int j = 0; j < 2; ++j) {
        Car myCar = cs.inputData();
        cars.push_back(myCar);
    }

    for (int i = 0; i < cars.size(); ++i) {
        cars.at(i).displayMessage();
    }

    return 0;
}

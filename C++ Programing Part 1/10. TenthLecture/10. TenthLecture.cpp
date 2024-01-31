#include <iostream>
#include <string>

class Car {
public:
    // constructor
    Car(std::string make, std::string model, int year, std::string color, std::string fuel, std::string vin, std::string transmission, std::string plate) {
        this->make = make, this->model = model, this->year = year, this->color = color, this->fuel = fuel, this->vin = vin, this->transmission = transmission, this->plate = plate;
    };


    // setters
    void setMake(std::string make) {
        this->make = make;

    }
    void setModel(std::string model) {
        this->model = model;
    }

    void setYear(int year) {
        if (year > 1956 && year < 2024) {
            this->year = year;
        }
        else {
            this->year = 0;
            std::cout << "Invalid year. Year must be between 1957 and 2023 " << std::endl;
        }
    }

    void setColor(std::string color) {
        this->color = color;
    }

    // getters
    std::string getMake() const {
        return this->make;
    }

    std::string getModel() const {
        return this->model;
    }

    int getYear() const {
        return this->year;
    }

    std::string getColor() const {
        return this->color;
    }

    // print function
    void printInfo() const {
        std::cout << "Make: " << make << " Model: " << model << " year: " << year << " color: " << color << std::endl;
    }

private:
    // initialize variables
    std::string make;
    std::string model;
    int year;
    std::string color;
    std::string fuel;
    std::string vin;
    std::string transmission;
    std::string plate;
};
 
int main() {
    Car firstCar("Audi", "A6", 2008, "black", "diesel", "ALABALA", "automatic", "CA7777PK");
    Car thirdCar("Mercedes", "EQS", 2023, "black", "electric", "AHJKALA", "automatic", "EA0001TM");

    std::string make;
    std::cout << "Enter car make ";
    std::cin >> make;

    std::string model;
    std::cout << "Enter car model ";
    std::cin >> model;

    int year;
    std::cout << "Enter car year ";
    std::cin >> year;

    std::string color;
    std::cout << "Enter car color ";
    std::cin >> color;

    /*firstCar.setMake(make);
    firstCar.setModel(model);
    firstCar.setYear(year);
    firstCar.setColor(color);*/

    Car secondCar(make, model, year, color, "gasoline", "HAKSLA", "autmatic", "EA0042AK");

    firstCar.printInfo();
    firstCar.setYear(2002);
    firstCar.printInfo();

    secondCar.printInfo();

    thirdCar.printInfo();

    std::string carMake = firstCar.getMake();
    std::cout << "Car make " << carMake << "\n";

    std::string carModel = firstCar.getModel();
    std::cout << "Car model " << carModel << std::endl;

    int carYear = firstCar.getYear();
    std::cout << "Car year is " << carYear << std::endl;

    return 0;
}

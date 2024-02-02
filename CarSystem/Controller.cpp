#include "Controller.h"

Controller::Controller() : carId(0), timerInterval(10) {}

void Controller::addCar(const std::string& carType) {
    std::unique_ptr<BaseCar> p;
    
    if (carType == "FastCar") {
        p = std::make_unique<FastCar>(unique_name(carType));
    }
    else if (carType == "SlowCar") {
        p = std::make_unique<SlowCar>(unique_name(carType));
    }
    else if (carType == "Car") {
        p = std::make_unique<Car>(unique_name(carType));
    }
    else {
        std::cerr << "Unvalid car type: " << carType << std::endl;
    }
     
    cars.push_back(std::move(p));
}

void Controller::addRoad() {
    roads.emplace_back(std::make_unique<Road>(1000, 2));
}

void Controller::loop() {
    for (auto& car : cars) {
        if (car->hasFinished()) {
            car->assignRoad(roads[rand() % roads.size()].get());
        }
    }
    for (auto& car : cars) {
        car->tick(timerInterval);
    }
}

std::string Controller::unique_name(const std::string& carType) {
    std::ostringstream os;
    os << carType << "-id-" << carId++;
    
    return os.str();
}

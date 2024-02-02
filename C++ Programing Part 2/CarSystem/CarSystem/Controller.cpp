#include "Controller.h"

Controller::Controller() : carId(0), timerInterval(10) {}

void Controller::addCar() {
    // Car *p = new Car(unique_name());
    // cars.emplace_back(p);
    std::unique_ptr<BaseCar> p = std::make_unique<Car>(unique_name());
    cars.emplace_back(std::move(p));
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

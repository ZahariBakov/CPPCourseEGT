#pragma once

#include <iostream>
#include <sstream>

#include "Car.h"
#include "Road.h"

class Controller {
public:
    Controller();

    void addCar();
    void addRoad();
    void loop();

private:

    std::string unique_name() {
        std::ostringstream os;
        os << "car-id-" << carId++;
        return os.str();
    }

    int carId;

    double timerInterval;
    std::vector<std::unique_ptr<Car>> cars;
    std::vector<std::unique_ptr<Road>> roads;
};

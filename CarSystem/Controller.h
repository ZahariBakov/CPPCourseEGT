#pragma once

#include <iostream>
#include <sstream>

#include "BaseCar.h"
#include "Car.h"
#include "FastCar.h"
#include "SlowCar.h"

#include "Road.h"

class Controller {
public:
    Controller();

    void addCar(const std::string& carType);
    void addRoad();
    void loop();

private:
    std::string unique_name(const std::string& carType);
    int carId;
    double timerInterval;
    std::vector<std::unique_ptr<BaseCar>> cars;
    std::vector<std::unique_ptr<Road>> roads;
};

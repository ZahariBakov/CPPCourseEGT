#pragma once

#include <iostream>
#include <string>

#include "Road.h"

class Car {

public:

    Car(std::string);

    void assignRoad(Road*);

    bool hasFinished();

    void tick(double);

private:

    std::string name;
    Road* road;
    double meters;
};

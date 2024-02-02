#pragma once

#include "BaseCar.h"

class Car : public BaseCar {

public:
    Car(std::string);

    void assignRoad(Road*) override;

    bool hasFinished() override;

    void tick(double) override;

    ~Car() override {}

private:
    std::string name;
    Road* road;
    double meters;
};

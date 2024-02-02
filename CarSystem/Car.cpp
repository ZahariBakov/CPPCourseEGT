#include "Car.h"

Car::Car(std::string name) : road(NULL), name(name), meters(0) {}

void Car::assignRoad(Road* road) {
    if (this->road != NULL) {
        throw "can't override road";
    }

    this->road = road;
}

bool Car::hasFinished() {
    return road == NULL;
}

void Car::tick(double sec) {
    if (hasFinished()) {
        return;
    }

    int maxSpeed = road->maxSpeedAt(meters);

    int roadLen = road->totalLength();

    double dist = maxSpeed * (sec / 3600) * 1000;
    std::cout <<this->name << " traveled " << dist <<
        " with " << maxSpeed << std::endl;
    meters += dist;
    if (meters >= roadLen) {
        std::cout << this->name << " reached end of road"
            << std::endl;
        road = NULL;
        meters = 0;
    }
    else {
        std::cout << this->name << " at "
            << meters << "/" << roadLen << " on road" << std::endl;
    }
}

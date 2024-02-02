#include "FastCar.h"

FastCar::FastCar(std::string name) : road(nullptr), name(name), meters(0) {}

void FastCar::assignRoad(Road* road) {
    if (this->road != nullptr) {
        throw "can't override road";
    }

    this->road = road;
}

bool FastCar::hasFinished() {
    return road == nullptr;
}

void FastCar::tick(double sec) {
    if (hasFinished()) {
        return;
    }

    int maxSpeed = (road->maxSpeedAt(meters)) + 20;

    int roadLen = road->totalLength();

    double dist = maxSpeed * (sec / 3600) * 1000;
    std::cout << this->name << " traveled " << dist <<
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

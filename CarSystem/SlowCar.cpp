#include "SlowCar.h"

SlowCar::SlowCar(std::string name) : road(NULL), name(name), meters(0) {}

void SlowCar::assignRoad(Road* road) {
    if (this->road != NULL) {
        throw "can't override road";
    }

    this->road = road;
}

bool SlowCar::hasFinished() {
    return road == NULL;
}

void SlowCar::tick(double sec) {
    if (hasFinished()) {
        return;
    }

    int maxSpeed = road->minSpeedAt(meters);

    int roadLen = road->totalLength();

    double dist = maxSpeed * (sec / 3600) * 1000;
    std::cout << "Car " << this->name << " traveled " << dist <<
        " with " << maxSpeed << std::endl;
    meters += dist;
    if (meters >= roadLen) {
        std::cout << "Car " << this->name << " reached end of road"
            << std::endl;
        road = NULL;
        meters = 0;
    }
    else {
        std::cout << "Car " << this->name << " at "
            << meters << "/" << roadLen << " on road" << std::endl;
    }
}

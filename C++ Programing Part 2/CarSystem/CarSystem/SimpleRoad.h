#pragma once

#include "BaseRoad.h"

class SimpleRoad : public BaseRoad {
private:
    int minSpeed;
    int maxSpeed;
    double lenMeters;
};

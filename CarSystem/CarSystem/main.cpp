#include <chrono>
#include <thread>

#include "RoadSegment.h"

#include "BaseRoad.h"
#include "SimpleRoad.h"
#include "CombineRoad.h"
#include "Road.h"

#include "BaseCar.h"
#include "Car.h"

#include "Controller.h"

int main() {
    Controller ctl;
    ctl.addCar();
    ctl.addRoad();

    for (int i = 0; i < 10; ++i) {
        ctl.loop();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
} 

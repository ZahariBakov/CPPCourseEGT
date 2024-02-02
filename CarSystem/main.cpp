#include <chrono>
#include <thread>

#include "Controller.h"

int main() {
    Controller ctl;

    ctl.addCar("Car");
    ctl.addCar("SlowCar");
    ctl.addCar("FastCar");
    ctl.addRoad();

    for (int i = 0; i < 10; ++i) {
        ctl.loop();
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}

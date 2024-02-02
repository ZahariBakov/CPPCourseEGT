#pragma once

class BaseRoad {
public:
    virtual int minSpeedAt(double meters) const = 0;
    virtual int maxSpeedAt(double meters) const = 0;
    virtual int totalLength() const = 0;
    // virtual int getHoles() const = 0;
    virtual double getDamagePercent(double meters, int speed) const = 0;

    virtual ~BaseRoad() {};
};

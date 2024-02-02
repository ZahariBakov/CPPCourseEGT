#pragma once

#include <vector>

#include "RoadSegment.h"

class Road {

public:
    Road(double, int);

    int minSpeedAt(double meters) const;
    int maxSpeedAt(double meters) const;
    int totalLength() const;

private:

    const RoadSegment* getSegmentAt(double meters) const;
    std::vector<RoadSegment> segments;
};

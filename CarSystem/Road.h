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

    const RoadSegment* getSegmentAt(double meters) const {
        if (meters >= totalLength()) {
            return NULL;
        }
        for (int i = 0; i < segments.size(); ++i) {
            if (segments[i].begining <= meters &&
                segments[i + 1].begining > meters) {
                return &segments[i];
            }
        }
        return NULL;
    }

    std::vector<RoadSegment> segments;
};

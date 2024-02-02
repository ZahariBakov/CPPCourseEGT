#include "Road.h"

Road::Road(double meters, int numSegments) {
    double segLen = meters / numSegments;
    for (int i = 0; i < numSegments; ++i) {
        int maxSpeed = 50 + rand() % 50;
        segments.push_back(RoadSegment{
                i * segLen,
                maxSpeed - 20,
                maxSpeed,
            });
    }
    segments.push_back(RoadSegment{ meters, 0, 0 });
}

int Road::minSpeedAt(double meters) const {
    return getSegmentAt(meters)->minSpeed;
}

int Road::maxSpeedAt(double meters) const {
    return getSegmentAt(meters)->maxSpeed;
}

int Road::totalLength() const {
    return segments[segments.size() - 1].begining;
}

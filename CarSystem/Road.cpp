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

const RoadSegment* Road::getSegmentAt(double meters) const {
    if (meters >= totalLength()) {
        return NULL;
    }
    for (int i = 0; i < segments.size(); ++i) {
        if (segments[i].begining <= meters && segments[i + 1].begining > meters) {
            return &segments[i];
        }
    }
    return NULL;
}

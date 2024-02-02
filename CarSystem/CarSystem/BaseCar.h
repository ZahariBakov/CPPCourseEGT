#pragma once

#include "Road.h"

class BaseCar {

public:

	virtual void tick(double) = 0;
	virtual void assignRoad(Road* road) = 0;
	virtual bool hasFinished() = 0;
	
	virtual ~BaseCar() {}

};

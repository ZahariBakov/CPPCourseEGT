#pragma once

#include <vector>

#include "BaseRoad.h"

class CombineRoad : public BaseRoad {
public:

private:
    std::vector<BaseRoad*> segments;
};

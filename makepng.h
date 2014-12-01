#ifndef DEF_MAKEPNG
#define DEF_MAKEPNG

#include <cmath>
#include <iostream>
#include "Station.h"

#include "lodepng.h"

#define DISPCOEF 1

void generateImage(const float xmin, const float xmax,
    const float ymin, const float ymax,
    const float min, const float max,
    const float step, float(*interp)(float, float,std::vector<Station>&),
    std::vector<Station> &stations);
#endif

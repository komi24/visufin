
#ifndef SHEPARD_H
#define SHEPARD_H


#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cmath>
#include <fstream>
#include "Station.h"

float ComputeShepardInterpolation(const float longitude, const float latitude,  std::vector<Station> &stations);


#endif

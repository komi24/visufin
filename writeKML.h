#ifndef writeKML_H
#define writeKML_H

#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include <cmath>
#include <fstream>
#include <vector>
#include "Segment.h"

using namespace std;

void writeKMLimage(const float North, const float South,
    const float West, const float East);

void writeKMLisocont(const float North, const float South,
    const float West, const float East,
    vector<Segment> &segments);


#endif

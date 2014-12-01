#ifndef DEF_STATION
#define DEF_STATION

#include <string>
#include <iostream>
#include <vector>

class Station
{
    public:

    Station();
    Station(float longitude, float latitude, float value);

    float longitude;
    float latitude;
    float value;
};

#endif

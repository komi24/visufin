#include "shepard.h"
using namespace std;

float ComputeShepardInterpolation(const float longitude, const float latitude,  std::vector<Station> &stations) {
float inv = 0;
 float res = 0;

  for (vector<Station>::iterator it = stations.begin(); it != stations.end(); it++) {
    inv += 1/(pow((latitude - it->latitude),2) + pow((longitude - it->longitude),2));


  }

for (vector<Station>::iterator it = stations.begin(); it != stations.end(); it++) {
  res += (1/(pow((latitude - it->latitude),2) + pow((longitude - it->longitude),2)))*it->value  ;

  }
 res = res/inv ;


 
 return res;
}

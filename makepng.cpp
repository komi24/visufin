#include "makepng.h"
#include <cmath>
#include <iostream>
#include "Station.h"

#include "lodepng.h"

#define DISPCOEF 1

using namespace std;

void generateImage(const float xmin, const float xmax,
    const float ymin, const float ymax,
    const float min, const float max,
    const float step, float(*interp)(float, float,vector<Station>&),
    vector<Station> &stations)
{
  const unsigned w = (unsigned)( (xmax - xmin)/step);
  const unsigned h = (unsigned)( (ymax - ymin)/step);
  vector<unsigned char> image;

  for(unsigned y = 0; y < h; y++)
  for(unsigned x = 0; x < w; x++)
  {
   int dv = 100;
    int i = (int)((interp(xmin+step*x,ymax-step*y,stations)-min)*(100/(max-min)));
    unsigned char r,g,b,a;
    a=155;
 
   if(i<0) i=0;
   if(i>dv) i=dv;

   if (i < dv/4) {
      r = 0;
      g = (4 * i);
      b = dv;
   } else if (i < dv/2) {
      r = 0;
      g = dv;
      b = dv-(4*i-dv);
   } else if (i < (3*dv)/4) {
      r = 4*i-2*dv;
      g = dv;
      b = 0;
   } else {
      r = dv;
      g = dv-(4*i-3*dv);
      b = 0;
   }
   image.push_back(r);
   image.push_back(g);
   image.push_back(b);
   image.push_back(250);
  }

  unsigned error = lodepng::encode("interp.png", image, w, h);

  //if there's an error, display it
  if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}

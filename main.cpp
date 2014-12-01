#include "shepard.h"
#include "KmlFactory.h"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
  int hour,day,iso;
  stringstream ss1(argv[1]);
  stringstream ss2(argv[2]);
  stringstream ss3(argv[3]);
  ss1 >> day;
  ss2 >> hour;
  ss3 >> iso;
  KmlFactory *test = new KmlFactory();
  test->parseData(day,hour);
  //vector<Station> stations = vector<Station>();
  //ComputeShepardInterpolation(1.0,0.2,stations);
  test->setInterp(&ComputeShepardInterpolation);
  test->interpolate(0.001);
  test->updateIsocont(iso,0.04);
}

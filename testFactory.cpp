#include "KmlFactory.h"
#include <iostream>

using namespace std;

float disp (float a, float b){
  cerr << "test " << a << " " << b << endl;
  return 0.1;
}

int main(int argc, char **argv){
  KmlFactory *test = new KmlFactory();
  test->parseData(1,1);
  test->setInterp(&disp);
  test->interpolate(0.6);
}

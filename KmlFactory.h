#ifndef DEF_KMLFACTORY
#define DEF_KML_FACTORY

#include <iostream>
#include "Parser.h"
#include "Point.h"
#include "Segment.h"
#include "isocontour.h"
#include "hardy.cpp"
#include </home/komi24/ensimag/visu/visufin/eigen-eigen-1306d75b4a21/Eigen/Dense>


class KmlFactory {
  private :
    float limitW,limitE,limitN,limitS;
    float domainMin,domainMax;
    float R;
    Eigen::VectorXf x;
    Parser *parser;
    std::vector<Point> *values;
    std::vector<Segment> isocont;
    float(*interp)(float, float,std::vector<Station>&);
    float(*hardyinterp)(float, float ,  std::vector<Station> &);


  public :
    KmlFactory() {};
    //parse le fichier et initialise les limites W,E,N,S et domainMax et Min
    //parser non NULL après appel
    float hardyinterpol(float longitude, float latitude,  std::vector<Station> &);
    void parseData(int day, int hour);
    void setInterp(float(*f)(float,float,std::vector<Station>&));
    void interpolate(float step);//Define limits before truely interpolate, create png and kml
    void interpolateHardy(float step);//Define limits before truely interpolate, create png and kml
    void updateIsocont(float p, float val);
};
#endif

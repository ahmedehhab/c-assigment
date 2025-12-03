#include "geoShape.h"
#ifndef TRIANGLE_H
#define  TRIANGLE_H

class Triangle : public GeoShape{
    public:
    Triangle(float d1,float d2);
  float area() override;
};



#endif
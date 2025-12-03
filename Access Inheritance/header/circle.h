#include "geoShape.h"
#ifndef CIRCLE_H
#define  CIRCLE_H

class Circle : private GeoShape{
public:
Circle(float d);
  float area() override;
};



#endif
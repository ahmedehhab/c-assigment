#include "geoShape.h"
#ifndef RECT_H
#define RECT_H
class Rect : public GeoShape{
    public:
    Rect(float d1,float d2);
    Rect();
    
    float area() override;
};

#endif
#include "rect.h"
#ifndef SQUARE_H
#define SQUARE_H
class Square : private Rect{
    public:
     Square(float d);
    float area() override;
};




#endif
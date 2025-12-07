#include "shape.h"
#ifndef POINT_H
#define POINT_H

class Point  : public Shape{
   private :
     int x;
     int y;
public:

    Point(int x, int y);

    int getx();
    int gety();
    void draw(sf::RenderWindow &window) override;
};

#endif

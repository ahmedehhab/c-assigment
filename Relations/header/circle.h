#include "point.h"
#include "shape.h"
#ifndef CIRCLE_H
#define CIRCLE_H
class Circle : public Shape {
    public:
    Point center;
    int reduis;
    Circle (int x,int y ,int reduis);
    void draw(sf::RenderWindow &window) override;
};

#endif

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>
#include <SFML/Graphics.hpp>

class Shape
{
public:
virtual void draw(sf::RenderWindow &window)=0;
virtual ~Shape(){};

};
// inline void gotoXY(int x, int y) {
//     printf("\033[%d;%dH", y, x);
// }

#endif
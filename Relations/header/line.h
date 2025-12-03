#include "point.h"
#include "shape.h"
#ifndef LINE_H
#define LINE_H
class Line :public Shape
{
private:
Point start;
Point end;
public:
   Line(int x1 ,int y1,int x2,int y2);
   void draw() override ;
};

#endif
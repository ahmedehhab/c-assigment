#include <iostream>
#include "../header/line.h"
using namespace std;

Line::Line(int x1,int y1,int x2,int y2):start(x1,y1),end(x2,y2){};

void Line::draw(){
 cout<<start.getx()<< " " << start.gety()<<"          "<<end.getx()<<" "<<end.gety();
};
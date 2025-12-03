#include "../header/point.h"
#include <iostream>
using namespace std;
Point::Point(int x, int y) {
    this->x = x;
    this->y = y;
}

int Point::getx() {
    return x;
}

int Point::gety() {
    return y;
}

void Point::draw(){
    cout<<this->x<<"  "<<this->y;
}
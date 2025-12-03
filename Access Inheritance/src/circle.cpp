#include "../header/circle.h"
#define PI 3.14159

Circle::Circle(float d){
  this->d1=this->d2=d;
}
float Circle::area(){
    return PI *d1;
}
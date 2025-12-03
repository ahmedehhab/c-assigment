#include "../header/square.h"

Square::Square(float d){
    this->d1=this->d2=d;
}

float Square::area(){
     return d1*d2;
}
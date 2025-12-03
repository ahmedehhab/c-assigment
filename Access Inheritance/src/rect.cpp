#include "../header/rect.h"

float Rect::area(){
    return d1*d2;
}
Rect::Rect(float d1,float d2){
    this->d1=d1;
    this->d2=d2;
}


Rect::Rect(){
    this->d1=0;
    this->d2=0;
}

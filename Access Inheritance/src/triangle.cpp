#include "../header/triangle.h"

Triangle::Triangle(float d1,float d2){
    this->d1=d1;
    this->d2=d2;
}

float Triangle:: area(){
    return 0.5*d1*d2;
}
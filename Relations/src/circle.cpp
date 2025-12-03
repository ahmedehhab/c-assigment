#include "../header/circle.h"
#include <iostream>
using namespace std;
Circle::Circle (int x,int y ,int reduis):center(x,y){
        this->reduis=reduis;
    };

 
void Circle::draw(){
    cout<<center.getx()<<" "<<center.gety()<<"    "<<reduis;
} 



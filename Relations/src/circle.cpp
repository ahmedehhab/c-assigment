#include "../header/circle.h"
#include <iostream>
using namespace std;
Circle::Circle (int x,int y ,int reduis):center(x,y){
        this->reduis=reduis;
    };

 
// void Circle::draw(){
//     cout<<center.getx()<<" "<<center.gety()<<"    "<<reduis;
// } 


 void Circle::draw(sf::RenderWindow &window) {
         sf::CircleShape c(this->reduis);
        c.setFillColor(sf::Color::Transparent);
        c.setOutlineThickness(2);
        c.setOutlineColor(sf::Color::Red);
        c.setPosition(center.getx(), center.gety());

        window.draw(c);
    
    };

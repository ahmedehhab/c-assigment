#include "../header/circle.h"
#include "../header/line.h"
#include "../header/point.h"
#include "../header/picture.h"
#include "../header/shape.h"
#include "../header/arrayManager.h"
#include<iostream>
#define SIZE_OF_ARRAY 10
using namespace std; 

int main(){
 
  // void ** pricture= new void *[10];
  // for(int i=0;i<=5;i++){
  //   pricture[i]=new Line(1+i,2+i, 3+i,4+i);
  //   ((Line *)pricture[i])->draw();
  //   cout<<'\n';
  // }

  //  for(int i=6;i<10;i++){
  //   pricture[i]=new Circle(1+i,2+i , 50+i);
  //   ((Circle *)pricture[i])->draw();
  //   cout<<'\n';
  // }
  
//  Picture p(20);
//  p.addLine(1,2,4,5);
//  p.addCircle(1,5,10);
//  p.draw();
// int size=SIZE_OF_ARRAY;
// Shape **Picture =new Shape*[size];

// cout<<"---------------LINE---------------------------\n";
// for(int i=0;i<=100;i++){
//   Shape * l=new Line(1+i,2+i,3+i,4+i);
// addShape(Picture,l,size,i);

// Picture[i]->draw();
// cout<<'\n';
// }
// cout<<"---------------CIRCLE---------------------------\n";
// for(int i=101;i<=200;i++){
//   Shape * l=new Circle(1+i,2+i, 15+i);
// addShape(Picture,l,size,i);

// Picture[i]->draw();
// cout<<'\n';
// }
// cout<<"---------------POINT---------------------------\n";
// for(int i=101;i<=200;i++){
//   Shape * l=new Point(1+i,2+i);
// addShape(Picture,l,size,i);

// Picture[i]->draw();
// cout<<'\n';
// }





  // Shape* s1 = new Line(5, 3, 3, 20);
    // Shape* s2 = new Circle(40, 10, 8);
    // Shape* s3 = new Point(10, 5);

    // s1->draw();
    // s2->draw();
    // s3->draw();



     sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Shapes");

  int size = SIZE_OF_ARRAY;
int capacity = size;
int index = 0;

Shape** Picture = new Shape*[capacity];

Shape* L = new Line(100, 100, 300, 300);
addShape(Picture, L, capacity, index);

Shape* C = new Circle(200, 200, 50);
addShape(Picture, C, capacity, index);

Shape* P = new Point(400, 300);
addShape(Picture, P, capacity, index);

while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    window.clear();

    for (int i = 0; i < index; i++)
        Picture[i]->draw(window);

    window.display();
}


 return 0;
}
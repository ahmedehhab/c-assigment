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
int size=SIZE_OF_ARRAY;
Shape **Picture =new Shape*[size];

cout<<"---------------LINE---------------------------\n";
for(int i=0;i<=100;i++){
  Shape * l=new Line(1+i,2+i,3+i,4+i);
addShape(Picture,l,size,i);

Picture[i]->draw();
cout<<'\n';
}
cout<<"---------------CIRCLE---------------------------\n";
for(int i=101;i<=200;i++){
  Shape * l=new Circle(1+i,2+i, 15+i);
addShape(Picture,l,size,i);

Picture[i]->draw();
cout<<'\n';
}
cout<<"---------------POINT---------------------------\n";
for(int i=101;i<=200;i++){
  Shape * l=new Circle(1+i,2+i, 15+i);
addShape(Picture,l,size,i);

Picture[i]->draw();
cout<<'\n';
}
 return 0;
}
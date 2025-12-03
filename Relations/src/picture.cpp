#include "../header/picture.h"
#include "../header/line.h"
#include "../header/circle.h"
Picture::Picture(int cap){
capacity = cap;
    count = 0;
    array = new void*[capacity];
    types = new bool[capacity];
}

void Picture::addLine(int x1,int y1,int x2,int y2){
 if(count<capacity){
    array[count]=new Line(x1,y1,x2,y2);
    types[count]=0;
 count++;
 }

}



void Picture::addCircle(int x1,int y1,int reduis){
 if(count<capacity){
    array[count]=new Circle(x1,y1,reduis);
    types[count]=1;
 count++;
 }

}

void Picture::draw(){
    for(int i=0;i<count;i++){
        if(types[0]){
            ((Line *)array[i])->draw();
        }else ((Circle *)array[i])->draw();
    }
}

Picture::~Picture(){
  for(int i=0;i<count;i++){
    if(types[0]){
        delete  ((Line *)array[i]);
    }else{
        delete  ((Circle *)array[i]);
    }

  }
  delete[] array;
  delete [] types;
}
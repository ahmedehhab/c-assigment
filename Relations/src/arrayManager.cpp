#include "../header/shape.h"
#include "../header/arrayManager.h"

void resize(Shape**& shapes, int& capacity, int size) {
    int newCapacity = capacity * 2;
    Shape** temp = new Shape*[newCapacity];
    for (int i = 0; i < size; i++)
        temp[i] = shapes[i];
    delete[] shapes;
    shapes = temp;       
    capacity = newCapacity; 
}

void addShape(Shape**& shapes ,Shape*& obj,int& capacity, int index){
  
  if(index==capacity)resize(shapes,capacity,index);
   shapes[index++]=obj;
}
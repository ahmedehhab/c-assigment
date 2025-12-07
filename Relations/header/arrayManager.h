#include "../header/shape.h"
#ifndef ARRAY_MANAGER_H
#define ARRAY_MANAGER_H
void resize(Shape**& shapes, int& capacity, int size);

void addShape(Shape**& shapes ,Shape*& obj,int& capacity, int &index);
#endif
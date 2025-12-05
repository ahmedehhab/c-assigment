#include "../header/dynamic_list.h"
#include <iostream>
using namespace std;

DynamicList::DynamicList(int cap) {
    capacity = cap;
    length = 0;
    arr = new basetype*[capacity];
}

DynamicList::DynamicList(const DynamicList& other) {
    capacity = other.capacity;
    length = other.length;
    arr = new basetype*[capacity];

    for (int i = 0; i < length; i++)
        arr[i] = other.arr[i];   // shallow copy
}

DynamicList& DynamicList::operator=(const DynamicList& other) {
    if (this == &other) return *this;

    delete[] arr;

    capacity = other.capacity;
    length = other.length;

    arr = new basetype*[capacity];
    for (int i = 0; i < length; i++)
        arr[i] = other.arr[i];

    return *this;
}

DynamicList::~DynamicList() {
    for (int i = 0; i < length; i++)
        delete arr[i];
    delete[] arr;
}

void DynamicList::expand() {
    capacity *= 2;
    basetype** newArr = new basetype*[capacity];

    for (int i = 0; i < length; i++)
        newArr[i] = arr[i];

    delete[] arr;
    arr = newArr;
}

void DynamicList::add(basetype* item) {
    if (length == capacity) expand();
    arr[length++] = item;
}

void DynamicList::removeAt(int index) {
    if (index < 0 || index >= length) return;

    delete arr[index];

    for (int i = index; i < length - 1; i++)
        arr[i] = arr[i + 1];

    length--;
}

basetype* DynamicList::operator[](int index) const {
    if (index < 0 || index >= length)
        throw out_of_range("Index out of range");

    return arr[index];
}

void DynamicList::print() const {
    cout << "[ ";
    for (int i = 0; i < length; i++) {
        arr[i]->print();
        if (i != length - 1) cout << ", ";
    }
    cout << " ]\n";
}

#ifndef __DYNAMIC_LIST_H__
#define __DYNAMIC_LIST_H__

#include "../header/base_type.h"

class DynamicList {
private:
    basetype** arr;
    int capacity;
    int length;

    void expand();

public:
    DynamicList(int cap = 10);
    DynamicList(const DynamicList& other);
    DynamicList& operator=(const DynamicList& other);
    ~DynamicList();

    void add(basetype* item);
    void removeAt(int index);
    basetype* operator[](int index) const;

    int size() const { return length; }
    void print() const;
};

#endif

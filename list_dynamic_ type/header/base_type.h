#ifndef __BASE_TYPE_H__
#define __BASE_TYPE_H__

#include <iostream>
#include <string>
using namespace std;

enum class TypeKind {
    INT,
    FLOAT,
    CHAR,
    STRING,
    BOOL
};

class basetype {
public:
    virtual ~basetype() {}
    virtual void print() = 0;
    virtual TypeKind getType() = 0;        
};



class Integer : public basetype {
private:
    int val;
public:
    Integer(int v);
    void print() override { cout << val; }
    TypeKind getType() override { return TypeKind::INT; }
};



class Float : public basetype {
private:
    float val;
public:
    Float(float v);
    void print() override { cout << val; }
    TypeKind getType() override { return TypeKind::FLOAT; }
};



class Character : public basetype {
private:
    char val;
public:
    Character(char v);
    void print() override { cout << val; }
    TypeKind getType() override { return TypeKind::CHAR; }
};



class String : public basetype {
private:
    string val;
public:
    String(string v);
    void print() override { cout << val; }
    TypeKind getType() override { return TypeKind::STRING; }
};



class Boolean : public basetype {
private:
    bool val;
public:
    Boolean(bool v);
    void print() override { cout << (val ? "true" : "false"); }
    TypeKind getType() override { return TypeKind::BOOL; }
};



basetype* detectType(const string& input);
ostream& operator<<(ostream& os, basetype& b);

#endif

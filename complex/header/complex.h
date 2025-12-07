#include <iostream>
using namespace std;
#ifndef COMPLEX_H
#define COMPLEX_H
class Complex
{
private:
    double real;
    double imag;
public:
   Complex(); //set real =0 and imag =0
   Complex(double real);
   Complex(double real,double imag);

   void setReal(double real );
   void setImag(double imag);

   double getReal();
   double getImag();

    Complex& operator =(const Complex &c); // assigment

    //arithmetic operators
    Complex operator + (const Complex &c)const;
    Complex operator - (const Complex &c)const;
    Complex operator * (const Complex &c)const;
    Complex operator / (const Complex &c)const;

   
    
    
    //compound operators
    Complex& operator += (const Complex &c);
    Complex& operator -= (const Complex &c);
    Complex& operator *= (const Complex &c);
    Complex& operator /= (const Complex &c);
     operator double() const;
     operator int() const;
     operator string()const;
    
    //unary operator 
    Complex& operator ++(); //++c;
    Complex& operator --(); //--c;
    Complex operator ++(int); //c++;
    Complex operator --(int); //c--;
    Complex& operator -();   //-c
    Complex& operator +();  //+c 
    
    
    
    //comparesson operators 
    bool operator ==(const Complex &c)const;
    bool operator !=(const Complex &c)const;
    bool operator<(const Complex& c) const;   
    bool operator<=(const Complex& c) const;
    bool operator>(const Complex& c) const;
    bool operator>=(const Complex& c) const;

    double operator[](int index);
    
    
};




#endif
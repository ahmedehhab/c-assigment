#include "../header/complex.h"

Complex::Complex(){
    this->real=0;
    this->imag=0;
}
Complex::Complex(double real){
    this->real=real;
    this->imag=0;
}
Complex::Complex(double real , double imag){
    this->real=real;
    this->imag=imag;
}


void Complex::setReal(double real){
    this->real=real;
}
void Complex::setImag(double imag){
    this->imag=imag;
}


double Complex::getImag(){
    return this->imag;
}
double Complex::getReal(){
    return this->real;
}



Complex& Complex::operator =(const Complex &c){
    this->real=c.real;
    this->imag=c.imag;
    return *this;
}


 Complex Complex::operator + (const Complex &c)const{
    Complex res;
    res.real= c.real + this->real;
    res.imag= c.imag + this->imag;
    return res;

 };

 Complex Complex::operator - (const Complex &c)const{
     Complex res;
    res.real= c.real - this->real;
    res.imag= c.imag - this->imag;
    return res;

 };
 Complex Complex::operator * (const Complex &c)const{
      Complex res;
    res.real= c.real * this->real;
    res.imag= c.imag * this->imag;
    return res;

 };
 Complex Complex::operator / (const Complex &c)const{
      Complex res;
    res.real= c.real / this->real;
    res.imag= c.imag / this->imag;
    return res;

 };



    Complex& Complex:: operator += (const Complex &c){
        this->real+=c.real;
        this->imag+=c.imag;
        return *this;

    };
    Complex& Complex:: operator -= (const Complex &c){
          this->real-=c.real;
          this->imag-=c.imag;
        return *this;
    };
    Complex& Complex:: operator *= (const Complex &c){
          this->real*=c.real;
          this->imag*=c.imag;
        return *this;
    };
    Complex& Complex:: operator /= (const Complex &c){
          this->real/=c.real;
          this->imag/=c.imag;
        return *this;
    };


    //++c;
    Complex& Complex::operator ++(){
        this->real+=1;
        this->imag+=1;
        return *this;

    }; 

    //--c;
    Complex& Complex::operator --(){
        this->real-=1;
        this->imag-=1;
        return *this;
    }; 

    //c++;
    Complex Complex::operator ++(int){
        Complex temp;
        temp=*this;
        this->real+=1;
        this->imag+=1;
        return temp;

    }; 

    //c--;
    Complex Complex::operator --(int){
        Complex temp;
        temp=*this;
        this->real-=1;
        this->imag-=1;
        return temp;
    }; 

    //-c
    Complex& Complex::operator -(){
         this->real*=-1;
         this->imag*=-1;
         return *this;
    }; 
    
    //+c 
    Complex& Complex::operator +(){
       return *this;
    };  



    bool Complex::operator ==(const Complex &c)const{
        return (this->real==c.real && this->imag==c.imag);

    };

    bool Complex::operator !=(const Complex &c)const{
        return !(this->real==c.real && this->imag==c.imag);
    };

    bool Complex::operator<(const Complex& c) const{
        return (this->real<c.real && this->imag<c.imag);
    };

    bool Complex::operator<=(const Complex& c) const{
        return (this->real<=c.real && this->imag<=c.imag);
    };

    bool Complex::operator>(const Complex& c) const{
        return (this->real>c.real && this->imag>c.imag);
    };

    bool Complex::operator>=(const Complex& c) const{
        return (this->real>=c.real && this->imag>=c.imag);
    };

    double Complex::operator[](int index){
        if(index==0)return this->real;
         if(index==1)return this->imag;
        throw std::string("out of bound");
    }
#include "../header/string.h"
#include <iostream>
using namespace std;
#define SIZE_OF_STRING 100
int String::str_len(const char arr[])const{
    int i=0;
    while(arr[i]!='\0'){
        i++;
    }
    return i;

}


void String::reSizeArray(){
     this->capacity*=2;
     char * temp=new char[this->capacity];
     for(int i=0;i<length;i++){
        temp[i]=this->arr[i];
     }
     temp[length]='\0';
     delete []this->arr;
     this->arr=temp;
}

void String::swap_char( char &a , char &b){
        a ^= b;
        b ^= a;
        a ^= b;
}

String::String(){
    this->capacity=SIZE_OF_STRING; 
    this->length=0;
    this->arr=new char[this->capacity];
    this->arr[0] = '\0';
}



String::String(const char *s){
    this->capacity=SIZE_OF_STRING;
 if(s==nullptr){
    this->length=0;
    this->arr=new char[this->capacity];
    this->arr[0] = '\0';
 }else{
    this->length=str_len(s);
    if(this->length>=this->capacity)this->capacity=this->length*2;
  
   this->arr=new char[this->capacity];    
    for(int i=0;i<length;i++){
        this->arr[i]=s[i];
    }
    this->arr[length] = '\0';
   
 }

}


String::String(const String &s){
this->capacity=s.capacity;
this->length=s.length;
 this->arr=new char[this->capacity];
for(int i=0;i<=length;i++){
  this->arr[i]=s.arr[i];
}

}


String::String(String &&s){
    this->capacity=s.capacity;
    this->length=s.length;
    this->arr=s.arr;

    s.arr=nullptr;
    s.capacity=0;
    s.length=0;
}

String::~String(){
    delete []arr;
}


String& String::operator=(const String &s){
    if(this==&s)return *this;
  this->capacity=s.capacity;
  this->length=s.length;
  delete []this->arr;
  this->arr=new char[this->capacity];
  for(int i=0;i<this->length;i++){
    this->arr[i]=s.arr[i];
  }
  this->arr[length]='\0';
  return *this;
    
}

String& String:: operator=(String&& s){
    if(&s==this) return *this;
    this->capacity=s.capacity;
    delete[] this->arr;
    this->arr=s.arr;
    this->length=s.length;
     s.arr=nullptr;
     s.length=0;
     s.capacity=0;
     return *this;
}

String& String::operator=(const char* s){
    if(s==nullptr) s="";
    this->length=str_len(s);
    this->capacity=this->length*2 +1;
    delete[] this->arr;
    this->arr=new char[this->capacity];
    for(int i=0;i<length;i++) this->arr[i]=s[i];
    this->arr[length]='\0';
    return *this;

}

String& String::operator +=(const char *s){
    if(s==nullptr) s="";
    int str_length=str_len(s);
    int merege_length=this->length+str_length;
    // case if the capacity is not avaliable
    if(merege_length+1 >= capacity){

        this->capacity=(merege_length +1)*2;

        char * temp=new char[this->capacity];

        for(int i=0;i<this->length;i++){
            temp[i]=this->arr[i];
        }

        
        delete[] this->arr;
        this->arr=temp;
    }

    for(int i=0;i<str_length;i++){
        this->arr[length++]=s[i];
    }
       this->arr[length]='\0';
    return *this;


}

String&  String::operator +=(const String &s){
    int mergedLength=s.length+this->length;
    if(this->capacity<=mergedLength + 1){
       this->capacity=(mergedLength +1)*2;

       char * temp=new char[this->capacity];

       for(int i=0;i<this->length;i++){
        temp[i]=this->arr[i];
       }

       delete []this->arr;
       this->arr=temp;

    }

    for(int i=0;i<s.length;i++){
        this->arr[this->length++]=s.arr[i];
    }
    this->arr[this->length]='\0';
    return * this;
}

String& String::operator+=(char c){
    if(this->length+1>=this->capacity) this->reSizeArray();
    this->arr[this->length++]=c;
    this->arr[this->length]='\0';
    return *this;
    
}

String String::operator+(const char* s) const {
    String temp;
    temp+=*this;
    temp+=s;
    return temp;
}

String String::operator+(const String& s) const {
    String temp=*this;
    temp+=s;
    return temp;
}

String operator+(const char* c, const String& s){
    String temp = c;
    temp += s;
    return temp;
}

bool String:: operator==(const String& s) const{
    for(int i=0;i<this->length;i++){
        if(this->arr[i]!=s.arr[i])return false;
    }
    return true;
}
bool String:: operator!=(const String& s) const{
 for(int i=0;i<this->length;i++){
        if(this->arr[i]!=s.arr[i])return true;
    }
    return false;
}
bool String:: operator>(const String& s) const{
    for(int i=0;i<this->length;i++){
        if(this->arr[i]>s.arr[i])return true;
    }
    return false;
}
bool String:: operator<(const String& s) const{
    for(int i=0;i<this->length;i++){
        if(this->arr[i]<s.arr[i])return true;
    }
    return false;
}
bool String:: operator>=(const String& s) const{
    for(int i=0;i<this->length;i++){
        if(this->arr[i]>=s.arr[i])return true;
    }
    return false;
}
bool String:: operator<=(const String& s) const{
    for(int i=0;i<this->length;i++){
        if(this->arr[i]<=s.arr[i])return true;
    }
    return false;
}

char& String::operator[](int index){
    if(index>=this->length) throw std::runtime_error("out of bound");
    return this->arr[index];
}



int String::size(){
    return this->length;
}

bool String::isEmpty(){
    return (this->length==0);
}

void String::clear(){
    this->length=0;
    this->arr[0]='\0';
}

void String::display(){

    for(int i=0;i<this->length;i++)cout<<this->arr[i];
}


char String::front() {
    if(this->isEmpty())throw std::runtime_error("the string is empty");
    return this->arr[0];
}

char String::back(){
    if(this->isEmpty())throw std::runtime_error("the string is empty");
    return this->arr[this->length -1];
}


void String::push_back(const char &s){
  if(length+1>=capacity)reSizeArray();
  this->arr[length]=s;
  length++;
  this->arr[length] = '\0';
}

void String::pop_back(){
    if(this->isEmpty())throw std::runtime_error("the string is empty");
     this->arr[this->length--]='\0';
}

void String::insert(int pos, const char * s){

    if (pos < 0||pos > this->length) {
        throw std::out_of_range("Insert position out of bounds");
    }

    if (s == nullptr) s = "";

    int newIndex=pos;
    int str_length=str_len(s);
    int merged_length=str_length+this->length;

   int newCapacity = capacity;
    if (merged_length + 1 > capacity) {
        newCapacity = (merged_length + 1) * 2;
    }

 char *temp=new char[newCapacity];

 for(int i=0;i<newIndex;i++){
     temp[i]=this->arr[i];
 }
  
 for(int i=0;i<str_length;i++){
    temp[newIndex++]=s[i];
 }
 for(int i=pos;i<this->length;i++){
    temp[newIndex++]=this->arr[i];
 }
 delete [] this->arr;
 this->arr=temp;
 this->arr[newIndex]='\0';
 this->capacity=newCapacity;
 this->length=merged_length;
}


void String::erase(int from ,int to ){
 if(from>=this->length || to >=this->length ||from<0 ||to<0 ) throw std::runtime_error("this range is out of boud ");

  int count =(to-from )+1;
  for(int i=to+1;i<this->length;i++){
    this->arr[i-count]=this->arr[i];
  }
  this->length-=count;
  this->arr[this->length]='\0';  
}

String String::substr(int from, int to) const{
 if(from>=this->length || from<0 ||to>this->length ||to<0) throw std::runtime_error("this range is out of boud ");
 String temp;
 for(;from<=to;from++)temp+=this->arr[from];
 return temp;

}


bool String::include(const char * c)const{
    int length_c =str_len(c);
    if(length_c>this->length)return false;
     for(int i=0;i<this->length - length_c;i++){
        bool equal=true;
        if(this->arr[i]==c[0]){
            for(int j=0;j<length_c && equal;j++){
                if(c[j]!=this->arr[i+j]) equal=false;
            }
            if(equal)return true;
        }
     }

return false;
}



void String::reverse(){
    int i=0 ,j=this->length-1;
    while(i<j){
      swap_char(this->arr[i],this->arr[j]);
      i++;j--;
    }

}

void String::swap(String &a,String &b){
    char *temp =nullptr;
    temp=a.arr;
    a.arr=b.arr;
    b.arr=temp;

}

bool String::isPalindrome()const{
    int i=0, j=this->length-1;
    while (i<j)
    {
        if(this->arr[i]!=this->arr[j])return false;
        i++;
        j--;
    }
    return true;
}

   ostream& operator<<(ostream& out,  const String& s) {
    for (int i = 0; i < s.length; i++) {
        out << s.arr[i];
    }
    return out;
}

  istream& operator>>( istream& in, String& s) {
    s.clear();  
    char temp[1024];  
    in >> temp;       
    s = temp;        
    return in;
}
#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;
class String{
private :
int capacity;
int length;
char *arr;
int str_len(const char arr[])const;
void reSizeArray();
void swap_char( char &a , char &b);
public: 
String();
String(const char *s);
~String();
String(const String &s);
String ( String &&s);

void display();
 
String& operator =(const String &s);
String& operator=(String&& s);
String& operator=(const char* s);
String& operator +=(const char *s);
String& operator +=(const String &s);
String& operator+=(char c);
String operator+(const char* s) const;
String operator+(const String& s) const;
friend String operator+(const char* c, const String& s);
char& operator[](int index);

bool operator==(const String& s) const;
bool operator!=(const String& s) const;
bool operator>(const String& s) const;
bool operator<(const String& s) const;
bool operator>=(const String& s) const;
bool operator<=(const String& s) const;

int size();
bool isEmpty();
void clear();

char front() ;
char back() ;


void push_back(const char &s);
void pop_back();
void insert(int pos, const char * s);
void erase(int from ,int to);
void reverse();
void swap(String &a,String &b);
String substr(int from , int to) const;
bool include (const char * s) const;
bool isPalindrome()const;
friend  ostream& operator<<( ostream& out,  const String& s);
friend istream& operator>>( istream& in,  String& s);

};



#endif
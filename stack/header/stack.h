#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;
template<class T>

class Stack{
private:
 T *arr;
 int capacity;
 int tos;
public:
Stack();
Stack(const Stack &s);
Stack( Stack &&s);

T top();
void push(T s);
void pop();
bool empty();
int size();
void clear();

Stack<T>& operator=(const Stack<T> &s);
Stack<T>& operator=( Stack<T> &&s);

~Stack();

};

template <class T>
Stack<T>::Stack(){
    this->capacity=20;
   this->arr=new T[this->capacity];
   this-> tos=-1;
}
template <class T>
void Stack<T>::push(T s){
    if(this->tos+1 == this->capacity){
        this->capacity*=2;
         T *temp=new T[this->capacity];
         for(int i=0;i<=this->tos;i++)
        temp[i]=this->arr[i];
        delete [] arr;
        arr=temp;
    }
    tos++;
    arr[tos]=s;

}

template<class T>
Stack<T>::Stack(const Stack<T>& s) {
   this-> capacity = s.capacity;
   this-> tos = s.tos;
   this-> arr = new T[this->capacity];
    for (int i = 0; i <= s.tos; i++)
       this-> arr[i] = s.arr[i];
}


template <class T>
Stack<T>::~Stack(){
    delete [] this->arr;
}


template<class T>
T Stack<T>::top(){
    if(empty()) throw runtime_error("Stack is empty");
    return arr[this->tos];
}

template<class T>
void Stack<T>::pop(){
  if(this->tos!=-1){ tos--;
   } else throw runtime_error("Stack is empty");
}

template<class T>
bool Stack<T>::empty(){
    return (this->tos==-1);
}

template<class T>
int Stack<T>::size(){
      if(this->tos==-1)return 0;
      return this->tos +1;
}
template<class T>
void Stack<T>::clear(){
    this->tos=-1;
}


template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& s)
{
   
if (this == &s) return *this;  // if s=s
    delete[] this->arr;         

    this->capacity = s.capacity;
    this->tos = s.tos;

    this->arr = new T[this->capacity];

    for (int i = 0; i <= s.tos; i++)
       this-> arr[i] = s.arr[i];

    return *this;
}

template<class T>
Stack<T>::Stack(Stack<T> &&s){
    this->capacity=s.capacity;
    this->tos=s.tos;
    this->arr=s.arr;
    s.arr=nullptr;

}

template<class T>
Stack<T>& Stack<T>::operator=(Stack<T>&& s)  {
    if (this != &s) {
        delete[] this->arr;

        this->arr = s.arr;
        this->capacity = s.capacity;
        this->tos = s.tos;

        s.arr = nullptr;
       
    }
    return *this;
}

#endif
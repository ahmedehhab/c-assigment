#include<iostream>
#include "../header/arr.h"
using namespace std;
int * creatArray(int rows,int cols){
    int * arr=new int [rows*cols];

    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<"enter number";
            cin>>arr[i*cols +j];
        }
    }

    return arr;
}
void printArray(int * arr,int rows,int cols){
 for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<arr[i*cols +j]<<' ';
        }
        cout<<'\n';
    }
}
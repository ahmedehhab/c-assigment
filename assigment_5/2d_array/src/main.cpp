#include <iostream>
#include "../header/arr.h"
using namespace std;


int main(){

    int rows,cols;
    cout<<"enter the number of rows ";
    cin>>rows;
    cout<<"enter the number of coulmns";
    cin>>cols;

    if(rows<0 || cols<0){
         cout<<"rows and cols must be postive";
         return 1;
    }

       int *arr=creatArray(rows,cols);      
    
       printArray(arr,rows,cols);
    
delete[] arr;

    return 0;
}
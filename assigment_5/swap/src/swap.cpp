#include "../header/swap.h"
void swap_using_add(int &x,int &y){
    x+=y;
    y=x-y;
    x-=y;
    
}
void swap_using_mul(int &x,int &y){
    x*=y;
    y=x/y;
    x/=y;
}

void swap_using_xor(int &x,int &y){
    x^=y;
    y=x^y;
    x^=y;
}
#include <iostream>
#include "../header/swap.h"
using namespace std;

int main(){
  
    int x=3;
    int y=4;
  swap_using_add(x,y);
  cout<<x<<' '<<y<<'\n';
  swap_using_mul(x,y);
  cout<<x<<' '<<y<<'\n';
  swap_using_xor(x,y);
  cout<<x<<' '<<y<<'\n';
  

    return 0;
}
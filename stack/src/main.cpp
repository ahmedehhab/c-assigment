#include <iostream>
#include "../header/stack.h"
using namespace std;

Stack<int> oneStack(){
   Stack<int>s;
   s.push(1);
   return s;
}
int main(){
    Stack<int> s,b;
     for(int i=0;i<100;i++){
        s.push(i);
        // cout<<s.top()<<'\n';
     }

     for(int i=200;i<300;i++){
        b.push(i);
        // cout<<s.top()<<'\n';
     }
    //  for(int i=0;i<10;i++)s.pop();
    // cout<<s.size()<<'\n';
    //  cout<<s.empty()<<'\n';
    //  s.clear();
    //       cout<<s.empty()<<'\n';

    //  cout<<s.size();

    s=b;
    cout<<s.top()<<" "<<b.top()<<'\n';

    s= oneStack();
    cout<<s.top();
    return 0;
}
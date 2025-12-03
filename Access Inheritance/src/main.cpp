#include <iostream>
#include "../header/circle.h"
#include "../header/rect.h"
#include "../header/square.h"
#include "../header/triangle.h"
using namespace std;
int main(){

    Circle c(50);
    cout<<c.area()<<'\n';

    Square s(10);
    cout<<s.area()<<'\n';

    Triangle t(10,20);
    cout<<t.area()<<'\n';

    Rect r(100,50);
    cout<<r.area()<<'\n';


    return 0;
}
#include "../header/termfx.h"
#include <iostream>
int main() {
    
    printAt(5, 2,  "AHMED EHAB", Color::Red);
    printAt(10, 4, "AHMED EHAB", Color::Green);
    printAt(15, 6, "AHMED EHAB", Color::Blue);
    printAt(0,  8, "AHMED EHAB", Color::BrightYellow);
    delay(3000);
    clear();
    return 0;
}

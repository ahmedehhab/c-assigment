#include "../header/termfx.h"
#include <iostream>
using namespace std;

void getPosition(int num, int n, int& row, int& col) {
    
    int idx = num - 1; 
    
    row = 0;
    col = n / 2;
    
    for (int i = 1; i < num; i++) {
    
        int newRow = (row - 1 + n) % n;
        int newCol = (col - 1 + n) % n;
        
        if (i % n == 0) {
            row = (row + 1) % n;
        } else {
            row = newRow;
            col = newCol;
        }
    }
}

int main() {
    int n;
    cout << "Enter odd number for magic square: ";
    cin >> n;

    if (n <= 0 || n % 2 == 0) {
        clear();
        printAt(5, 3, "Magic square must be a positive odd number!", Color::Red);
        delay(2000);
        return 0;
    }

    clear();

    int startRow = 3;
    int startCol = 10;
    int spacing = 5;

    setColor(Color::BrightBlack);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            moveCursor(startCol + j * spacing, startRow + i);
            cout << ".";
        }
    }
    resetColor();

    for (int num = 1; num <= n * n; num++) {
        int r, c;
        getPosition(num, n, r, c);
        
        moveCursor(startCol + c * spacing, startRow + r);
        setColor(Color::BrightCyan);
        cout << num;
        resetColor();
        cout.flush();
        
        delay(500);
    }

  cout<<'\n';
    
    return 0;
}
#include "../header/ui_screens.h"
#include "../header/array_manager.h"
#include "../header/termfx.h"
#include <iostream>
#include <cstring>

bool valid_str(const char* field, int currentRow, const char* error_message, int labelLength) {
    // Check if empty
    if (strlen(field) == 0) {
        return false;
    }
    
    // Check if has at least one letter
    bool hasLetter = false;
    for (int i = 0; i < strlen(field); i++) {
        char c = field[i];
        // Allow letters (both upper and lower), spaces, hyphens, apostrophes
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            hasLetter = true;
        } else if (c != ' ') {
            // Invalid character found
            printAt(FORM_LEFT_MARGIN, currentRow + 1, error_message, Color::Red);
            delay(2000);
            return false;
        }
    }
    
    // Must have at least one letter
    if (!hasLetter) {
        printAt(FORM_LEFT_MARGIN, currentRow + 1, error_message, Color::Red);
        delay(2000);
        return false;
    }
    
    return true;
}

bool valid_salary(const char* salaryInput, int currentRow) {
    // Check if it's a valid number
    bool hasDigit = false;
    bool hasDecimal = false;
    
    for (int i = 0; i < strlen(salaryInput); i++) {
        char c = salaryInput[i];
        
        if (c >= '0' && c <= '9') {
            hasDigit = true;
        } else if (c == '.') {
            if (hasDecimal) {
                printAt(FORM_LEFT_MARGIN, currentRow + 1, 
                       "Error: Invalid number format!", Color::Red);
                delay(2000);
                return false;
            }
            hasDecimal = true;
        } else if (c != ' ') {
            printAt(FORM_LEFT_MARGIN, currentRow + 1, 
                   "Error: Enter valid number!", Color::Red);
            delay(2000);
            return false;
        }
    }
    
    if (!hasDigit) {
        printAt(FORM_LEFT_MARGIN, currentRow + 1, 
               "Error: Enter valid number!", Color::Red);
        delay(2000);
        return false;
    }
    
    // Check if positive
    double salary = atof(salaryInput);
    if (salary <= 0) {
        printAt(FORM_LEFT_MARGIN, currentRow + 1, 
               "Error: Salary must be greater than 0!", Color::Red);
        delay(2000);
        return false;
    }
    
    return true;
}

void addScreen(Employee*& employees, int& employeeCount, int& arrayCapacity, int& nextId) {
    clear();
    showCursor();
    
    int width = getConsoleWidth();
    
    const char* title = "=== ADD NEW EMPLOYEE ===";
    int titleX = (width - strlen(title)) / 2;
    printAt(titleX, TITLE_ROW, title, Color::BrightCyan);
    
    // Show cancel hint
    printAt(FORM_LEFT_MARGIN, TITLE_ROW + 1, 
            "Leave empty and press Enter to cancel", 
            Color::BrightBlack);
    
    Employee emp;
    emp.id = nextId;
    
    moveCursor(FORM_LEFT_MARGIN, FORM_START_ROW);
    setColor(Color::Green);
    std::cout << "ID: " << emp.id;
    resetColor();
    
    int currentRow = FORM_START_ROW + FORM_LINE_SPACING;
    
    // Input Name
    printAt(FORM_LEFT_MARGIN, currentRow, "Name: ", Color::Green);
    std::cin.getline(emp.name, MAX_NAME_LENGTH);
    
    // Check for cancel (empty input)
    if (strlen(emp.name) == 0) {
        hideCursor();
        return;
    }
    
    // Validate name
    if (!valid_str(emp.name, currentRow, "Error: Enter valid name with letters!", 6)) {
        hideCursor();
        return;
    }
    
    currentRow += FORM_LINE_SPACING;
    
    // Input Position
    printAt(FORM_LEFT_MARGIN, currentRow, "Position: ", Color::Green);
    std::cin.getline(emp.position, MAX_POSITION_LENGTH);
    
    // Check for cancel (empty input)
    if (strlen(emp.position) == 0) {
        hideCursor();
        return;
    }
    
    // Validate position
    if (!valid_str(emp.position, currentRow, "Error: Enter valid position with letters!", 10)) {
        hideCursor();
        return;
    }
    
    currentRow += FORM_LINE_SPACING;
    
    // Input Salary
    printAt(FORM_LEFT_MARGIN, currentRow, "Salary: ", Color::Green);
    
    char salaryInput[MAX_NAME_LENGTH];
    std::cin.getline(salaryInput, MAX_NAME_LENGTH);
    
    // Check for cancel (empty input)
    if (strlen(salaryInput) == 0) {
        hideCursor();
        return;
    }
    
    // Validate salary
    if (!valid_salary(salaryInput, currentRow)) {
        hideCursor();
        return;
    }
    
    emp.salary = atof(salaryInput);
    
    // Add employee
    addEmployee(employees, employeeCount, arrayCapacity, emp);
    nextId++;
    
    currentRow += FORM_LINE_SPACING + 1;
    printAt(FORM_LEFT_MARGIN, currentRow, "Employee added successfully!", Color::BrightGreen);
    
    delay(SUCCESS_DISPLAY_DELAY);
    
    hideCursor();
    showBackButton();
}

void displayScreen(Employee* employees, int employeeCount, int arrayCapacity) {
    clear();
    
    int width = getConsoleWidth();
    
    const char* title = "=== ALL EMPLOYEES ===";
    int titleX = (width - strlen(title)) / 2;
    printAt(titleX, TITLE_ROW, title, Color::BrightCyan);
    
    if (employeeCount == 0) {
        printAt(FORM_LEFT_MARGIN, FORM_START_ROW, "No employees found!", Color::Red);
    } else {
        printAt(COL_ID, TABLE_HEADER_ROW, "ID", Color::BrightYellow);
        printAt(COL_NAME, TABLE_HEADER_ROW, "Name", Color::BrightYellow);
        printAt(COL_POSITION, TABLE_HEADER_ROW, "Position", Color::BrightYellow);
        printAt(COL_SALARY, TABLE_HEADER_ROW, "Salary", Color::BrightYellow);
        
        printAt(COL_ID, TABLE_SEPARATOR_ROW, 
                std::string(SEPARATOR_LENGTH, '-'), 
                Color::BrightBlack);
        
        int row = TABLE_DATA_START_ROW;
        for (int i = 0; i < employeeCount; i++) {
            Employee& emp = employees[i];
            
            moveCursor(COL_ID, row);
            setColor(Color::White);
            std::cout << emp.id;
            
            printAt(COL_NAME, row, emp.name, Color::White);
            printAt(COL_POSITION, row, emp.position, Color::White);
            
            moveCursor(COL_SALARY, row);
            setColor(Color::White);
            std::cout << "$" << emp.salary;
            resetColor();
            
            row += TABLE_ROW_SPACING;
        }
        
        row += 1;
        moveCursor(COL_ID, row);
        setColor(Color::BrightGreen);
        std::cout << "Total Employees: " << employeeCount;
        resetColor();
        
        moveCursor(COL_ID, row + 1);
        setColor(Color::BrightBlack);
        std::cout << "Array Capacity: " << arrayCapacity;
        resetColor();
    }
    
    std::cout.flush();
    showBackButton();
}
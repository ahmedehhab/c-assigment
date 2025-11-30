#ifndef EMPLOYEE_H
#define EMPLOYEE_H

// Constants for Employee struct
#define MAX_NAME_LENGTH 50
#define MAX_POSITION_LENGTH 50

// Constants for dynamic array
#define INITIAL_CAPACITY 2
#define RESIZE_MULTIPLIER 2

// UI Layout Constants
#define TITLE_ROW 2
#define FORM_START_ROW 5
#define FORM_LEFT_MARGIN 5
#define FORM_LINE_SPACING 2
#define TABLE_HEADER_ROW 5
#define TABLE_SEPARATOR_ROW 6
#define TABLE_DATA_START_ROW 8
#define TABLE_ROW_SPACING 2

// Table Column Positions
#define COL_ID 5
#define COL_NAME 12
#define COL_POSITION 35
#define COL_SALARY 60

// Delay times in milliseconds
#define ERROR_DISPLAY_DELAY 1500
#define SUCCESS_DISPLAY_DELAY 1500

// Menu constants
#define MENU_CURSOR_OFFSET 3
#define MENU_SIZE 3

// Separator line length
#define SEPARATOR_LENGTH 64

// Clear line length for error messages
#define CLEAR_LINE_LENGTH 40
#define CLEAR_SALARY_INPUT_LENGTH 30

struct Employee {
    int id;
    char name[MAX_NAME_LENGTH];
    char position[MAX_POSITION_LENGTH];
    double salary;
};

#endif // EMPLOYEE_H
#ifndef UI_SCREENS_H
#define UI_SCREENS_H

#include "employee.h"

// Add employee screen
void addScreen(Employee*& employees, int& employeeCount, int& arrayCapacity, int& nextId);

// Display all employees screen
void displayScreen(Employee* employees, int employeeCount, int arrayCapacity);

#endif // UI_SCREENS_H
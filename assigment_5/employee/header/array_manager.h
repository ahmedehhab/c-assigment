#ifndef ARRAY_MANAGER_H
#define ARRAY_MANAGER_H

#include "employee.h"

// Function to resize the dynamic array
void resizeArray(Employee*& employees, int& arrayCapacity, int employeeCount);

// Add employee to dynamic array
void addEmployee(Employee*& employees, int& employeeCount, int& arrayCapacity, const Employee& emp);

#endif // ARRAY_MANAGER_H
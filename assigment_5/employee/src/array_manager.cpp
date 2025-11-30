#include "../header/array_manager.h"

void resizeArray(Employee*& employees, int& arrayCapacity, int employeeCount) {
    int newCapacity = (arrayCapacity == 0) ? INITIAL_CAPACITY : arrayCapacity * RESIZE_MULTIPLIER;
    Employee* newArray = new Employee[newCapacity];
    
    for (int i = 0; i < employeeCount; i++) {
        newArray[i] = employees[i];
    }
    
    delete[] employees;
    
    employees = newArray;
    arrayCapacity = newCapacity;
}

void addEmployee(Employee*& employees, int& employeeCount, int& arrayCapacity, const Employee& emp) {
    if (employeeCount >= arrayCapacity) {
        resizeArray(employees, arrayCapacity, employeeCount);
    }
    employees[employeeCount++] = emp;
}
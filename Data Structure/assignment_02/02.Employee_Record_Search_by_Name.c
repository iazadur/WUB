#include <stdio.h>
#include <string.h>

// Define the Employee structure
struct Employee {
    char name[50];
    int empID;
    char department[30];
};

// Function to search for an employee by name
void searchEmployee(struct Employee employees[], int n, char* name) {
    for (int i = 0; i < n; i++) {
        if (strcmp(employees[i].name, name) == 0) {
            printf("ID: %d, Department: %s\n", employees[i].empID, employees[i].department);
            return;
        }
    }
    printf("Employee not found.\n");
}

// Main function
int main() {
    // Initialize employee array
    struct Employee employees[] = {
        {"Alice", 101, "HR"},
        {"Bob", 102, "Engineering"},
        {"Charlie", 103, "Sales"}
    };
    
    // Employee name to search
    char nameToSearch[] = "Bob";
    searchEmployee(employees, 3, nameToSearch);  // Call search function
    return 0;
}

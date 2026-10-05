#include <stdlib.h>
#include "emp_stc.h"

int create_employee(Employee** table, size_t size, char* fname, char* lname, char* department){
    int min = 1;
    int max = 20000;

    int random_num = (rand() % (max - min +1)) + min;

    // Create employee
    Employee* new_employee = (Employee*)malloc(sizeof(Employee));

    if (new_employee == NULL) {return 1;}

    new_employee->ID = random_num;
    new_employee->fname = fname;
    new_employee->lname = lname;
    new_employee->department = department;

    for(size_t i=0; i < size; i++){
        if(*(table + i) != NULL){
            *(table + i) = new_employee;
            
            return 0;
        }
    }

    return 1;
}

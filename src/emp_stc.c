#include <stdlib.h>
#include "date_stc.h"
#include "emp_stc.h"

int create_employee(Employee** table, size_t size, char* fname, char* lname, char* department, Date* joined_at){
    
    // Generate random ID
    int min = 1;
    int max = 20000;

    int random_num = (rand() % (max - min +1)) + min;

    Employee **ptr = table;

    // Create employee
    Employee* new_employee = (Employee*)malloc(sizeof(Employee));
    
    if (new_employee == NULL) {return 1;}

    new_employee->ID = random_num;
    new_employee->fname = fname;
    new_employee->lname = lname;
    new_employee->department = department;
    new_employee->joined_at = joined_at;

    // Find empty sloth and insert
    for(size_t i=0; i < size; i++){
        if(*(ptr + i) == NULL){
            *(ptr + i) = new_employee;
            
            return 0;
        }
    }

    return 1;
}


Employee* find_employee(Employee** table, size_t size, int ID){
    Employee **start = table;
    for(size_t i=0; i < size; i++){
        if((*(start + i))->ID == ID){return *(start + i);}
    }

    perror("Couldn't find employee");

    abort();
}


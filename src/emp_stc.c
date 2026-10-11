#include <stdlib.h>
#include "date_stc.h"
#include "emp_stc.h"

static size_t emp_arr_size = 1;

Employee** create_employee(Employee** table, char* fname, char* lname, char* department, Date* joined_at){
    
    // Generate random ID
    int min = 1;
    int max = 20000;

    int random_num = (rand() % (max - min +1)) + min;

    // Create employee
    Employee* new_employee = (Employee*)malloc(sizeof(Employee));
    
    if (new_employee == NULL) {abort();}

    new_employee->ID = random_num;
    new_employee->fname = fname;
    new_employee->lname = lname;
    new_employee->department = department;
    new_employee->joined_at = joined_at;


    Employee** tmp = realloc(table, emp_arr_size * sizeof(Employee*));

    if(tmp == NULL){abort();}

    if((*(tmp + (emp_arr_size - 1)) = new_employee)){

        table = tmp;

        ++emp_arr_size;

        return table;
    }
    
    perror("Unable to create new employee");
    abort();
}


Employee* find_employee(Employee** table, int ID){
    Employee **tmp = table;
    for(size_t i=0; i < emp_arr_size; i++){
        if((*(tmp + i))->ID == ID){return *(tmp + i);}
    }

    perror("Couldn't find employee");

    abort();
}


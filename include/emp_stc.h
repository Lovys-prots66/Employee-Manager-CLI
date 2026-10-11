#include "date_stc.h"
#ifndef EMP_STC
#define EMP_STC

typedef struct{
    int ID;
    char* fname;
    char* lname;
    char* department;
    Date* joined_at;
} Employee;

Employee** create_employee(
    Employee** table, 
    char* fname, 
    char* lname, 
    char* department,
    Date* joined_at
);
Employee* find_employee(Employee** table, int ID); 
void display_employee(Employee* employee); 


#endif

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "date_stc.h"

Date* create_date(int year, int month, int day){
    Date* new_date = malloc(sizeof(Date));
    
    new_date->day = day;
    new_date->month = month;
    new_date->year = year;

    if(!validate_date(new_date)){
        free(new_date);
        new_date = NULL;      
        abort();
    }else{
        return new_date;
    }
}
char* format_date(Date* date){
    char* final_date = malloc(11 * sizeof(char));

    snprintf(final_date, 11, "%04d-%02d-%02d", date->year, date->month, date->day);

    return final_date;
}

bool validate_date(Date* date){
    if(
        !date->day &&
        !date->month &&
        !date->year 
    ){
        perror("Missing day, month or year!");
        return false;
    }

    if(!(0 < date->day && date->day <= 31)){
        perror("Invalid day");
        return false;
    }
    
    if(!(0 < date->month && date->month <= 12)){
        perror("Invalid month");
        return false;
    }

    if(!(2000 < date->year && date->year <= 2026)){
        perror("Invalid year");
        return false;
    }

    return true;
}

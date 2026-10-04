#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "date_stc.h"

char* format_date(Date* date){
    char* final_date = malloc(11 * sizeof(char));

    snprintf(final_date, 11, "%04d-%02d-%02d", date->year, date->month, date->day);

    return final_date;
}

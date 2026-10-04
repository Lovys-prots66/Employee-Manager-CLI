#include <stdbool.h>
#ifndef DATE_STC
#define DATE_STC

typedef struct{
    int day;
    int month;
    int year;
} Date;

bool validate_date(Date* date);
char* format_date(Date* date);

#endif

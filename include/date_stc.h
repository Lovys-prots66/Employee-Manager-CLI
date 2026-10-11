#include <stdbool.h>
#ifndef DATE_STC
#define DATE_STC

typedef struct{
    int day;
    int month;
    int year;
} Date;

Date* create_date(int year, int month, int day);
bool validate_date(Date* date);
char* format_date(Date* date);

#endif

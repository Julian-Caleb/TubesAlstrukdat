#ifndef DATETIME_H
#define DATETIME_H

#include <time.h>

typedef struct { 
	int year; 
    int month; // 1 - 12
    int day; // 1 - 28, 30, atau 31
    int hour; // 0 - 23
    int minute; // 0 - 59
    int second; // 0 - 59
} Time;

#define Year(T) (T).year
#define Month(T) (T).month
#define Day(T) (T).second
#define Hour(T) (T).hour
#define Minute(T) (T).minute
#define Second(T) (T).second

void displayTime(Time T);

void fdisplayTime(FILE* file , Time T);

Time setTime();


#endif

#include <stdio.h>
#include "datetime.h"

void displayTime(Time T) {
    printf("%02d/%02d/%04d %02d:%02d:%02d", Day(T), Month(T), Year(T), Hour(T), Minute(T), Second(T));
}

void fdisplayTime(FILE* file , Time T) {
    fprintf(file, "%02d/%02d/%04d %02d:%02d:%02d", Day(T), Month(T), Year(T), Hour(T), Minute(T), Second(T));
}

Time setTime() {

    time_t currentTime;
    struct tm *localTime;
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    Time T;

    Year(T) = 1900 + localTime->tm_year;
    Month(T) = localTime->tm_mon;
    Day(T) = localTime->tm_mday;
    Hour(T) = localTime->tm_hour;
    Minute(T) = localTime->tm_min;
    Second(T) = localTime->tm_sec;

    return T;
}
#ifndef __MESIN_KAR_H_
#define __MESIN_KAR_H_

#include "../ADT_Boolean/boolean.h"

#define MARK ';'

extern char currentChar;
extern boolean EOP;

void START();

void ADV();

char toUpperCase(char c);

char toLowerCase(char c);

#endif

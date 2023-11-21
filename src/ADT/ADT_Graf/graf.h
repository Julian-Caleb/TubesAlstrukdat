#ifndef GRAF_H
#define GRAF_H

#include "../ADT_Boolean/boolean.h"

#define CAP 20

typedef int Idx;
typedef int El;
typedef struct
{
   El mem[CAP][CAP];
   int length;
} Graf;

#define LENGTH(G) (G).length
#define ELEMENT(G, i, j) (G).mem[(i)][(j)]

void CreateGraf(Graf *g, int nPengguna);

void readGraf(Graf *g, int nPengguna);

void displayGraf(Graf g);

#endif

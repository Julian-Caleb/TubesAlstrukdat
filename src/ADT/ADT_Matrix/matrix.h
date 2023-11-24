#ifndef MATRIX_H
#define MATRIX_H

#include "../ADT_Boolean/boolean.h"

#define ROW_CAP 100
#define COL_CAP 100

typedef int IdxType;
typedef char ElType;
typedef struct
{
   ElType mem[ROW_CAP][COL_CAP];
   int rowEff;
   int colEff;
} Matrix;

#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

void createMatrix(int nRows, int nCols, Matrix *m);

void readMatrix(Matrix *m, int nRow, int nCol);

void displayMatrix(Matrix m);

void fdisplayMatrix(FILE* file,Matrix m);

#endif

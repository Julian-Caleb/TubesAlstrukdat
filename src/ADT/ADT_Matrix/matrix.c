#include <stdio.h>
#include "matrix.h"

void createMatrix(int nRows, int nCols, Matrix *m) {

    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;

}

void readMatrix(Matrix *m, int nRow, int nCol) {

    int i, j;
    char c;
    createMatrix(nRow, nCol, m);

    i = 0;
    while (i < nRow) {
        j = 0;
        while (j < nCol) {
            scanf("%c", &c);
            if (c != '\n' && c != ' ') {
                ELMT(*m, i, j) = c;
                j++;
            }
        }
        i++;
    }

}

void displayMatrix(Matrix m) {

    int i, j;

    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            printf("%c", ELMT(m, i, j));
            if (j < COL_EFF(m) - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

}

void fdisplayMatrix(FILE* file,Matrix m) {

    int i, j;

    for (i = 0; i < ROW_EFF(m); i++) {
        for (j = 0; j < COL_EFF(m); j++) {
            fprintf(file,"%c", ELMT(m, i, j));
            if (j < COL_EFF(m) - 1) {
                fprintf(file," ");
            }
        }
        fprintf(file,"\n");
    }

}

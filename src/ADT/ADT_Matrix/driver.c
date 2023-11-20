#include <stdio.h>
#include "matrix.h"

int main() {

    Matrix m;
    int nRow, nCol;

    scanf("%d", &nRow);
    scanf("%d", &nCol);

    readMatrix(&m, nRow, nCol);
    displayMatrix(m);

    return 0;

}
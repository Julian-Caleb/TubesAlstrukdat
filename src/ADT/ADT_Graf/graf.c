#include <stdio.h>
#include "graf.h"

void CreateGraf(Graf *g, int nPengguna) {

    LENGTH(*g) = nPengguna;

}

void readGraf(Graf *g, int nPengguna) {

    int i, j;
    CreateGraf(g, nPengguna);

    for (i = 0; i < LENGTH(*g); i++) {
        for (j = 0; j < LENGTH(*g); j++) {
            scanf("%d", &ELEMENT(*g, i, j));
        }
    }

}

void displayGraf(Graf g) {

    int i, j;

    for (i = 0; i < LENGTH(g); i++) {
        for (j = 0; j < LENGTH(g); j++) {
            printf("%d", ELEMENT(g, i, j));
            if (j < LENGTH(g) - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }


}

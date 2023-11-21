#include <stdio.h>
#include "graf.h"

int main() {

    int n;
    Graf g;

    scanf("%d", &n);

    readGraf(&g, n);
    displayGraf(g);

}
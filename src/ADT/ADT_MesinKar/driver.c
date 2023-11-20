#include <stdio.h>
#include "mesinkar.h"

int main() {

    START();
    while (currentChar != 'a') {
        printf("%c", currentChar);
        ADV();
    }

    return 0;

}
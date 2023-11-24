#include <stdio.h>
#include "mesinkata.h"

int main() {

    while (true) {

        STARTWORD();

        if (currentWord.TabWord[0] == 'a') {
            break;
        } else {
            printf("%d\n", ExtractInteger(currentWord));
        }

    }

    return 0;

}
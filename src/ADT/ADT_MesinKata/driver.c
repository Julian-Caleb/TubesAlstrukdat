#include <stdio.h>
#include "mesinkata.h"

int main() {

    while (true) {

        STARTWORD();

        if (currentWord.TabWord[0] == 'a') {
            break;
        } else {
            printWord(currentWord);
        }

    }

    return 0;

}
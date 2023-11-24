#include <stdio.h>
#include "mesintxt.h"

int main() {

    STARTSENTENCE();
    printf("Reading...\n");
    STARTTXT(currentWord);
    printWord(currentWord);

    ADVTXTWORD();
    printWord(currentWord);

    ADVTXTWORD();
    printWord(currentWord);

    CLOSETXT();

    // STARTSENTENCE();
    // printWord(currentWord);

    return 0;
}
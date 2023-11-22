#include <stdio.h>
#include "mesintxt.h"

int main() {

    STARTSENTENCE();
    STARTTXT(currentWord);
    printWord(currentWord);
    ADVTXTWORD();
    printWord(currentWord);
    printf("%c", currentChar);

    return 0;
}
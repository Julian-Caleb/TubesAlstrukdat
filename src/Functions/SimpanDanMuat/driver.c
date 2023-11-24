#include <stdio.h>
#include "muat.h"

int main() {

    STARTSENTENCE();
    printf("Reading file...\n");
    muat(currentWord);
    STARTSENTENCE();
    printWord(currentWord);


    return 0;

}
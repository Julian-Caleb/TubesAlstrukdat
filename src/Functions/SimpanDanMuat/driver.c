#include <stdio.h>
#include "simpandanmuat.h"

int main() {

    STARTWORD();
    printWord(currentWord);
    muat(currentWord);
    
    printWord(arrayOfProfile.buffer[0].username);

    return 0;

}
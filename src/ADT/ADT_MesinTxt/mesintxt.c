#include <stdio.h>
#include "./mesintxt.h"

static FILE *file;
static int retval;

void STARTTXT(Word fileName) {

    file = fopen(fileName.TabWord, "r");
    ADVTXT();
    if (currentChar == ENTER) {
        EndWord = true;
    } else {
        EndWord = false;
        COPYWORD();
    }

}

void ADVTXT() {

    retval = fscanf(file, "%c", &currentChar);

}

void ADVTXTWORD() {

    if (currentChar == ENTER) {
        while(currentChar == ENTER) {
            ADVTXT();
        }
    }
    COPYWORD();

}

void COPYWORD() {

    int i; 

    i = 0;
    while ((currentChar != ENTER) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADVTXT();  
        i++;
    }
    currentWord.TabWord[i] = '\0';
    currentWord.Length = i;    

}
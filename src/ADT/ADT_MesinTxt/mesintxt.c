#include <stdio.h>
#include "./mesintxt.h"

static FILE *file;
static int retval;

void STARTTXT(Word fileName) {

    file = fopen(fileName.TabWord, "r");
    if (file == NULL) {
        printf("File opening failed.\n");
    }
    ADVTXT();
    if (currentChar == ENTER || currentChar == EOF) {
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

    while (currentChar == ENTER || currentChar == ' ') {
        if (currentChar == ENTER) {
            while (currentChar == ENTER) {
                ADVTXT();
            }
        } else {
            ADVTXT();
        }
    }
    COPYWORD();
    if (currentChar == EOF) {
        printf("File selesai dibaca.\n");
        fclose(file);
    }

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
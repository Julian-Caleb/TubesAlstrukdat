#include <stdio.h>
#include "mesinkata.h"
#include "../ADT_MesinKar/mesinkar.h"

boolean EndWord;
Word currentWord;

void IgnoreEnters() {

    while (currentChar == ENTER)
    {
        ADV();
    }

}

void IgnoreBlanks() {

    while (currentChar == BLANK) {
        ADV();
    }

}

void STARTWORD() {

    START();
    IgnoreBlanks();
    IgnoreEnters();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }

}

// void ADVWORD() {

//     IgnoreBlanks();
//     if (currentChar == MARK) {
//         EndWord = true;
//     } else {
//         CopyWord();
//         IgnoreBlanks();
//     }


// }

void CopyWord() {

    int i; 

    i = 0;
    while ((currentChar != MARK) && (i < NMax)) {
        currentWord.TabWord[i] = currentChar;
        ADV();  
        i++;
    }
    currentWord.TabWord[i] = '\0';
    currentWord.Length = i;

}

void STARTSENTENCE() {

    START();
    IgnoreEnters();
    if (currentChar == MARK) {
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }

}

Word CopyToNewWord(Word word1) {

    Word word2;

    int i;
    for (i = 0; i < word1.Length; i++) {
        word2.TabWord[i] = word1.TabWord[i];
    }
    word2.Length = word1.Length;
    return word2;

}

void printWord(Word word) {

   int i;

   for (i = 0; i < word.Length; i++) {

        if (word.TabWord[i] != '\0') {
            printf("%c", word.TabWord[i]);
        }

   }
   
   printf("\n");

}

void printWordNoNewLine(Word word) {
   int i;
   for (i = 0; i < word.Length; i++) {
        if (word.TabWord[i] != '\0') {
            printf("%c", word.TabWord[i]);
        }
   }
}

boolean isWordEqual(Word word1, Word word2) {

    int i;
    boolean check;

    check = true;
    if (word1.Length != word2.Length) {
        check = false;
    } else {
        for (i = 0; i < word1.Length; i++) {
            if (word1.TabWord[i] != word2.TabWord[i]) {
                check = false;
            }
        }
    }

    return check;

}

boolean isEarlyCharInWordEqual(Word word_panjang, Word word_pendek) {

    int i;
    boolean check;
    check = true;
    if (word_pendek.Length >= word_panjang.Length) {
        check = false;
    } else {
        for (i = 0; i < word_pendek.Length; i++) {
            if (word_pendek.TabWord[i] != word_panjang.TabWord[i]) {
                check = false;
            }
        }
    }

    return check;

}

boolean isWordEqualCaseInsensitive(Word word1, Word word2) {

    int i;
    boolean check;

    check = true;
    if (word1.Length != word2.Length) {
        check = false;
    } else {
        for (i = 0; i < word1.Length; i++) {
            if (toLowerCase(word1.TabWord[i]) != toLowerCase(word2.TabWord[i])) {
                check = false;
            }
        }
    }

    return check;

}

int CharToInt(char c) {
    return (((int) c )- 48);
}

int ExtractInteger(Word word) {
    int total;
    int i;
    int tens;
    total = 0;
    tens = 1;
    for (i = word.Length-1; i >= 0; i--) {
        if (word.TabWord[i] != '\n' && word.TabWord[i] != '\r' && word.TabWord[i] != ' ' && word.TabWord[i] != '\t') {
            total = total + (CharToInt(word.TabWord[i]) * (tens));
            tens *= 10;
        }
    }
    return total;
}

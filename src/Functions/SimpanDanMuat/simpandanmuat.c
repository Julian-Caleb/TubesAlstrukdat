#include <stdio.h>
#include "simpandanmuat.h"

Word addExtension(Word foldername) {

    Word filepath;
    int i;
    int length;

    filepath = CopyToNewWord(foldername);

    length = filepath.Length;

    // Menambah ./
    for (i = length - 1; i >= 0; i--) {
        filepath.TabWord[i + 2] = filepath.TabWord[i];
    }
    filepath.TabWord[0] = '.';
    filepath.TabWord[1] = '/';
    length = length + 2;
    filepath.Length = length + 2;

    // Menambah .config
    filepath.TabWord[length++] = '.';
    filepath.TabWord[length++] = 'c';
    filepath.TabWord[length++] = 'o';
    filepath.TabWord[length++] = 'n';
    filepath.TabWord[length++] = 'f';
    filepath.TabWord[length++] = 'i';
    filepath.TabWord[length++] = 'g';
    filepath.TabWord[length++] = '\0';
    filepath.Length = length;

    return filepath;

}

Word penggunaFile(Word foldername) {

    Word filepath;
    int length;

    filepath = CopyToNewWord(foldername);

    length = filepath.Length;
    filepath.TabWord[length++] = '/';
    filepath.TabWord[length++] = 'p';
    filepath.TabWord[length++] = 'e';
    filepath.TabWord[length++] = 'n';
    filepath.TabWord[length++] = 'g';
    filepath.TabWord[length++] = 'g';
    filepath.TabWord[length++] = 'u';
    filepath.TabWord[length++] = 'n';
    filepath.TabWord[length++] = 'a';
    filepath.Length = length;

    filepath = addExtension(filepath);

    return filepath;

}

Word balasanFile(Word foldername) {

    Word filepath;
    int length;

    filepath = CopyToNewWord(foldername);

    length = filepath.Length;
    filepath.TabWord[length++] = '/';
    filepath.TabWord[length++] = 'b';
    filepath.TabWord[length++] = 'a';
    filepath.TabWord[length++] = 'l';
    filepath.TabWord[length++] = 'a';
    filepath.TabWord[length++] = 's';
    filepath.TabWord[length++] = 'a';
    filepath.TabWord[length++] = 'n';
    filepath.Length = length;

    filepath = addExtension(filepath);

    return filepath;

}

Word drafFile(Word foldername) {

    Word filepath;
    int length;

    filepath = CopyToNewWord(foldername);

    length = filepath.Length;
    filepath.TabWord[length++] = '/';
    filepath.TabWord[length++] = 'd';
    filepath.TabWord[length++] = 'r';
    filepath.TabWord[length++] = 'a';
    filepath.TabWord[length++] = 'f';
    filepath.Length = length;

    filepath = addExtension(filepath);

    return filepath;

}

Word kicauanFile(Word foldername) {

    Word filepath;
    int length;

    filepath = CopyToNewWord(foldername);

    length = filepath.Length;
    filepath.TabWord[length++] = '/';
    filepath.TabWord[length++] = 'k';
    filepath.TabWord[length++] = 'i';
    filepath.TabWord[length++] = 'c';
    filepath.TabWord[length++] = 'a';
    filepath.TabWord[length++] = 'u';
    filepath.TabWord[length++] = 'a';
    filepath.TabWord[length++] = 'n';
    filepath.Length = length;

    filepath = addExtension(filepath);

    return filepath;

}

Word utasFile(Word foldername) {

    Word filepath;
    int length;

    filepath = CopyToNewWord(foldername);

    length = filepath.Length;
    filepath.TabWord[length++] = '/';
    filepath.TabWord[length++] = 'u';
    filepath.TabWord[length++] = 't';
    filepath.TabWord[length++] = 'a';
    filepath.TabWord[length++] = 's';
    filepath.Length = length;

    filepath = addExtension(filepath);

    return filepath;

}
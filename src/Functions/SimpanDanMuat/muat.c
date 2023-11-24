#include <stdio.h>
#include "muat.h"

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

// void muat(Word foldername) {
//     struct stat folderStat;
//     if (stat(foldername.TabWord, &folderStat) != 0 || !S_ISDIR(folderStat.st_mode)) {
//         printf("Folder tidak ditemukan :(");
//     } else {
//         muatPengguna(foldername);
//         muatKicauan(foldername);
//     }
// }

void muatPengguna(Word foldername) {
    int n, i, j, k, l;

    int length = foldername.Length;
    foldername.TabWord[length++] = '/';
    foldername.TabWord[length++] = 'p';
    foldername.TabWord[length++] = 'e';
    foldername.TabWord[length++] = 'n';
    foldername.TabWord[length++] = 'g';
    foldername.TabWord[length++] = 'g';
    foldername.TabWord[length++] = 'u';
    foldername.TabWord[length++] = 'n';
    foldername.TabWord[length++] = 'a';
    foldername.Length = length;

    foldername = addExtension(foldername);

    STARTTXT(foldername);
    printWord(currentWord);
    n = ExtractInteger(currentWord);
    for (i = 0; i < n; i++) {
        // Uname
        ADVTXTWORD();
        printWord(currentWord);
        setUsername(&arrayOfProfile.buffer[i], currentWord);
        // Password
        ADVTXTWORD();
        printWord(currentWord);
        setPassword(&arrayOfProfile.buffer[i], currentWord);
        // Bio
        ADVTXTWORD();
        printWord(currentWord);
        setBio(&arrayOfProfile.buffer[i], currentWord);
        // Nomor HP
        ADVTXTWORD();
        printWord(currentWord);
        setNomorHP(&arrayOfProfile.buffer[i], currentWord);
        // Weton
        ADVTXTWORD();
        printWord(currentWord);
        setWeton(&arrayOfProfile.buffer[i], currentWord);
        // Publik
            if (currentWord.TabWord[1] == 'u') { // Publik
            arrayOfProfile.buffer[i].private = true;
        }
        // Matrix 5 baris
        createMatrix(5, 10, &arrayOfProfile.buffer[i].pfp);
        for (j = 0; j < 5; j++) {
            ADVTXTWORD();
            printWord(currentWord);
            l = 0;
            for (k = 0; k < 10; k++) {
                arrayOfProfile.buffer[i].pfp.mem[j][k] = currentWord.TabWord[l];
                l = l + 2;
            }
        }
        // id
        arrayOfProfile.buffer[i].id = i;
    }
    // Teman
    CreateGraf(&grafPertemanan, n);
    for (i = 0; i < n; i++) {
        ADVTXTWORD();
        printWord(currentWord);
        j = 0;
        for (k = 0; k < n; k++) {
            grafPertemanan.mem[i][k] = CharToInt(currentWord.TabWord[j]);
            j = j + 2;
        }
    }
    // Permintaan Pertemanan
    ADVTXTWORD();
    printWord(currentWord);
    n = ExtractInteger(currentWord);
    MakeEmpty();
    for (i = 0; i < n; i++) {
        ADVTXTWORD();
        printWord(currentWord);
        permintaanPertemanan.buffer[i].DariSiapa = CopyToNewWord(arrayOfProfile.buffer[CharToInt(currentWord.TabWord[0])].username); // Yang meminta
        permintaanPertemanan.buffer[i].UntukSiapa = CopyToNewWord(arrayOfProfile.buffer[CharToInt(currentWord.TabWord[2])].username); // Yang menerima
        permintaanPertemanan.buffer[i].banyakTeman = CharToInt(currentWord.TabWord[4]); // Banyak teman yang meminta
    }    
    CLOSETXT();
    permintaanPertemanan.head = 0;
    permintaanPertemanan.tail = n-1;
    permintaanPertemanan.length = n;

}

void muatKicauan(Word foldername) {
    int n, i;

    int length = foldername.Length;
    foldername.TabWord[length++] = '/';
    foldername.TabWord[length++] = 'k';
    foldername.TabWord[length++] = 'i';
    foldername.TabWord[length++] = 'c';
    foldername.TabWord[length++] = 'a';
    foldername.TabWord[length++] = 'u';
    foldername.TabWord[length++] = 'a';
    foldername.TabWord[length++] = 'n';
    foldername.Length = length;

    foldername = addExtension(foldername);

    STARTTXT(foldername);
    printWord(currentWord);
    n = CharToInt(currentWord.TabWord[0]);   
    CreateKicauanExtern(n);
    // Kicauan
    for (i = 0; i < n; i++) {
        // Index
        ADVTXTWORD();
        printWord(currentWord);
        kicauan.buffer[i].index = CharToInt(currentWord.TabWord[0]);
        // Kicau
        ADVTXTWORD();
        printWord(currentWord);
        kicauan.buffer[i].kicau = CopyToNewWord(currentWord);
        // Like
        ADVTXTWORD();
        printWord(currentWord);
        kicauan.buffer[i].like = CharToInt(currentWord.TabWord[0]);
        // Nama
        ADVTXTWORD();
        printWord(currentWord);
        kicauan.buffer[i].nama = CopyToNewWord(currentWord);
        // Datetime
        ADVTXTWORD();
        printWord(currentWord);
        kicauan.buffer[i].time.day = CharToInt(currentWord.TabWord[0]) * 10 + CharToInt(currentWord.TabWord[1]);
        kicauan.buffer[i].time.month = CharToInt(currentWord.TabWord[3]) * 10 + CharToInt(currentWord.TabWord[4]);
        kicauan.buffer[i].time.year = CharToInt(currentWord.TabWord[6]) * 1000 + CharToInt(currentWord.TabWord[7]) * 100 + CharToInt(currentWord.TabWord[8]) * 10 + CharToInt(currentWord.TabWord[9]) * 1;
        kicauan.buffer[i].time.hour = CharToInt(currentWord.TabWord[11]) * 10 + CharToInt(currentWord.TabWord[12]);
        kicauan.buffer[i].time.minute = CharToInt(currentWord.TabWord[14]) * 10 + CharToInt(currentWord.TabWord[15]);
        kicauan.buffer[i].time.second = CharToInt(currentWord.TabWord[17]) * 10 + CharToInt(currentWord.TabWord[18]);
    }   
    CLOSETXT();
}

void muatDraf(Word foldername) {
    int n, j, k;
    int banyakDraf, tens, id;
    Word user;

    int length = foldername.Length;
    foldername.TabWord[length++] = '/';
    foldername.TabWord[length++] = 'd';
    foldername.TabWord[length++] = 'r';
    foldername.TabWord[length++] = 'a';
    foldername.TabWord[length++] = 'f';
    foldername.Length = length;

    foldername = addExtension(foldername);
    STARTTXT(foldername);
    printWord(currentWord);
    n = ExtractInteger(currentWord);
    CreateDrafExtern(5);
    // Draf
    while (n > 0) {
        printf("test");
        // Mengambil username dan banyak draf
        ADVTXTWORD();
        printWord(currentWord);
        banyakDraf = 0;
        tens = 1;
        j = currentWord.Length - 1;
        while (currentWord.TabWord[j] != ' ') {

            banyakDraf = banyakDraf + (CharToInt(currentWord.TabWord[j]) * tens);
            tens *= 10;
            j--;
        }
        for (k = 0; k < j; k++) {
            user.TabWord[k] = currentWord.TabWord[k];
        }
        user.Length = j;

        id = checkId(user);
        
        if (banyakDraf > draf[id].capacity) {
            ExpandDrafCertainPengguna(id);
        }

        // Tiap draf
        for (j = 0; j < banyakDraf; j++) {
            // Draf Kicau
            ADVTXTWORD();
            printWord(currentWord);
            draf[id].buffer[j].kicau = CopyToNewWord(currentWord);
            // Draf datetime
            draf[id].buffer[j].time.day = CharToInt(currentWord.TabWord[0]) * 10 + CharToInt(currentWord.TabWord[1]);
            draf[id].buffer[j].time.month = CharToInt(currentWord.TabWord[3]) * 10 + CharToInt(currentWord.TabWord[4]);
            draf[id].buffer[j].time.year = CharToInt(currentWord.TabWord[6]) * 1000 + CharToInt(currentWord.TabWord[7]) * 100 + CharToInt(currentWord.TabWord[8]) * 10 + CharToInt(currentWord.TabWord[9]) * 1;
            draf[id].buffer[j].time.hour = CharToInt(currentWord.TabWord[11]) * 10 + CharToInt(currentWord.TabWord[12]);
            draf[id].buffer[j].time.minute = CharToInt(currentWord.TabWord[14]) * 10 + CharToInt(currentWord.TabWord[15]);
            draf[id].buffer[j].time.second = CharToInt(currentWord.TabWord[17]) * 10 + CharToInt(currentWord.TabWord[18]);
        }

        n--;

    }
}

void muatUtas(Word foldername) {
    
}
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


void simpan(Word foldername) {

    // Cek eksistensi folder
    struct stat folderStat;
    if (stat(foldername.TabWord, &folderStat) != 0) {
        if (mkdir(foldername.TabWord, 0777) == 0) {
            printf("Folder belum ada, dibuat dulu ya :D\n");
        } else {
            printf("Folder ditemukan :D\n");
        }
    }

    // Akses path
    Word penggunaPath, balasanPath, drafPath, kicauanPath, utasPath;

    penggunaPath = penggunaFile(foldername);
    printWord(penggunaPath);
    balasanPath = balasanFile(foldername);
    printWord(balasanPath);
    drafPath = drafFile(foldername);
    printWord(drafPath);
    kicauanPath = kicauanFile(foldername);
    printWord(kicauanPath);
    utasPath = utasFile(foldername);
    printWord(utasPath);

    int v = 5;
    FILE* file;

    // Pengguna
    file = fopen(penggunaPath.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    fprintf(file, "%d\n", v);
    fclose(file);

    // Balasan
    file = fopen(balasanPath.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    fprintf(file, "%d\n", v);
    fclose(file);

    // Kicauan
    file = fopen(kicauanPath.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    fprintf(file, "%d\n", v);
    fclose(file);

    // Utas
    file = fopen(utasPath.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    fprintf(file, "%d\n", v);
    fclose(file);

    // Draf
    file = fopen(drafPath.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    fprintf(file, "%d\n", v);
    fclose(file);

}

void muat(Word foldername) {

    int n, i, j, k, l;

    // Cek eksistensi folder
    struct stat folderStat;
    if (stat(foldername.TabWord, &folderStat) != 0 || !S_ISDIR(folderStat.st_mode)) {
        printf("Folder tidak ditemukan :(");
    } else {
        // Pembuatan path
        Word penggunaPath, balasanPath, drafPath, kicauanPath, utasPath;
        penggunaPath = penggunaFile(foldername);
        STARTTXT(penggunaPath);
        printWord(currentWord);
        n = CharToInt(currentWord.TabWord[0]);
        ADVTXTWORD();
        printWord(currentWord);
        for (i = 0; i < n; i++) {
            // Uname
            setUsername(&arrayOfProfile.buffer[i], currentWord);
            ADVTXTWORD();
            printWord(currentWord);
            // Password
            setPassword(&arrayOfProfile.buffer[i], currentWord);
            ADVTXTWORD();
            printWord(currentWord);
            // Bio
            setBio(&arrayOfProfile.buffer[i], currentWord);
            ADVTXTWORD();
            printWord(currentWord);
            // Nomor HP
            setNomorHP(&arrayOfProfile.buffer[i], currentWord);
            ADVTXTWORD();
            printWord(currentWord);
            // Weton
            setWeton(&arrayOfProfile.buffer[i], currentWord);
            ADVTXTWORD();
            printWord(currentWord);
            // Publik
                if (currentWord.TabWord[1] == 'u') { // Publik
                arrayOfProfile.buffer[i].private = true;
            }
            ADVTXTWORD();
            printWord(currentWord);
            // Matrix 5 baris
            createMatrix(5, 10, &arrayOfProfile.buffer[i].pfp);
            for (j = 0; j < 5; j++) {
                l = 0;
                for (k = 0; k < 10; k++) {
                    arrayOfProfile.buffer[i].pfp.mem[j][k] = currentWord.TabWord[l];
                    l = l + 2;
                }
                ADVTXTWORD();
                printWord(currentWord);
            }
            // id
            arrayOfProfile.buffer[i].id = i;
        }
        // Teman
        CreateGraf(&grafPertemanan, 3);
        for (i = 0; i < n; j++) {
            j = 0;
            for (k = 0; k < n; k++) {
                grafPertemanan.mem[i][k] = currentWord.TabWord[j];
                j = j + 2;
            }
            ADVTXTWORD();
            printWord(currentWord);
        }
        // Permintaan Pertemanan
        n = CharToInt(currentWord.TabWord[0]);
        MakeEmpty();
        ADVTXTWORD();
        printWord(currentWord);
        for (i = 0; i < n; i++) {
            permintaanPertemanan.buffer[i].DariSiapa = CopyToNewWord(arrayOfProfile.buffer[(int) currentWord.TabWord[0]].username); // Yang meminta
            permintaanPertemanan.buffer[i].UntukSiapa = CopyToNewWord(arrayOfProfile.buffer[(int) currentWord.TabWord[2]].username); // Yang menerima
            permintaanPertemanan.buffer[i].banyakTeman = (int) currentWord.TabWord[4]; // Banyak teman yang meminta
            ADVTXTWORD();
            printWord(currentWord);            
        }
        permintaanPertemanan.head = 0;
        permintaanPertemanan.tail = n-1;
        permintaanPertemanan.length = n;
        CLOSETXT();

        // kicauan.config
        kicauanPath = kicauanFile(foldername);
        STARTTXT(kicauanPath);
        n = CharToInt(currentWord.TabWord[0]);
        ADVTXTWORD();
        printWord(currentWord);            
        CreateKicauanExtern(n);
        for (i = 0; i < n; i++) {
            kicauan.buffer[i].index = CharToInt(currentWord.TabWord[0]);
            ADVTXTWORD();
            printWord(currentWord);
            kicauan.buffer[i].kicau = CopyToNewWord(currentWord);
            ADVTXTWORD();
            printWord(currentWord);
            kicauan.buffer[i].like = CharToInt(currentWord.TabWord[0]);
            ADVTXTWORD();
            printWord(currentWord);
            kicauan.buffer[i].nama = CopyToNewWord(currentWord);
            ADVTXTWORD();
            printWord(currentWord);
            kicauan.buffer[i].time.day = CharToInt(currentWord.TabWord[0]) * 10 + CharToInt(currentWord.TabWord[1]);
            kicauan.buffer[i].time.month = CharToInt(currentWord.TabWord[3]) * 10 + CharToInt(currentWord.TabWord[4]);
            kicauan.buffer[i].time.year = CharToInt(currentWord.TabWord[6]) * 1000 + CharToInt(currentWord.TabWord[7]) * 100 + CharToInt(currentWord.TabWord[8]) * 10 + CharToInt(currentWord.TabWord[9]) * 1;
            kicauan.buffer[i].time.hour = CharToInt(currentWord.TabWord[11]) * 10 + CharToInt(currentWord.TabWord[12]);
            kicauan.buffer[i].time.minute = CharToInt(currentWord.TabWord[14]) * 10 + CharToInt(currentWord.TabWord[15]);
            kicauan.buffer[i].time.second = CharToInt(currentWord.TabWord[17]) * 10 + CharToInt(currentWord.TabWord[18]);
            printf("test");
            ADVTXTWORD();
            printWord(currentWord);
        }

        balasanPath = balasanFile(foldername);
        printWord(balasanPath);
        
        drafPath = drafFile(foldername);
        printWord(drafPath);

        utasPath = utasFile(foldername);
        printWord(utasPath);

    }

}
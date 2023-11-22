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
    ArrayOfProfile arrayOfProfile;

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
        n = currentWord.TabWord[0];
        for(i = 0; i < n; i++) {
            // Uname
            ADVTXTWORD();
            setUsername(&arrayOfProfile.buffer[i], currentWord);
            // Password
            ADVTXTWORD();
            setPassword(&arrayOfProfile.buffer[i], currentWord);
            // Bio
            ADVTXTWORD();
            setBio(&arrayOfProfile.buffer[i], currentWord);
            // Nomor HP
            ADVTXTWORD();
            setNomorHP(&arrayOfProfile.buffer[i], currentWord);
            // Weton
            ADVTXTWORD();
            setWeton(&arrayOfProfile.buffer[i], currentWord);
            // Publik
            ADVTXTWORD();
            if (currentWord.TabWord[1] == 'u') { // Publik
                arrayOfProfile.buffer[i].private = true;
            }
            // Matrix 5 baris
            createMatrix(5, 10, &arrayOfProfile.buffer[i].pfp);
            for (j = 0; j < 5; j++) {
                ADVTXTWORD();
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
        CreateGraf(&grafPertemanan, 3);
        for (i = 0; i < n; j++) {
            ADVTXTWORD();
            j = 0;
            for (k = 0; k < n; k++) {
                grafPertemanan.mem[i][k] = currentWord.TabWord[j];
                j = j + 2;
            }
        }  
        printMatrixPertemanan();
        // Permintaan Pertemanan
        // n = currentWord.TabWord[0];
        // for (i = 0; i < n; i++) {
        //     ADVTXTWORD();
        //     currentWord.TabWord[0]; // Yang meminta
        //     currentWord.TabWord[2]; // Yang menerima
        //     currentWord.TabWord[4]; // Banyak teman yang meminta
        // }
        balasanPath = balasanFile(foldername);
        printWord(balasanPath);
        
        drafPath = drafFile(foldername);
        printWord(drafPath);
        kicauanPath = kicauanFile(foldername);
        printWord(kicauanPath);
        utasPath = utasFile(foldername);
        printWord(utasPath);

    }

}
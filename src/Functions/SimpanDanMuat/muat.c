#include <stdio.h>
#include "muat.h"

void muat(Word foldername) {
    struct stat folderStat;
    if (stat(foldername.TabWord, &folderStat) != 0 || !S_ISDIR(folderStat.st_mode)) {
        printf("Folder tidak ditemukan :(");
    } else {
        muatPengguna(foldername);
        muatKicauan(foldername);
        muatDraf(foldername);
        muatUtas(foldername);
        muatBalasan(foldername);
    }
}

void muatPengguna(Word foldername) {
    int n, i, j, k, l;

    foldername = penggunaFile(foldername);

    STARTTXT(foldername);
    n = ExtractInteger(currentWord);
    arrayOfProfile.length = n;
    if (n > 0) {
        for (i = 0; i < n; i++) {
            // Uname
            ADVTXTWORD();
            currentWord.Length--;
            setUsername(&arrayOfProfile.buffer[i], currentWord);
            // Password
            ADVTXTWORD();
            currentWord.Length--;
            setPassword(&arrayOfProfile.buffer[i], currentWord);
            // Bio
            ADVTXTWORD();
            currentWord.Length--;
            setBio(&arrayOfProfile.buffer[i], currentWord);
            // Nomor HP
            ADVTXTWORD();
            currentWord.Length--;
            setNomorHP(&arrayOfProfile.buffer[i], currentWord);
            // Weton
            ADVTXTWORD();
            currentWord.Length--;
            setWeton(&arrayOfProfile.buffer[i], currentWord);
            // Publik
            ADVTXTWORD();
            currentWord.Length--;
            if (currentWord.TabWord[1] == 'r') { // Private
                arrayOfProfile.buffer[i].private = true;
            }
            else{ // Publik
                arrayOfProfile.buffer[i].private = false;
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
        CreateGraf(&grafPertemanan, n);
        for (i = 0; i < n; i++) {
            ADVTXTWORD();
            j = 0;
            for (k = 0; k < n; k++) {
                grafPertemanan.mem[i][k] = CharToInt(currentWord.TabWord[j]);
                j = j + 2;
            }
        }
        // Permintaan Pertemanan
        ADVTXTWORD();
        n = ExtractInteger(currentWord);
        MakeEmpty();
        for (i = 0; i < n; i++) {
            ADVTXTWORD();
            permintaanPertemanan.buffer[i].DariSiapa = CopyToNewWord(arrayOfProfile.buffer[CharToInt(currentWord.TabWord[0])].username); // Yang meminta
            permintaanPertemanan.buffer[i].UntukSiapa = CopyToNewWord(arrayOfProfile.buffer[CharToInt(currentWord.TabWord[2])].username); // Yang menerima
            if (currentWord.TabWord[5] == '\n' || currentWord.TabWord[5] == '\r') {
                permintaanPertemanan.buffer[i].banyakTeman = CharToInt(currentWord.TabWord[4]); // Banyak teman yang meminta
            } else {
                permintaanPertemanan.buffer[i].banyakTeman = (CharToInt(currentWord.TabWord[4]) * 10) + (CharToInt(currentWord.TabWord[5])); // Banyak teman yang meminta
            }
        }    
        permintaanPertemanan.head = 0;
        permintaanPertemanan.tail = n-1;
        permintaanPertemanan.length = n;
    }
    CLOSETXT();
        

}

void muatKicauan(Word foldername) {
    int n, i;

    foldername = kicauanFile(foldername);

    STARTTXT(foldername);
    n = CharToInt(currentWord.TabWord[0]);   
    CreateKicauanExtern(n);
    kicauan.nEffKicau = n;
    // Kicauan
    for (i = 0; i < n; i++) {
        // Index
        ADVTXTWORD();
        kicauan.buffer[i].index = ExtractInteger(currentWord);
        // Kicau
        ADVTXTWORD();
        currentWord.Length--;
        kicauan.buffer[i].kicau = CopyToNewWord(currentWord);
        // Like
        ADVTXTWORD();
        kicauan.buffer[i].like = ExtractInteger(currentWord);
        // Nama
        ADVTXTWORD();
        currentWord.Length--;
        kicauan.buffer[i].nama = CopyToNewWord(currentWord);
        // Datetime
        ADVTXTWORD();
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

    foldername = drafFile(foldername);

    STARTTXT(foldername);
    n = ExtractInteger(currentWord);
    CreateDrafExtern(5);
    // Draf
    while (n > 0) {
        // Mengambil username dan banyak draf
        ADVTXTWORD();

        banyakDraf = 0;
        tens = 1;
        j = currentWord.Length - 2;
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
    
            currentWord.Length--;
            draf[id].buffer[j].kicau = CopyToNewWord(currentWord);
            // Draf datetime
            ADVTXTWORD();
    
            draf[id].buffer[j].time.day = CharToInt(currentWord.TabWord[0]) * 10 + CharToInt(currentWord.TabWord[1]);
            draf[id].buffer[j].time.month = CharToInt(currentWord.TabWord[3]) * 10 + CharToInt(currentWord.TabWord[4]);
            draf[id].buffer[j].time.year = CharToInt(currentWord.TabWord[6]) * 1000 + CharToInt(currentWord.TabWord[7]) * 100 + CharToInt(currentWord.TabWord[8]) * 10 + CharToInt(currentWord.TabWord[9]) * 1;
            draf[id].buffer[j].time.hour = CharToInt(currentWord.TabWord[11]) * 10 + CharToInt(currentWord.TabWord[12]);
            draf[id].buffer[j].time.minute = CharToInt(currentWord.TabWord[14]) * 10 + CharToInt(currentWord.TabWord[15]);
            draf[id].buffer[j].time.second = CharToInt(currentWord.TabWord[17]) * 10 + CharToInt(currentWord.TabWord[18]);
        }

        n--;

    }
    CLOSETXT();
}

void muatUtas(Word foldername) {
    int n, i, j;
    int idKicau, banyakUtas;
    Address a, b;

    foldername = utasFile(foldername);

    STARTTXT(foldername);
    n = ExtractInteger(currentWord);
    kicauan.nEffUtas = n;
    for (i = 1; i <= n; i++) {
        // Id Kicauan        
        ADVTXTWORD();
        idKicau = ExtractInteger(currentWord);
        kicauan.buffer[idKicau].idUtas = i;
        // Banyak utas
        ADVTXTWORD();
        banyakUtas = ExtractInteger(currentWord);
        for (j = 0; j < banyakUtas; j++) {
            b = newUtas();
            // Isi utas
            ADVTXTWORD();
            currentWord.Length--;
            b->kicau = CopyToNewWord(currentWord);
            // Author
            ADVTXTWORD();
            currentWord.Length--;
            b->nama = CopyToNewWord(currentWord);
            // Datetime
            ADVTXTWORD();
            b->time.day = CharToInt(currentWord.TabWord[0]) * 10 + CharToInt(currentWord.TabWord[1]);
            b->time.month = CharToInt(currentWord.TabWord[3]) * 10 + CharToInt(currentWord.TabWord[4]);
            b->time.year = CharToInt(currentWord.TabWord[6]) * 1000 + CharToInt(currentWord.TabWord[7]) * 100 + CharToInt(currentWord.TabWord[8]) * 10 + CharToInt(currentWord.TabWord[9]) * 1;
            b->time.hour = CharToInt(currentWord.TabWord[11]) * 10 + CharToInt(currentWord.TabWord[12]);
            b->time.minute = CharToInt(currentWord.TabWord[14]) * 10 + CharToInt(currentWord.TabWord[15]);
            b->time.second = CharToInt(currentWord.TabWord[17]) * 10 + CharToInt(currentWord.TabWord[18]);

            if (j == 0) {
                kicauan.buffer[idKicau].nextUtas = b;
                a = b;
            } else {
                a->nextUtas = b;
                a = b;
            }
        }

    }
    CLOSETXT();

}

void muatBalasan(Word foldername) {
    int n, i, j, k;
    int idKicau, idYangDibalas, idBalasannya;
    Word tempOne, tempTwo;
    AddressBalasan b, newb;

    foldername = balasanFile(foldername);

    STARTTXT(foldername);
    n = ExtractInteger(currentWord);
    printWord(currentWord);
    while (n > 0) {
        // ID Kicauan
        ADVTXTWORD();
        printWord(currentWord);
        idKicau = ExtractInteger(currentWord);
        // Memiliki 4 balasan
        ADVTXTWORD();
        printWord(currentWord);
        i = ExtractInteger(currentWord);
        // Untuk tiap balasan
        while (i > 0) {
            // Membalas apa
            ADVTXTWORD();
            printWord(currentWord);
            j = 0; 
            while (currentWord.TabWord[j] != ' ') {
                tempOne.TabWord[j] = currentWord.TabWord[j];
                j++;
            }
            tempOne.Length = j;
            j++; k = 0;
            while (j < currentWord.Length) {
                tempTwo.TabWord[k] = currentWord.TabWord[j];
                j++; k++;
            }
            tempTwo.Length = k-1;         
            // Buat newb
            newb = newBalasan();
            while (newb == NULL) {
                newb = newBalasan();
            }
            // Kalau kicau utama
            if (tempOne.TabWord[0] == '-') {
                b = kicauan.buffer[idKicau-1].balasan;
                if (b == NULL) {
                    kicauan.buffer[idKicau-1].balasan = newb;
                } else {
                    while (b->sibling != NULL) {
                        b = b->sibling;
                    }
                    b->sibling = newb;
                    printf("bruh");
                }
            } else {
                idYangDibalas = ExtractInteger(tempOne);
                b = CariBalasanDariKicau(idKicau, idYangDibalas);
                if (b->child == NULL) {
                    b->child = newb;
                } else {
                    while (b->sibling != NULL) {
                        b = b->sibling;
                    }
                    b->sibling = newb;
                }
            }
            // Id
            idBalasannya = ExtractInteger(tempTwo);
            newb->idBalasan = idBalasannya;
            // Kicau
            ADVTXTWORD();
            printWord(currentWord);
            newb->kicau = CopyToNewWord(currentWord);
            // Author
            ADVTXTWORD();
            printWord(currentWord);
            newb->nama = CopyToNewWord(currentWord);
            // Datetime
            ADVTXTWORD();
            printWord(currentWord);
            newb->time.day = CharToInt(currentWord.TabWord[0]) * 10 + CharToInt(currentWord.TabWord[1]);
            newb->time.month = CharToInt(currentWord.TabWord[3]) * 10 + CharToInt(currentWord.TabWord[4]);
            newb->time.year = CharToInt(currentWord.TabWord[6]) * 1000 + CharToInt(currentWord.TabWord[7]) * 100 + CharToInt(currentWord.TabWord[8]) * 10 + CharToInt(currentWord.TabWord[9]) * 1;
            newb->time.hour = CharToInt(currentWord.TabWord[11]) * 10 + CharToInt(currentWord.TabWord[12]);
            newb->time.minute = CharToInt(currentWord.TabWord[14]) * 10 + CharToInt(currentWord.TabWord[15]);
            newb->time.second = CharToInt(currentWord.TabWord[17]) * 10 + CharToInt(currentWord.TabWord[18]);
            CetakBalasan(idKicau);
        }
    }
    CLOSETXT();

}

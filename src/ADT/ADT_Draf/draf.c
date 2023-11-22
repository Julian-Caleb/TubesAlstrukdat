#include <stdio.h>
#include "draf.h"

Draf draf;

void CreateDrafExtern() {
    draf.buffer = (Kicau*)malloc(1 * sizeof(Kicau));

    if (draf.buffer != NULL) {
        draf.TOP = Nil;
        draf.capacity = 1;
    } else {
        printf("Alokasi memori gagal!\n");
        return;
    }
}

boolean IsDrafEmpty() {
    return (draf.TOP == Nil);
}

boolean IsDrafFull() {
    return (draf.capacity == draf.TOP + 1);
}

void BuatDraf() {
    Kicau kicau;
    kicau = MakeKicau();
    printf("Apakah anda ingin menghapus, menyimpan, atau menerbitkan draf ini?\n");
    STARTSENTENCE();
    printf("\n");
    if (currentWord.TabWord[0] == 'H' || currentWord.TabWord[0] == 'h') {
        printf("Draf telah berhasil dihapus!");
    } else if (currentWord.TabWord[0] == 'S' || currentWord.TabWord[0] == 's') {
        if (IsDrafFull()) {
            ExpandDraf();
        }
        draf.TOP++;
        draf.buffer[draf.TOP] = kicau;
        printf("draf telah berhasil dihapus!");
    } else if (currentWord.TabWord[0] == 'T' || currentWord.TabWord[0] == 't') {
        if (isKicauanFull()) {
            ExpandKicauan();
        }
        CopyKicau(&kicauan.buffer[kicauan.nEffKicau], kicau);
        kicauan.nEffKicau++;
        printf("Selamat, kicauan berhasil dibuat!\n");
        PrintKicauCertainId(kicau.index);
    }
    printf("\n\n");
}

void LihatDraf() {
    if (IsDrafEmpty()) {
        printf("Yah, anda belum memiliki draf apapun! Buat dulu ya :D");
    } else {
        printf("Ini draf terakhir Anda:\n");
        printf("| ");
        displayTime(draf.buffer[draf.TOP].time);
        printf("\n");
        printf("| ");
        printWord(draf.buffer[draf.TOP].kicau);
        printf("\n");
        printf("Apakah anda ingin menghapus, mengubah, atau menerbitkan draf ini?\n");
        STARTSENTENCE();
        printf("\n");
        if (currentWord.TabWord[0] == 'H' || currentWord.TabWord[0] == 'h') {
            draf.TOP--;
            if (draf.TOP < draf.capacity / 2) {
                ShrinkDraf();
            }
            printf("Draf telah berhasil dihapus!");
        } else if (currentWord.TabWord[0] == 'U' || currentWord.TabWord[0] == 'u') {
            printf("Masukkan kicau baru:\n");
            STARTSENTENCE();
            printf("\n");
            draf.buffer[draf.TOP].kicau = CopyToNewWord(currentWord);
            draf.buffer[draf.TOP].time = setTime();
            printf("Draf telah berhasil diubah!");
        } else if (currentWord.TabWord[0] == 'T' || currentWord.TabWord[0] == 't') {
            if (isKicauanFull()) {
                ExpandKicauan();
            }
            CopyKicau(&kicauan.buffer[kicauan.nEffKicau], draf.buffer[draf.TOP]);
            kicauan.nEffKicau++;
            printf("Selamat, kicauan berhasil dibuat!\n");
            PrintKicauCertainId(draf.buffer[draf.TOP].index);
            draf.TOP--;
        }
    }
    printf("\n\n");
}

void ExpandDraf() {
    draf.capacity *= 2;
    Kicau* temp = (Kicau*)realloc(draf.buffer, draf.capacity * sizeof(Kicau));
    if (temp != NULL) {
        draf.buffer = temp;
    } else {
        printf("Memory reallocation failed!\n");
    }
}

void ShrinkDraf() {
    draf.capacity /= 2;
    Kicau* temp = (Kicau*)realloc(draf.buffer, draf.capacity * sizeof(Kicau));
    if (temp != NULL) {
        draf.buffer = temp;
    } else {
        printf("Memory reallocation failed!\n");
    }
}
#include <stdio.h>
#include "draf.h"

Draf draf[CAPACITYPENGGUNA];

void CreateDrafExtern(int n) {
    int i;
    i = 0;
    while (i < CAPACITYPENGGUNA) {
        draf[i].buffer = (Kicau*)malloc(n * sizeof(Kicau));

        if (draf[i].buffer != NULL) {
            draf[i].TOP = Nil;
            draf[i].capacity = n;
            i++;
        } else {
            printf("Alokasi memori gagal!\n");
        }
    }
}

boolean IsDrafEmpty() {
    return (draf[currentUser.id].TOP == Nil);
}

boolean IsDrafFull() {
    return (draf[currentUser.id].capacity == draf[currentUser.id].TOP + 1);
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
        draf[currentUser.id].TOP++;
        draf[currentUser.id].buffer[draf[currentUser.id].TOP] = kicau;
        printf("draf telah berhasil disimpan!");
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
        displayTime(draf[currentUser.id].buffer[draf[currentUser.id].TOP].time);
        printf("\n");
        printf("| ");
        printWord(draf[currentUser.id].buffer[draf[currentUser.id].TOP].kicau);
        printf("\n");
        printf("Apakah anda ingin menghapus, mengubah, atau menerbitkan draf ini?\n");
        STARTSENTENCE();
        printf("\n");
        if (currentWord.TabWord[0] == 'H' || currentWord.TabWord[0] == 'h') {
            draf[currentUser.id].TOP--;
            if (draf[currentUser.id].TOP < draf[currentUser.id].capacity / 2) {
                ShrinkDraf();
            }
            printf("Draf telah berhasil dihapus!");
        } else if (currentWord.TabWord[0] == 'U' || currentWord.TabWord[0] == 'u') {
            printf("Masukkan kicau baru:\n");
            STARTSENTENCE();
            printf("\n");
            draf[currentUser.id].buffer[draf[currentUser.id].TOP].kicau = CopyToNewWord(currentWord);
            draf[currentUser.id].buffer[draf[currentUser.id].TOP].time = setTime();
            printf("Draf telah berhasil diubah!");
        } else if (currentWord.TabWord[0] == 'T' || currentWord.TabWord[0] == 't') {
            if (isKicauanFull()) {
                ExpandKicauan();
            }
            CopyKicau(&kicauan.buffer[kicauan.nEffKicau], draf->buffer[draf->TOP]);
            kicauan.nEffKicau++;
            printf("Selamat, kicauan berhasil dibuat!\n");
            PrintKicauCertainId(draf[currentUser.id].buffer[draf[currentUser.id].TOP].index);
            draf[currentUser.id].TOP--;
        }
    }
    printf("\n\n");
}

void ExpandDraf() {
    int i;
    draf[currentUser.id].capacity *= 2;
    i = 0;
    while (i < CAPACITYPENGGUNA) {
        Kicau* temp = (Kicau*)realloc(draf[currentUser.id].buffer, draf[currentUser.id].capacity * sizeof(Kicau));
        if (temp != NULL) {
            draf[currentUser.id].buffer = temp;
        } else {
            printf("Memory reallocation failed!\n");
        }
    }
}

void ExpandDrafCurrentUser() {
    draf[currentUser.id].capacity *= 2;
    Kicau* temp = (Kicau*)realloc(draf[currentUser.id].buffer, draf[currentUser.id].capacity * sizeof(Kicau));
    if (temp != NULL) {
        draf[currentUser.id].buffer = temp;
    } else {
        printf("Memory reallocation failed!\n");
    }
}

void ExpandDrafCertainPengguna(int id) {
    draf[id].capacity *= 2;
    Kicau* temp = (Kicau*)realloc(draf[id].buffer, draf[id].capacity * sizeof(Kicau));
    if (temp != NULL) {
        draf[id].buffer = temp;
    } else {
        printf("Memory reallocation failed!\n");
    }
}

void ShrinkDraf() {
    int i;
    draf[currentUser.id].capacity /= 2;
    i = 0;
    while (i < CAPACITYPENGGUNA) {
        Kicau* temp = (Kicau*)realloc(draf[currentUser.id].buffer, draf[currentUser.id].capacity * sizeof(Kicau));
        if (temp != NULL) {
            draf[currentUser.id].buffer = temp;
        } else {
            printf("Memory reallocation failed!\n");
        }
    }
}

void ShrinkDrafCurrentUser() {
    draf[currentUser.id].capacity /= 2;
    Kicau* temp = (Kicau*)realloc(draf[currentUser.id].buffer, draf[currentUser.id].capacity * sizeof(Kicau));
    if (temp != NULL) {
        draf[currentUser.id].buffer = temp;
    } else {
        printf("Memory reallocation failed!\n");
    }
}

void ShrinkDrafCertainPengguna(int id) {
    draf[id].capacity /= 2;
    Kicau* temp = (Kicau*)realloc(draf[id].buffer, draf[id].capacity * sizeof(Kicau));
    if (temp != NULL) {
        draf[id].buffer = temp;
    } else {
        printf("Memory reallocation failed!\n");
    }
}
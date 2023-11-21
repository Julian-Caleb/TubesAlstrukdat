#include <stdio.h>
#include "kicauan.h"

Kicauan kicauan;

boolean isKicauanFull() {
    return (kicauan.nEff == kicauan.capacity);
}

boolean isKicauanEmpty() {
    return (kicauan.nEff == 0);
}

void CreateKicauanExtern() {
    kicauan.buffer = (Kicau*)malloc(100 * sizeof(Kicau));
    
    if (kicauan.buffer != NULL) {
        kicauan.nEff = 0;
        kicauan.capacity = 100;
    } else {
        printf("Alokasi memori gagal!\n");
        return;
    }
}


Kicau MakeKicau() {
    Kicau kicau;
    printf("Masukkan kicauan:\n");
    STARTSENTENCE();
    printf("\n");
    if(isKicauAllSpace(currentWord)) {
        printf("Kicau tidak boleh hanya berisi spasi!");
    } else {
        kicau.id = kicauan.nEff + 1;
        kicau.nama = CopyToNewWord(currentUser.username);
        kicau.time = setTime();
        kicau.kicau = CopyToNewWord(currentWord);
        kicau.like = 0;
    }
    return kicau;
}

void AddKicau() {
    Kicau newKicau;
    newKicau = MakeKicau();
    if (isKicauanFull()) {
        ExpandKicauan();
    }
    CopyKicau(&kicauan.buffer[kicauan.nEff], newKicau);
    kicauan.nEff++;
    printf("Selamat, kicauan berhasil dibuat!\n");
    PrintKicauCertainId(newKicau.id);
    printf("\n\n");
}

void CopyKicau(Kicau *kicau1, Kicau kicau2) {
    (*kicau1).id = kicau2.id;
    (*kicau1).kicau = CopyToNewWord(kicau2.kicau);
    (*kicau1).like= kicau2.like;
    (*kicau1).nama = CopyToNewWord(kicau2.nama);
    (*kicau1).time = kicau2.time;
}

void UbahKicau(int id) {
    if (!isIdExist(id)) {
        printf("Tidak ditemukan kicau dengan id %d!", id);
    } else if (!isWordEqual(kicauan.buffer[id-1].nama, currentUser.username)) {
        printf("Kicau dengan id %d bukan milikmu!", id);
    } else {
        printf("Masukkan kicauan baru:\n");
        STARTSENTENCE();
        printf("\n");
        if(isKicauAllSpace(currentWord)) {
            printf("Kicau tidak boleh hanya berisi spasi!");
        } else {
            kicauan.buffer[id-1].kicau = CopyToNewWord(currentWord);
            printf("Kicau berhasil diperbaharui!\n");
            PrintKicauCertainId(id);
        }
    }
    printf("\n\n");
}

void SukaKicau(int id) {
    Word name;
    if (!isIdExist(id)) {
        printf("Tidak ditemukan kicau dengan id %d!", id);
    } else {
        name = CopyToNewWord(kicauan.buffer[id-1].nama);
        id = checkId(name);
        if (arrayOfProfile.buffer[id].private && !isTeman(name)) {
            printf("Wah, kicauan tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya!");
        } else {
            kicauan.buffer[id-1].like++;
            printf("Kicau berhasil dilike!");
        }
    }
    printf("\n\n");
}

boolean isIdExist(int id) {
    printf("%d", kicauan.buffer[id-1].id);
    return (id <= kicauan.nEff && id == kicauan.buffer[id-1].id);
}

boolean isKicauAllSpace(Word kicau) {
    int i;
    boolean space;
    i = 0;
    space = true;
    while(i < kicau.Length && space) {
        if (kicau.TabWord[i] != ' ') {
            space = false;
        }
        i++;
    }
    return space;
}

void ExpandKicauan() {
    kicauan.capacity *= 2;
    Kicau* temp = (Kicau*)realloc(kicauan.buffer, kicauan.capacity * sizeof(Kicau));
    if (temp != NULL) {
        kicauan.buffer = temp;
    } else {
        printf("Memory reallocation failed!\n");
    }
}

void PrintKicau() {
    int i;
    for (i = 0; i < kicauan.nEff; i++) {
        if (isWordEqual(kicauan.buffer[i].nama, currentUser.username)) {
            printf("| ");
            printf("ID = %d", kicauan.buffer[i].id);
            printf("\n");
            printf("| ");
            printWordNoNewLine(kicauan.buffer[i].nama);
            printf("\n");
            printf("| ");
            displayTime(kicauan.buffer[i].time);
            printf("\n");
            printf("| ");
            printWordNoNewLine(kicauan.buffer[i].kicau);
            printf("\n");
            printf("| ");
            printf("Disukai: %d", kicauan.buffer[i].like);
            printf("\n");
            printf("\n");
        }
    }
}

void PrintKicauCertainId(int i) {
    i--;
    printf("| ");
    printf("ID = %d", kicauan.buffer[i].id);
    printf("\n");
    printf("| ");
    printWordNoNewLine(kicauan.buffer[i].nama);
    printf("\n");
    printf("| ");
    displayTime(kicauan.buffer[i].time);
    printf("\n");
    printf("| ");
    printWordNoNewLine(kicauan.buffer[i].kicau);
    printf("\n");
    printf("| ");
    printf("Disukai: %d", kicauan.buffer[i].like);
    printf("\n");
    printf("\n");
}
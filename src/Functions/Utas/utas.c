#include <stdio.h>
#include "utas.h"

Address newUtas() {
    Kicau *kicau = (Kicau *)malloc(sizeof(Kicau));
    return kicau;
}

Address MakeUtas(int indexUtas) {
    Address utas = newUtas();
    int index = indexUtas;
    while (utas == NULL) {
        printf("Alokasi gagal!");
        utas = newUtas();
    } 
    printf("Masukkan kicau:\n");
    STARTSENTENCE();
    printf("\n");
    while (isKicauAllSpace(currentWord)) {
        printf("Kicau tidak boleh hanya berisi spasi!");
        STARTSENTENCE();
        printf("\n");
    }
    if (utas->index == IDX_UNDEF) {
        utas->index = index;
    }
    utas->nama = CopyToNewWord(currentUser.username);
    utas->time = setTime();
    utas->kicau = CopyToNewWord(currentWord);
    utas->like = 0;
    utas->nextUtas = NULL;
    printf("\n\n");
    return utas;
}

void DeallocateKicau(Address kicau) {
    free(kicau);
}

void AddUtas(int idKicau) {
    Address utas, nextUtas;
    int indexUtas;
    if(isLoggedIn){
        indexUtas = lengthUtas(idKicau) + 1;
        if (!isIdExist(idKicau)) {
            printf("Kicauan tidak ditemukan!");
        } else if (!isWordEqual(kicauan.buffer[idKicau-1].nama, currentUser.username)) {
            printf("Utas ini bukan milik anda!");
        } else {
            utas = MakeUtas(indexUtas);
            if (utas != NULL) {
                kicauan.buffer[idKicau-1].nextUtas = utas;
                kicauan.nEffUtas++;
                kicauan.buffer[idKicau-1].idUtas = kicauan.nEffUtas;
                indexUtas++;
                printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
                STARTSENTENCE();
                printf("\n");
                while (currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y') {
                    nextUtas = MakeUtas(indexUtas);
                    if (nextUtas != NULL) {
                        utas->nextUtas = nextUtas;
                        utas = nextUtas;
                        indexUtas++;
                    }
                    printf("Apakah Anda ingin melanjutkan utas ini? (YA/TIDAK)\n");
                    STARTSENTENCE();
                    printf("\n");
                }
            }
            printf("Utas selesai!");
        }
        printf("\n\n");
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

int lengthUtas(int idKicau) {
    int lengthUtas;
    lengthUtas = 0;
    Address utas;
    utas = kicauan.buffer[idKicau-1].nextUtas;
    while (utas != NULL) {
        lengthUtas++;
        utas = utas->nextUtas;
    }
    return lengthUtas;
}

void SambungUtas(int idUtas, int index) {
    Address utas, newUtas;
    int idKicauMinSatu, i;
    if(isLoggedIn){
        idKicauMinSatu = findIdKicau(idUtas);
        if (!isIdExist(idKicauMinSatu)) {
            printf("Utas tidak ditemukan!");
        } else if (!isWordEqual(kicauan.buffer[idKicauMinSatu].nama, currentUser.username)) {
            printf("Utas ini bukan milik anda!");
        } else if (index > lengthUtas(idKicauMinSatu + 1)) {
            printf("Kicauan sambungan tidak ditemukan pada utas!");
        } else {
            utas = kicauan.buffer[idKicauMinSatu].nextUtas;
            if (index != 1) {
                for (i = 1; i < index; i++) {
                    utas = utas->nextUtas;
                }
            }
            newUtas = MakeUtas(index);
            newUtas->nextUtas = utas->nextUtas;
            utas->nextUtas = newUtas;
            utas = newUtas->nextUtas;
            while (utas != NULL) {
                utas->index++;
                utas = utas->nextUtas;
            }
        }
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void HapusUtas(int idUtas, int index) {
    Address utas, beforeUtas;
    int idKicauMinSatu, i;
    if(isLoggedIn){
        idKicauMinSatu = findIdKicau(idUtas);
        if (!isIdExist(idKicauMinSatu)) {
            printf("Utas tidak ditemukan!");
        } else if (!isWordEqual(kicauan.buffer[idKicauMinSatu].nama, currentUser.username)) {
            printf("Utas ini bukan milik anda!");
        } else if (index == 0) {
            printf("Anda tidak bisa menghapus kicauan utama!");
        } else if (index > lengthUtas(idKicauMinSatu + 1)) {
            printf("Kicauan sambungan tidak ditemukan pada utas!");
        } else {
            utas = kicauan.buffer[idKicauMinSatu].nextUtas;
            if (index != 1) {
                for (i = 1; i < index; i++) {
                    beforeUtas = utas;
                    utas = utas->nextUtas;
                }
                beforeUtas->nextUtas = utas->nextUtas;
            }
            beforeUtas = utas;
            utas = utas->nextUtas;
            DeallocateKicau(beforeUtas);
            while (utas != NULL) {
                utas->index--;
                utas = utas->nextUtas;
            }
        }
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void CetakUtas(int idUtas) {
    Address utas;
    int idKicau;
    if(isLoggedIn){
        idKicau = findIdKicau(idUtas);
        if (idKicau == -999) {
            printf("Utas tidak ditemukan!");
        } else if (arrayOfProfile.buffer[idKicau].private && !isTeman(arrayOfProfile.buffer[idKicau].username)) {
            printf("Wah, utas tersebut dibuat oleh akun privat! Ikuti akun itu dulu ya!");
        } else {
            PrintKicauCertainId(idUtas);
            utas = kicauan.buffer[idKicau].nextUtas;
            while (utas != NULL) {
                printf("\t\t| ");
                printf("INDEX = %d", utas->index);
                printf("\n");
                printf("\t\t| ");
                printWordNoNewLine(utas->nama);
                printf("\n");
                printf("\t\t| ");
                displayTime(utas->time);
                printf("\n");
                printf("\t\t| ");
                printWordNoNewLine(utas->kicau);
                printf("\n");
                printf("\n");
                utas = utas->nextUtas;
            }
        }
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

int findIdKicau (int idUtas) {
    int idKicauMinSatu;
    idKicauMinSatu = 0;
    while (idUtas != kicauan.buffer[idKicauMinSatu].idUtas && idKicauMinSatu < kicauan.nEffKicau) {
        idKicauMinSatu++;
    }
    if (idKicauMinSatu == kicauan.nEffKicau) {
        return -999;
    } else {
        return idKicauMinSatu;
    }
}
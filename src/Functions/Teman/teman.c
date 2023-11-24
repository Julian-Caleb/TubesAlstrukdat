#include <stdio.h>
#include "teman.h"

Graf grafPertemanan;

void printMatrixPertemanan() {

    displayGraf(grafPertemanan);

}

void daftarTeman() {

    int i;

    if (isLoggedIn) {
        if (banyakTeman() > 0) {
            printWord(currentUser.username);
            printf(" memiliki %d teman\n", banyakTeman());
            printf("Daftar teman ");
            printWord(currentUser.username);
            printf("\n");
            for (i = 0; i < grafPertemanan.length; i++) {
                if (grafPertemanan.mem[currentUser.id][i] == 1 && i != currentUser.id) {
                    printf("| ");
                    printWord(arrayOfProfile.buffer[i].username);
                    printf("\n");
                }
            }
        } else {
            printWord(currentUser.username);
            printf("belum mempunyai teman \n");
        } 
    } else {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }

}

void hapusTeman() {

    Word friend;

    if (isLoggedIn) {
        printf("Masukkan nama pengguna: \n");
        STARTSENTENCE();
        friend = CopyToNewWord(currentWord);
        if (isTeman(friend)) {
            printf("Apakah anda yakin ingin menghapus");
            printWord(friend); 
            printf("dari daftar teman anda?(YA/TIDAK)");
            STARTSENTENCE();
            if (currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y') {
                grafPertemanan.mem[currentUser.id][checkId(friend)] = 0;
                grafPertemanan.mem[checkId(friend)][currentUser.id] = 0;
            }
        } else {
            printWord(friend);
            printf("Bukan teman Anda");
        }
    } else {
        printf("Anda belum masuk! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }

}

int banyakTeman() {

    int i, total;

    total = 0;

    for (i = 0; i < grafPertemanan.length; i++) {
        if (grafPertemanan.mem[currentUser.id][i] == 1) {
            total++;
        }
    }

    return total-1;

}

int banyakTemanOrangLain(Word name) {

    int i, total, id;

    id = checkId(name);

    total = 0;

    for (i = 0; i < grafPertemanan.length; i++) {
        if (grafPertemanan.mem[id][i] == 1) {
            total++;
        }
    }

    return total-1;

}

boolean isTeman(Word friend) {

    boolean check;
    int i;

    if (checkId(friend) == -999) {
        check = false;
    } else {
        check = true;
        i = checkId(friend);
    }

    if (check) {
        check = false;
        if (grafPertemanan.mem[i][currentUser.id] == 1) {
            check = true;
        }
    }

    return check;

}
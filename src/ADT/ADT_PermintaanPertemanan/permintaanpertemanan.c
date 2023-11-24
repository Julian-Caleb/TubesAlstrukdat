#include <stdio.h>
#include "permintaanpertemanan.h"

PermintaanPertemanan permintaanPertemanan;

boolean IsEmpty() {
    return (permintaanPertemanan.length == 0);
}

boolean IsFull() {
    return (permintaanPertemanan.length == CAPACITYTEMAN);
}

int NBElmt() {
    return (permintaanPertemanan.length);
}

void MakeEmpty () {
    permintaanPertemanan.length = 0;
    permintaanPertemanan.head = -1;
    permintaanPertemanan.tail = -1;
}

void TambahTeman() {
    int i, banyakTeman;
    Word name;
    if(isLoggedIn){
        if (BanyakPermintaan() > 0) {
            printf("Terdapat permintaan pertemanan yang belum Anda setujui. Silakan kosongkan daftar permintaan pertemanan untuk Anda terlebih dahulu.");
        } else {
            printf("Masukkan nama pengguna:\n");
            STARTSENTENCE();
            name = CopyToNewWord(currentWord);
            if (!isUnameExist(name)) {
                printf("Pengguna bernama ");
                printWordNoNewLine(name);
                printf("tidak ditemukan.\n");
            } else if (isPermintaanExist(name)) {
                printf("Anda sudah mengirimkan permintaan pertemanan kepada ");
                printWordNoNewLine(name);
                printf(". Silakan tunggu hingga permintaan Anda disetujui.");
            } else if (isTeman(name)) {
                printf("Anda sudah menjadi temannya");
            } else if (!IsFull()) {
                banyakTeman = banyakTemanOrangLain(name);
                if (IsEmpty()) {
                    permintaanPertemanan.head = 0;
                    permintaanPertemanan.tail = 0;
                    permintaanPertemanan.buffer[0].DariSiapa = CopyToNewWord(currentUser.username);
                    permintaanPertemanan.buffer[0].UntukSiapa = CopyToNewWord(name);
                    permintaanPertemanan.buffer[0].banyakTeman = banyakTemanOrangLain(currentUser.username);
                } else {
                    permintaanPertemanan.tail = permintaanPertemanan.tail + 1;
                    i = permintaanPertemanan.tail - 1;
                    while (banyakTeman > permintaanPertemanan.buffer[i].banyakTeman) {
                        permintaanPertemanan.buffer[i+1].DariSiapa = CopyToNewWord(permintaanPertemanan.buffer[i].DariSiapa);
                        permintaanPertemanan.buffer[i+1].UntukSiapa = CopyToNewWord(permintaanPertemanan.buffer[i].UntukSiapa);
                        permintaanPertemanan.buffer[i+1].banyakTeman = permintaanPertemanan.buffer[i].banyakTeman;
                        i--;
                    }
                    permintaanPertemanan.buffer[i+1].DariSiapa = CopyToNewWord(permintaanPertemanan.buffer[i].DariSiapa);
                    permintaanPertemanan.buffer[i+1].UntukSiapa = CopyToNewWord(permintaanPertemanan.buffer[i].UntukSiapa);
                    permintaanPertemanan.buffer[i+1].banyakTeman = permintaanPertemanan.buffer[i].banyakTeman;
                    permintaanPertemanan.buffer[i].DariSiapa = CopyToNewWord(currentUser.username);
                    permintaanPertemanan.buffer[i].UntukSiapa = CopyToNewWord(name);
                    permintaanPertemanan.buffer[i].banyakTeman = banyakTemanOrangLain(currentUser.username);
                }
                permintaanPertemanan.length++;
                permintaanPertemanan.tail++;
                printf("Permintaan pertemanan kepada "); 
                printWord(name);
                printf("telah dikirim. Tunggu beberapa saat hingga permintaan Anda disetujui.");
            }
        }
        printf("\n\n");
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void SetujuiPertemanan() {
    int i, idTeman, idSaya;
    Word name;
    if(isLoggedIn){
        if (IsEmpty() || BanyakPermintaan() == 0) {
            printf("Tidak ada permintaan pertemanan");
        } else {
            i = 0;
            while (!isWordEqual(permintaanPertemanan.buffer[i].UntukSiapa, currentUser.username)) {
                i++;
            }
            printf("Permintaan teratas dari ");
            printWord(permintaanPertemanan.buffer[i].DariSiapa);
            printf("\n\n");
            printf("| ");
            printWord(permintaanPertemanan.buffer[i].DariSiapa);
            printf("\n");
            printf("| Jumlah teman: ");
            printf("%d", permintaanPertemanan.buffer[i].banyakTeman);
            printf("\n\n");
            printf("Apakah Anda ingin menyetujui permintaan pertemanan ini? (YA/TIDAK)");
            printf("\n");
            STARTSENTENCE();
            if (currentWord.TabWord[0] == 'Y' || currentWord.TabWord[0] == 'y') {
                printf("Permintaan pertemanan dari Bob telah disetujui. Selamat! Anda telah berteman dengan Bob.");
                name = CopyToNewWord(permintaanPertemanan.buffer[i].DariSiapa);
                idTeman = checkId(name);
                idSaya = checkId(currentUser.username);
                grafPertemanan.mem[idTeman][idSaya] = 1;
                grafPertemanan.mem[idSaya][idTeman] = 1;
            } else {
                printf("Permintaan pertemanan dari Bob telah ditolak.");
                name = CopyToNewWord(permintaanPertemanan.buffer[i].DariSiapa);
            }
            permintaanPertemanan.length--;
            if (permintaanPertemanan.length == 0) {
                MakeEmpty(permintaanPertemanan);
            } else {
                while (i < permintaanPertemanan.tail) {
                    permintaanPertemanan.buffer[i].DariSiapa = CopyToNewWord(permintaanPertemanan.buffer[i+1].DariSiapa);
                    permintaanPertemanan.buffer[i].UntukSiapa = CopyToNewWord(permintaanPertemanan.buffer[i+1].UntukSiapa);
                    permintaanPertemanan.buffer[i].banyakTeman = permintaanPertemanan.buffer[i+1].banyakTeman;
                    i++;
                }
                permintaanPertemanan.tail--;
            }
        }
        printf("\n\n");
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void DaftarPermintaanPertemanan() {
    int i;
    if(isLoggedIn){
        if (BanyakPermintaan() == 0) {
            printf("Tidak ada permintaan pertemanan untuk Anda.");
        } else {
            for (i = 0; i < permintaanPertemanan.length; i++) {
                if(isWordEqual(permintaanPertemanan.buffer[i].UntukSiapa, currentUser.username)) {
                    printf("| ");
                    printWord(permintaanPertemanan.buffer[i].DariSiapa);
                    printf("\n");
                    printf("| Jumlah teman: ");
                    printf("%d", permintaanPertemanan.buffer[i].banyakTeman);
                    printf("\n\n");
                }
            }
        }
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

int BanyakPermintaan() {
    int i, total;
    total = 0;
    if (IsEmpty()) {
        total = 0;
    } else {
        for (i = 0; i < permintaanPertemanan.length; i++) {
            if(isWordEqual(permintaanPertemanan.buffer[i].UntukSiapa, currentUser.username)) {
                total++;
            }
        }
    }
    return total;
}

int BanyakMeminta() {
    int i, total;
    total = 0;
    if (IsEmpty()) {
        total = 0;
    } else {
        for (i = 0; i < permintaanPertemanan.length; i++) {
            if(isWordEqual(permintaanPertemanan.buffer[i].DariSiapa, currentUser.username)) {
                total++;
            }
        }
    }
    return total;
}

boolean isPermintaanExist(Word name) {
    int i;
    boolean check;
    check = false;
    for (i = 0; i < permintaanPertemanan.length; i++) {
        if(isWordEqual(permintaanPertemanan.buffer[i].DariSiapa, currentUser.username) && isWordEqual(permintaanPertemanan.buffer[i].UntukSiapa, name)) {
            check = true;
        }
    }
    return check;
}
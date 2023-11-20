#include <stdio.h>
#include "login.h"

boolean isLoggedIn;
User currentUser;
ArrayOfProfile arrayOfProfile;

void daftar() {
    
    Word uname, pass;

    if (isLoggedIn) {
        printf("Anda sudah masuk. Keluar terlebih dahulu untuk melakukan daftar.\n");
        printf("\n");
    } else if (arrayOfProfile.length == CAPACITYPENGGUNA) {
        printf("Jumlah pengguna sudah penuh.\n");
        printf("\n");
    } else {
        printf("Masukkan nama: \n");
        STARTSENTENCE();
        printf("\n");
        while (isUnameExist(currentWord)) {
            printf("Wah, sayang sekali nama tersebut telah diambil.\n");
            STARTSENTENCE();
            printf("\n");
        }
        uname = CopyToNewWord(currentWord);
        printf("Masukkan kata sandi: \n");
        STARTSENTENCE();
        printf("\n");
        pass = CopyToNewWord(currentWord);
        setUsername(&arrayOfProfile.buffer[arrayOfProfile.length], uname);
        setPassword(&arrayOfProfile.buffer[arrayOfProfile.length], pass);
        arrayOfProfile.length++;
        printf("Pengguna telah berhasil terdaftar. Masuk untuk menikmati fitur-fitur BurBir.\n");
        printf("\n");
    }

}

void masuk() {

    Word uname, pass;

    if (isLoggedIn) {
        printf("Wah Anda sudah masuk. Keluar dulu yuk!");
    } else if (arrayOfProfile.length == 0) {
        printf("Belum ada pengguna!");
    } else {
        printf("Masukkan nama: \n");
        STARTSENTENCE();
        printf("\n");
        while (!isUnameExist(currentWord)) {
            printf("Wah, nama yang Anda cari tidak ada. Masukkan nama lain!\n");
            STARTSENTENCE();
            printf("\n");
        }
        printf("\n");
        uname = CopyToNewWord(currentWord);
        printf("Masukkan kata sandi: \n");
        STARTSENTENCE();
        while (!isPasswordExist(currentWord)) {
            printf("Wah, kata sandi yang Anda masukkan belum tepat. Periksa kembali kata sandi Anda!\n");
            STARTSENTENCE();
            printf("\n");
        }
        pass = CopyToNewWord(currentWord);
        setUser(&currentUser, uname, pass);
        printf("Anda telah berhasil masuk dengan nama pengguna Tuan Bri. Mari menjelajahi BurBir bersama Ande-Ande Lumut!\n");
        printf("\n");
    }


}

void keluar() {
    
    if (!isLoggedIn) {
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.");
    } else {
        isLoggedIn = false;
    }

}

boolean isUnameExist(Word uname) {

    boolean check;
    int i;

    check = false;

    for (i = 0; i < arrayOfProfile.length; i++) {
        if (isWordEqual(uname, arrayOfProfile.buffer[i].username)) {
            check = true;
        }
    }

    return check;

}

boolean isPasswordExist(Word pass) {

    boolean check;
    int i;

    check = false;

    for (i = 0; i < arrayOfProfile.length; i++) {
        if (isWordEqual(pass, arrayOfProfile.buffer[i].password)) {
            check = true;
        }
    }

    return check;

}




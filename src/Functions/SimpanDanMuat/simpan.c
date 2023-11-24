#include <stdio.h>
#include "simpan.h"

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
    // printWord(penggunaPath);
    balasanPath = balasanFile(foldername);
    // printWord(balasanPath);
    drafPath = drafFile(foldername);
    // printWord(drafPath);
    kicauanPath = kicauanFile(foldername);
    // printWord(kicauanPath);
    utasPath = utasFile(foldername);
    // printWord(utasPath);

    simpanPengguna(penggunaPath);
    simpanBalasan(balasanPath);
    simpanDraf(drafPath);
    simpanKicauan(kicauanPath);
    simpanUtas(utasPath);

}

void simpanPengguna(Word foldername) {
    FILE* file;
    // Pengguna
    file = fopen(foldername.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    // Tulis di sini
    fclose(file);
}

void simpanKicauan(Word foldername) {
    FILE* file;
    // Kicauan
    file = fopen(foldername.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    // Tulis di sini
    fclose(file);
}

void simpanDraf(Word foldername) {
    FILE* file;
    // Draf
    file = fopen(foldername.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    // Tulis di sini
    fclose(file);
}

void simpanUtas(Word foldername) {
    FILE* file;
    // Utas
    file = fopen(foldername.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    // Tulis di sini
    fclose(file);
}

void simpanBalasan(Word foldername) {
    FILE* file;
    // Balasan
    file = fopen(foldername.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    // Tulis di sini
    fclose(file);
}
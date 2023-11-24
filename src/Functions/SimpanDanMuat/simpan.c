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
    int i;
    fprintf(file,"%d\n",arrayOfProfile.length);
    for(i=0;i<arrayOfProfile.length;i++){
        fprintWord(file,arrayOfProfile.buffer[i].username);
        fprintWord(file,arrayOfProfile.buffer[i].password);
        fprintWord(file,arrayOfProfile.buffer[i].bio);
        fprintWord(file,arrayOfProfile.buffer[i].nomorHP);
        fprintWord(file,arrayOfProfile.buffer[i].weton);
        if(arrayOfProfile.buffer[i].private){
            fprintf(file,"Privat\n");
        }
        else{
            fprintf(file,"Publik\n");
        }
        fdisplayMatrixPFP(file,arrayOfProfile.buffer[i].pfp);
    }
    fdisplayGraf(file,grafPertemanan);
    fprintf(file,"%d",permintaanPertemanan.length);
    for (i=0;i<permintaanPertemanan.length;i++){
        fprintf(file,"%d %d %d",checkId(permintaanPertemanan.buffer[i].DariSiapa),checkId(permintaanPertemanan.buffer[i].UntukSiapa),permintaanPertemanan.buffer[i].banyakTeman);
    }
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
    int exist = 0;
    int i;
    for (i = 1; i <= kicauan.length; i++) {
        if(lengthUtas[i] > 0) {
            exist++;
        }
    }
    fprintf(file, exist);
    for (i = 1; i <= kicauan.length; i++) {
        if(lengthUtas[i] > 0) {
            fprintf(file, findIdKicau[i]);
            fprintf(file, lengthUtas[i]);
            int j;
            for (j = 0; j <= lengthUtas[i]; j++) {
                fprintWord(file, kicauan.buffer[i].kicau);
                fprintWord(file, kicauan.buffer[i].nama);
                fdisplayTime(file, kicauan.buffer[i].time);
            }
        }
    }
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
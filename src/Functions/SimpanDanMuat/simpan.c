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

    fprintf(file, "%d\n", kicauan.nEffKicau);
    for(int i = 0; i < kicauan.nEffKicau; i++){
        fprintf(file, "%d\n", kicauan.buffer[i].index);
        fprintWord(file, kicauan.buffer[i].kicau);
        fprintf(file, "%d\n", kicauan.buffer[i].like);
        fprintWord(file, kicauan.buffer[i].nama);
        displayTime(kicauan.buffer[i].time);
        fprintf(file, "\n");
    }

    // Tulis di sini
    fclose(file);
}


void simpanDraf(Word foldername) {
    FILE* file;
    file = fopen(foldername.TabWord, "w");
    if (file == NULL) {
        printf("Waduh ada error :(");
    }
    int i, n = 0;
    for (i = 0; i < 20; i++) {
        if (draf[i].TOP != Nil) {
            n++;
        }
    }
    fputc(n, file);
    fputc('\n', file);
    for (i = 0; i < 20; i++) {
        if (draf[i].TOP != Nil) {
            fputs(draf[i].buffer[0].nama.TabWord, file);
            fputc(' ', file);
            fputc(draf[i].TOP, file);
            fputc('\n', file);
            int j = 0;
            Address P = &draf[i].buffer[0];
            while (P != NULL) {
                fputs(P->kicau.TabWord, file);
                fputc('\n', file);
                fputc(P->time.day, file);
                fputc('/', file);
                fputc(P->time.month, file);
                fputc('/', file);
                fputc(P->time.year, file);
                fputc(' ', file);
                fputc(P->time.hour, file);
                fputc(':', file);
                fputc(P->time.minute, file);
                fputc(':', file);
                fputc(P->time.second, file);
                fputc('\n', file);
                j++;
                P = &draf[i].buffer[j];
            }
        }
    }
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
    for (i = 1; i <= kicauan.nEffUtas; i++) {
        if(lengthUtas(i) > 0) {
            exist++;
        }
    }
    fprintf(file, "%d\n", exist);
    for (i = 1; i <= kicauan.nEffUtas; i++) {
        if(lengthUtas(i) > 0) {
            fprintf(file, "%d\n", findIdKicau(i));
            fprintf(file, "%d\n", lengthUtas(i));
            int j;
            for (j = 0; j <= lengthUtas(i); j++) {
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
    int i;
    int sum = 0;
    for (i = 0; i < kicauan.nEffKicau; i++) {
        if (kicauan.buffer[i].balasan != NULL) {
            sum++;
        }
    }
    fprintf(file, "%d\n", sum);
    for (i = 0; i < kicauan.nEffKicau; i++) {
        if (kicauan.buffer[i].balasan != NULL) {
            fprintf(file, "%d\n", kicauan.buffer[i].index);
            AddressBalasan utama = kicauan.buffer[i].balasan;
            fprintf(file, "%d\n", TotalBalasan(utama));
            int j, idParent = 0;
            int totalBalasan = TotalBalasan(utama);
            for (j = 1; j <= totalBalasan; j++) {
                AddressBalasan P = CariBalasan(utama, j);
                if (CariBalasanDariKicau(i+1, j) == utama) {
                    fprintf(file, "-1 ");
                }
                else {
                    AddressBalasan parent = CariParent(utama, P);
                    idParent = parent->idBalasan;
                    fprintf(file, "%d ", idParent);
                }
                fprintf(file, "%d\n", P->idBalasan);
                fprintf(file, "%s\n", P->kicau.TabWord);
                fprintf(file, "%s\n", P->nama.TabWord);
                fprintf(file, "%d/%d/%d %d:%d:%d\n", P->time.day, P->time.month, P->time.year, P->time.hour, P->time.minute, P->time.second);
            }
        }
    }
    fclose(file);
}
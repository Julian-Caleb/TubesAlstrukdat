#include <stdio.h>
#include "profile.h"

ArrayOfProfile arrayOfProfile;

void setUsername(Profile *profile, Word namaInput) {
    if (isUsernameValid(namaInput)) {
        (*profile).username = namaInput;
    }
}

void setPassword(Profile *profile, Word passInput) {
    if (isPasswordValid(passInput)) {
        (*profile).password = passInput;
    }
}

void setBio(Profile *profil, Word bioInput)
{
    if (isBioValid(bioInput))
    {
        (*profil).bio = bioInput;
    }    
}

void setNomorHP(Profile *profil, Word noHPInput)
{
    if (isNomorHPValid(noHPInput))
    {
        (*profil).nomorHP = noHPInput;
    }    
}

void setWeton(Profile *profil, Word wetonInput)
{
    if (isWetonValid(wetonInput))
    {
        (*profil).weton = wetonInput;
    }    
}

void togglePrivate(Profile *profil)
{
    (*profil).private = !(*profil).private ;
}

void setpfp(Profile *profil, Matrix profpic)
{
    (*profil).pfp = profpic;
}

boolean isBioValid(Word bio)
{
    return bio.Length <= 135;
}

boolean isNomorHPValid(Word nomor)
{
    int i = 0;
    boolean isDigit = true;
    if (nomor.Length > 15) {
        isDigit = false;
    } else {
        while (isDigit && i < nomor.Length){
            if (nomor.TabWord[i]<48||nomor.TabWord[i]>57){
                isDigit = false;
            }
            i++;
        }
    }
    return isDigit;
}

boolean isWetonValid(Word weton)
{
    Word pahing, kliwon, wage, legi, pon;

    pahing.Length = 6;
    pahing.TabWord[0] = 'p';
    pahing.TabWord[1] = 'a';
    pahing.TabWord[2] = 'h';
    pahing.TabWord[3] = 'i';
    pahing.TabWord[4] = 'n';
    pahing.TabWord[5] = 'g';

    kliwon.Length = 6;
    kliwon.TabWord[0] = 'k';
    kliwon.TabWord[1] = 'l';
    kliwon.TabWord[2] = 'i';
    kliwon.TabWord[3] = 'w';
    kliwon.TabWord[4] = 'o';
    kliwon.TabWord[5] = 'n';

    wage.Length = 4;
    wage.TabWord[0] = 'w';
    wage.TabWord[1] = 'a';
    wage.TabWord[2] = 'g';
    wage.TabWord[3] = 'e';

    legi.Length = 4;
    legi.TabWord[0] = 'l';
    legi.TabWord[1] = 'e';
    legi.TabWord[2] = 'g';
    legi.TabWord[3] = 'i';
    
    pon.Length = 3;
    pon.TabWord[0] = 'p';
    pon.TabWord[1] = 'o';
    pon.TabWord[2] = 'n';

    return (isWordEqualCaseInsensitive(weton, pahing) || isWordEqualCaseInsensitive(weton, kliwon) || isWordEqualCaseInsensitive(weton, legi) || isWordEqualCaseInsensitive(weton, wage) || isWordEqualCaseInsensitive(weton, pon)|| weton.Length==0);

}

void displayPFP(Profile profile)
{
    Matrix foto = profile.pfp;
    int i,j;
    for (i=0;i<5;i++){
        for (j=0;j<=10;j= j+2){
            switch (ELMT(foto,i,j))
            {
            case 'R':
                print_red(ELMT(foto,i,j+1));
                break;
            case 'G':
                print_green(ELMT(foto,i,j+1));
                break;
            case 'B':
                print_blue(ELMT(foto,i,j+1));
                break;
            default:
                break;
            }
        }
        printf("\n");
    }
}

void displayProfile(Profile profil)
{
    printf("| Nama: ");
    printWord(profil.username);
    printf("| Bio: ");
    printWord(profil.bio);
    printf("| No HP: ");
    printWord(profil.nomorHP);
    printf("| Weton: ");
    printWord(profil.weton);
    printf("\n");
    displayPFP(profil);
}

void gantiProfil() {

    int id;

    id = checkId(currentUser.username);
    displayProfile(arrayOfProfile.buffer[id]);

    printf("Masukkan Bio Akun:\n");
    STARTSENTENCE();
    while (!isBioValid(currentWord)) {
        printf("Bio tidak valid. Masukkan lagi yuk!\n");
        STARTSENTENCE();
    }
    setBio(&arrayOfProfile.buffer[id], currentWord);
    printf("\n");

    printf("Masukkan No HP:\n");
    STARTSENTENCE();
    while (!isNomorHPValid(currentWord)) {
        printf("No HP tidak valid. Masukkan lagi yuk!\n");
        STARTSENTENCE();
    }
    setNomorHP(&arrayOfProfile.buffer[id], currentWord);
    printf("\n");

    printf("Masukkan Weton:\n");
    STARTSENTENCE();
    while (!isWetonValid(currentWord)) {
        printf("Weton tidak valid. Masukkan lagi yuk!\n");
        STARTSENTENCE();
    }
    setWeton(&arrayOfProfile.buffer[id], currentWord);    
    printf("\n");

    printf("Profil Anda sudah berhasil diperbarui!\n");
    printf("\n");

}

void lihatProfil(Word username) {
    if (currentUser.id != -1){
        boolean found = false;
        int i = 0;
        while(!found && i<20){
            if(isWordEqual(username, arrayOfProfile.buffer[i].username)){
                found = true;
            }
            i++;
        }
        if(found){
            i--;
            if(isTeman(username) || !(arrayOfProfile.buffer[i].private)){
                displayProfile(arrayOfProfile.buffer[i]);
            }
            else{
                printf("Wah, akun ");
                printWordNoNewLine(username);
                printf(" diprivat nih. Ikuti dulu yuk untuk bisa melihat profil ");
                printWordNoNewLine(username);
                printf("!\n");
            }
        }
        else{
            printf("Tidak ada pengguna dengan nama pengguna tersebut\n");
        }
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void aturJenisAkun() {
    if(currentUser.id!=-1){
        Word ya,tidak;
        ya.Length = 2;
        ya.TabWord[0] = 'Y';
        ya.TabWord[1] = 'A';
        tidak.Length = 5;
        tidak.TabWord[0] = 'T';
        tidak.TabWord[1] = 'I';
        tidak.TabWord[2] = 'D';
        tidak.TabWord[3] = 'A';
        tidak.TabWord[4] = 'K';
        if(arrayOfProfile.buffer[currentUser.id].private){
            printf("Saat ini, akun Anda adalah akun Privat. Ingin mengubah ke akun Publik?\n");   
        }
        else{
            printf("Saat ini, akun Anda adalah akun Publik. Ingin mengubah ke akun Privat?\n");
        }
        while(true){
            printf("(YA/TIDAK)  ");
            STARTSENTENCE();
            if(isWordEqual(ya,currentWord)){
                togglePrivate(&arrayOfProfile.buffer[currentUser.id]);
                break;
            }
            else if(isWordEqual(tidak,currentWord)){
                break;
            }
            printf("\n");
        }
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }

}

void ubahFotoProfil() {
    if (currentUser.id!=-1){
        Matrix profpic;
        int i,j;
        char format;
        printf("Foto profil Anda saat ini adalah\n");
        displayPFP(arrayOfProfile.buffer[currentUser.id]);
        printf("\n");
        printf("Masukkan foto profil yang baru\n");
        createMatrix(5,11,&profpic);
        scanf("%c",&format);
        for(i=0;i<5;i++){
            for(j=0;j<11;j++){
                scanf("%c",&format);
                ELMT(profpic,i,j) = (int)format;
            }
        }
        arrayOfProfile.buffer[currentUser.id].pfp = profpic;
        printf("\n");
        printf("Foto profil anda sudah berhasil diganti!\n");
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }

}

void fdisplayMatrixPFP(FILE* file,Matrix m) {
    int i, j;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 10; j++) {
            fprintf(file,"%c", ELMT(m, i, j));
            if (j != 9) {
                fprintf(file," ");
            }
        }
        fprintf(file,"\n");
    }
}
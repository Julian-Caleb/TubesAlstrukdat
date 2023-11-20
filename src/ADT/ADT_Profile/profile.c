#include <stdio.h>
#include "profile.h"

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
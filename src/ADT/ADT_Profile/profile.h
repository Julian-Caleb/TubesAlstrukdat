#ifndef __PROFILE_H__
#define __PROFILE_H__

#include "../ADT_Boolean/boolean.h"
#include "../ADT_MesinKata/mesinkata.h"
#include "../ADT_Matrix/matrix.h"
#include "../ADT_User/user.h"
#include "../../Functions/PColor/pcolor.h"
#include "../../Functions/Login/login.h"
#include "../../Functions/Teman/teman.h"

#define CAPACITYPENGGUNA 20

/*ADT Profile*/
typedef struct {
    int id;
    Word username;
    Word password;
    Word bio; 
    Word nomorHP;
    Word weton;
    Matrix pfp;
    boolean private;
} Profile;

typedef struct {
    Profile buffer[CAPACITYPENGGUNA];
    int length;
} ArrayOfProfile;

extern ArrayOfProfile arrayOfProfile;

void setUsername(Profile *profile, Word namaInput);

void setPassword(Profile *profile, Word passInput);

void setBio(Profile *profil, Word bioInput);

void setNomorHP(Profile *profil, Word noHPInput);

void setWeton(Profile *profil, Word wetonInput);

void togglePrivate(Profile *profil);

void setpfp(Profile *profil, Matrix profpic);

boolean isBioValid(Word bio);

boolean isNomorHPValid(Word nomor);

boolean isWetonValid(Word weton);

void displayPFP(Profile profile);

void displayProfile(Profile profil);

void gantiProfil();

void lihatProfil(Word username);

void aturJenisAkun();

void ubahFotoProfil();

#endif
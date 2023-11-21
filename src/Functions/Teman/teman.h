#ifndef __TEMAN_H__
#define __TEMAN_H__

#include "../../ADT/ADT_User/user.h"
#include "../../ADT/ADT_Graf/graf.h"
#include "../../ADT/ADT_Profile/profile.h"
#include "../../ADT/ADT_MesinKata/mesinkata.h"
#include "../Login/login.h"

extern Graf grafPertemanan;

void printMatrixPertemanan();

void daftarTeman();

void hapusTeman();

int banyakTeman();

int banyakTemanOrangLain(Word name);

boolean isTeman(Word friend);

#endif
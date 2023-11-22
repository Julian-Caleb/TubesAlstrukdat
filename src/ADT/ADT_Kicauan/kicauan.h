#ifndef KICAUAN_H
#define KICAUAN_H

#include <stdlib.h>
#include "../ADT_Boolean/boolean.h"
#include "../ADT_Datetime/datetime.h"
#include "../ADT_MesinKata/mesinkata.h"
#include "../ADT_User/user.h"
#include "../ADT_Profile/profile.h"

#define IDX_MIN 0
#define IDX_UNDEF -999

typedef struct kicau* Address;
typedef struct kicau {
    int index;
    Word nama;
    Time time;
    Word kicau;
    int like;
    int idUtas;
    Address nextUtas;
} Kicau;

typedef struct
{
    Kicau *buffer;
    int nEffKicau;
    int nEffUtas;
    int capacity;
} Kicauan;

extern Kicauan kicauan;

boolean isKicauanFull();

boolean isKicauanEmpty();

void CreateKicauanExtern();

Kicau MakeKicau();

void AddKicau();

void CopyKicau(Kicau *kicau1, Kicau kicau2);

void UbahKicau(int id);

void SukaKicau(int id);

boolean isIdExist(int id);

boolean isKicauAllSpace(Word kicau);

void ExpandKicauan();

void PrintKicau();

void PrintKicauCertainId(int i);

#endif

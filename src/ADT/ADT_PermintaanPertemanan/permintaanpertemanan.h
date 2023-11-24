#ifndef prioqueue_H
#define prioqueue_H

// Versi 1

#include "../ADT_Boolean/boolean.h"
#include "../ADT_MesinKata/mesinkata.h"
#include "../../Functions/Teman/teman.h"
#include "../../Functions/Login/login.h"

#define Nil -1 
#define CAPACITYTEMAN 20

typedef int AddressInt;

typedef struct {
    Word DariSiapa;
    Word UntukSiapa;
    int banyakTeman;
} Pertemanan;

typedef struct {
    Pertemanan buffer[CAPACITYTEMAN];
    AddressInt head;
    AddressInt tail;
    int length;
} PermintaanPertemanan;

extern PermintaanPertemanan permintaanPertemanan;

boolean IsEmpty();

boolean IsFull();

int NBElmt();

void MakeEmpty();

void TambahTeman();

void SetujuiPertemanan();

void DaftarPermintaanPertemanan();

int BanyakPermintaan();

int BanyakMeminta();

boolean isPermintaanExist(Word name);

#endif

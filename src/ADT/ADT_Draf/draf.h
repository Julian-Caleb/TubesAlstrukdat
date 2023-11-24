#ifndef DRAF_H
#define DRAF_H

#include "../ADT_Boolean/boolean.h"
#include "../ADT_Kicauan/kicauan.h"
#include "../ADT_Profile/profile.h"
#include <stdlib.h>

#define Nil -1

typedef struct { 
  Kicau *buffer;
  int TOP;  
  int capacity;
} Draf;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

extern Draf draf[CAPACITYPENGGUNA];

void CreateDrafExtern(int n);

boolean IsDrafEmpty();

boolean IsDrafFull();

void BuatDraf();

void LihatDraf();

void ExpandDraf();

void ExpandDrafCurrentUser();

void ExpandDrafCertainPengguna(int id);

void ShrinkDraf();

void ShrinkDrafCurrentUser();

void ShrinkDrafCertainPengguna(int id);

int currentUserDraf();

#endif

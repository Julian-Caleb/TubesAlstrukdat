#ifndef UTAS_H
#define UTAS_H

#include "../../ADT/ADT_Kicauan/kicauan.h"
#include "../../ADT/ADT_MesinKata/mesinkata.h"

Address newUtas();

Address MakeUtas(int id);

void DeallocateKicau(Address kicau);

void AddUtas(int id);

int lengthUtas(int id);

void SambungUtas(int idUtas, int index);

void HapusUtas(int idUtas, int index);

void CetakUtas(int idUtas);

int findIdKicau(int idUtas);

#endif

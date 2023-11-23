#ifndef BALASAN_H
#define BALASAN_H

#include <stdlib.h>
#include "../ADT_Boolean/boolean.h"
#include "../ADT_MesinKata/mesinkata.h"
#include "../ADT_Datetime/datetime.h"

typedef struct balasan* AddressBalasan;
typedef struct balasan {
    int idBalasan;
    Word nama;
    Time time;
    Word kicau;
    AddressBalasan child;
    AddressBalasan sibling;
} Balasan;

AddressBalasan newBalasan();

AddressBalasan makeBalasan(int index);

void Balas(int index, int idBalasan);

void CetakBalasanCertainId(int index, int idBalasan);

void CetakBalasanSingular(AddressBalasan balasan);

void CetakBalasan(int index);

void CetakBalasanIndented(AddressBalasan balasan, int level);

void HapusBalasan(int index, int idBalasan);

void DealokasiBalasan (AddressBalasan balasan);

AddressBalasan CariBalasanDariKicau(int index, int idBalasan);

AddressBalasan CariBalasan(AddressBalasan balasan, int idBalasan);

AddressBalasan CariParent(AddressBalasan balasanParent, AddressBalasan balasan);

AddressBalasan CariPreSibling(AddressBalasan balasanPreSibling, AddressBalasan balasan);

int TotalBalasanDariKicauan(int index);

int TotalBalasan(AddressBalasan balasan);

int MaxIdBalasan(AddressBalasan balasan);

#endif
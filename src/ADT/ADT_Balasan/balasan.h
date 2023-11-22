#ifndef BALASAN_H
#define BALASAN_H

#include "../ADT_Boolean/boolean.h"
#include "../ADT_Kicauan/kicauan.h"

typedef struct balasan* Address;
typedef struct balasan {
    int idKicauan;
    Kicau balas;
    Address child;
    Address sibling;
} Balasan;

Kicau MakeBalas();

#endif
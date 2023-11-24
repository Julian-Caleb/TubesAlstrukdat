#ifndef _SIMPAN_H__
#define _SIMPAN_H__

#include <sys/stat.h>
#include "../../ADT/ADT_MesinTxt/mesintxt.h"
#include "../../ADT/ADT_Profile/profile.h"
#include "../../ADT/ADT_Matrix/matrix.h"
#include "../../ADT/ADT_PermintaanPertemanan/permintaanpertemanan.h"
#include "../../ADT/ADT_Kicauan/kicauan.h"
#include "../../ADT/ADT_Draf/draf.h"
#include "../Utas/utas.h"
#include "../Teman/teman.h"
#include "./simpandanmuat.h"

void simpan(Word foldername);

void simpanPengguna(Word foldername);

void simpanKicauan(Word foldername);

void simpanDraf(Word foldername);

void simpanUtas(Word foldername);

void simpanBalasan(Word foldername);

#endif
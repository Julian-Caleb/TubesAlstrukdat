#ifndef _MUAT_H__
#define _MUAT_H__

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

void muat(Word foldername);

void muatPengguna(Word foldername);

void muatKicauan(Word foldername);

void muatDraf(Word foldername);

void muatUtas(Word foldername);

void muatBalasan(Word foldername);

#endif
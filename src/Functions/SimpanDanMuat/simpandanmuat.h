#ifndef __SIMPAN_MUAT_H__
#define __SIMPAN_MUAT_H__

#include <sys/stat.h>
#include "../../ADT/ADT_MesinTxt/mesintxt.h"
#include "../../ADT/ADT_Profile/profile.h"
#include "../../ADT/ADT_Matrix/matrix.h"
#include "../../ADT/ADT_PermintaanPertemanan/permintaanpertemanan.h"
#include "../../ADT/ADT_Kicauan/kicauan.h"
#include "../Teman/teman.h"

Word addExtension(Word foldername);
/* Menambah .config ke foldername */

Word penggunaFile(Word foldername);
/*  Mengubah foldername menjadi path ke pengguna.config*/

Word balasanFile(Word foldername);
/*  Mengubah foldername menjadi path ke balasan.config*/

Word drafFile(Word foldername);
/*  Mengubah foldername menjadi path ke draf.config*/

Word kicauanFile(Word foldername);
/*  Mengubah foldername menjadi path ke kicauan.config*/

Word utasFile(Word foldername);
/*  Mengubah foldername menjadi path ke utas.config*/

void simpan(Word foldername);
/*  Fungsi simpan menyimpan kondisi ADT ke dalam file confignya 
    masing-masing berdasarkan ADT dan spesifikasi. */ 

void muat(Word foldername);
/*  Fungsi muat menerima file dan menaruhnya kedalam masing-masing
    ADT berdasarkan isi filenya. */


#endif
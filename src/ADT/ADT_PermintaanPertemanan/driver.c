#include <stdio.h>
#include "permintaanpertemanan.h"

int main() {

    MakeEmpty(permintaanPertemanan);

    daftar();
    daftar();
    daftar();
    daftar();
    daftar();

    masuk();
    TambahTeman();
    TambahTeman();
    keluar();

    masuk();
    TambahTeman();
    keluar();

    masuk();
    DaftarPermintaanPertemanan();
    SetujuiPertemanan();
    printf("%d", banyakTeman());

    return 0;
}
#include <stdio.h>
#include "balasan.h"
#include "../ADT_Kicauan/kicauan.h"
#include "../../Functions/Login/login.h"

int main() {

    CreateKicauanExtern(10);

    daftar();
    daftar();

    masuk();
    AddKicau();
    keluar();

    masuk();
    Balas(1, -1);
    Balas(1, 1);
    Balas(1, 2);
    Balas(1, 1);
    CetakBalasan(1);

}
#include <stdio.h>
#include "teman.h"
#include "../Login/login.h"

int main() {

    daftar();
    daftar();
    daftar();

    masuk();

    readGraf(&grafPertemanan, 3);

    printMatrixPertemanan();

    printf("%d", banyakTeman());

    return 0;


}
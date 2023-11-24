#include <stdio.h>
#include "commands.h"

int command_to_int(Word command)
{
    Word daftar,masuk,keluar,tutup_program;
    Word ganti_profil,lihat_profil,atur_jenis_akun,ubah_foto_profil;
    Word daftar_teman,hapus_teman;
    Word tambah_teman,daftar_permintaan_pertemanan,setujui_pertemanan;
    Word kicau,kicauan,suka_kicauan,ubah_kicauan;
    Word balas,balasan,hapus_balasan;
    Word buat_draf,lihat_draf;
    Word utas,sambung_utas,hapus_utas,cetak_utas;
    Word simpan,muat;

    daftar.Length=6;
    daftar.TabWord[0]='D';
    daftar.TabWord[1]='A';
    daftar.TabWord[2]='F';
    daftar.TabWord[3]='T';
    daftar.TabWord[4]='A';
    daftar.TabWord[5]='R';

    masuk.Length=5;
    masuk.TabWord[0]='M';
    masuk.TabWord[1]='A';
    masuk.TabWord[2]='S';
    masuk.TabWord[3]='U';
    masuk.TabWord[4]='K';

    keluar.Length=6;
    keluar.TabWord[0]='K';
    keluar.TabWord[1]='E';
    keluar.TabWord[2]='L';
    keluar.TabWord[3]='U';
    keluar.TabWord[4]='A';
    keluar.TabWord[5]='R';

    tutup_program.Length=13;
    tutup_program.TabWord[0]='T';
    tutup_program.TabWord[1]='U';
    tutup_program.TabWord[2]='T';
    tutup_program.TabWord[3]='U';
    tutup_program.TabWord[4]='P';
    tutup_program.TabWord[5]='_';
    tutup_program.TabWord[6]='P';
    tutup_program.TabWord[7]='R';
    tutup_program.TabWord[8]='O';
    tutup_program.TabWord[9]='G';
    tutup_program.TabWord[10]='R';
    tutup_program.TabWord[11]='A';
    tutup_program.TabWord[12]='M';

    ganti_profil.Length=12;
    ganti_profil.TabWord[0]='G';
    ganti_profil.TabWord[1]='A';
    ganti_profil.TabWord[2]='N';
    ganti_profil.TabWord[3]='T';
    ganti_profil.TabWord[4]='I';
    ganti_profil.TabWord[5]='_';
    ganti_profil.TabWord[6]='P';
    ganti_profil.TabWord[7]='R';
    ganti_profil.TabWord[8]='O';
    ganti_profil.TabWord[9]='F';
    ganti_profil.TabWord[10]='I';
    ganti_profil.TabWord[11]='L';

    lihat_profil.Length=13;
    lihat_profil.TabWord[0]='L';
    lihat_profil.TabWord[1]='I';
    lihat_profil.TabWord[2]='H';
    lihat_profil.TabWord[3]='A';
    lihat_profil.TabWord[4]='T';
    lihat_profil.TabWord[5]='_';
    lihat_profil.TabWord[6]='P';
    lihat_profil.TabWord[7]='R';
    lihat_profil.TabWord[8]='O';
    lihat_profil.TabWord[9]='F';
    lihat_profil.TabWord[10]='I';
    lihat_profil.TabWord[11]='L';
    lihat_profil.TabWord[12]=' ';

    atur_jenis_akun.Length=15;
    atur_jenis_akun.TabWord[0]='A';
    atur_jenis_akun.TabWord[1]='T';
    atur_jenis_akun.TabWord[2]='U';
    atur_jenis_akun.TabWord[3]='R';
    atur_jenis_akun.TabWord[4]='_';
    atur_jenis_akun.TabWord[5]='J';
    atur_jenis_akun.TabWord[6]='E';
    atur_jenis_akun.TabWord[7]='N';
    atur_jenis_akun.TabWord[8]='I';
    atur_jenis_akun.TabWord[9]='S';
    atur_jenis_akun.TabWord[10]='_';
    atur_jenis_akun.TabWord[11]='A';
    atur_jenis_akun.TabWord[12]='K';
    atur_jenis_akun.TabWord[13]='U';
    atur_jenis_akun.TabWord[14]='N';

    ubah_foto_profil.Length=16;
    ubah_foto_profil.TabWord[0]='U';
    ubah_foto_profil.TabWord[1]='B';
    ubah_foto_profil.TabWord[2]='A';
    ubah_foto_profil.TabWord[3]='H';
    ubah_foto_profil.TabWord[4]='_';
    ubah_foto_profil.TabWord[5]='F';
    ubah_foto_profil.TabWord[6]='O';
    ubah_foto_profil.TabWord[7]='T';
    ubah_foto_profil.TabWord[8]='O';
    ubah_foto_profil.TabWord[9]='_';
    ubah_foto_profil.TabWord[10]='P';
    ubah_foto_profil.TabWord[11]='R';
    ubah_foto_profil.TabWord[12]='O';
    ubah_foto_profil.TabWord[13]='F';
    ubah_foto_profil.TabWord[14]='I';
    ubah_foto_profil.TabWord[15]='L';

    daftar_teman.Length=12;
    daftar_teman.TabWord[0]='D';
    daftar_teman.TabWord[1]='A';
    daftar_teman.TabWord[2]='F';
    daftar_teman.TabWord[3]='T';
    daftar_teman.TabWord[4]='A';
    daftar_teman.TabWord[5]='R';
    daftar_teman.TabWord[6]='_';
    daftar_teman.TabWord[7]='T';
    daftar_teman.TabWord[8]='E';
    daftar_teman.TabWord[9]='M';
    daftar_teman.TabWord[10]='A';
    daftar_teman.TabWord[11]='N';

    hapus_teman.Length=11;
    hapus_teman.TabWord[0]='H';
    hapus_teman.TabWord[1]='A';
    hapus_teman.TabWord[2]='P';
    hapus_teman.TabWord[3]='U';
    hapus_teman.TabWord[4]='S';
    hapus_teman.TabWord[5]='_';
    hapus_teman.TabWord[6]='T';
    hapus_teman.TabWord[7]='E';
    hapus_teman.TabWord[8]='M';
    hapus_teman.TabWord[9]='A';
    hapus_teman.TabWord[10]='N';

    tambah_teman.Length=12;
    tambah_teman.TabWord[0]='T';
    tambah_teman.TabWord[1]='A';
    tambah_teman.TabWord[2]='M';
    tambah_teman.TabWord[3]='B';
    tambah_teman.TabWord[4]='A';
    tambah_teman.TabWord[5]='H';
    tambah_teman.TabWord[6]='_';
    tambah_teman.TabWord[7]='T';
    tambah_teman.TabWord[8]='E';
    tambah_teman.TabWord[9]='M';
    tambah_teman.TabWord[10]='A';
    tambah_teman.TabWord[11]='N';

    daftar_permintaan_pertemanan.Length=28;
    daftar_permintaan_pertemanan.TabWord[0]='D';
    daftar_permintaan_pertemanan.TabWord[1]='A';
    daftar_permintaan_pertemanan.TabWord[2]='F';
    daftar_permintaan_pertemanan.TabWord[3]='T';
    daftar_permintaan_pertemanan.TabWord[4]='A';
    daftar_permintaan_pertemanan.TabWord[5]='R';
    daftar_permintaan_pertemanan.TabWord[6]='_';
    daftar_permintaan_pertemanan.TabWord[7]='P';
    daftar_permintaan_pertemanan.TabWord[8]='E';
    daftar_permintaan_pertemanan.TabWord[9]='R';
    daftar_permintaan_pertemanan.TabWord[10]='M';
    daftar_permintaan_pertemanan.TabWord[11]='I';
    daftar_permintaan_pertemanan.TabWord[12]='N';
    daftar_permintaan_pertemanan.TabWord[13]='T';
    daftar_permintaan_pertemanan.TabWord[14]='A';
    daftar_permintaan_pertemanan.TabWord[15]='A';
    daftar_permintaan_pertemanan.TabWord[16]='N';
    daftar_permintaan_pertemanan.TabWord[17]='_';
    daftar_permintaan_pertemanan.TabWord[18]='P';
    daftar_permintaan_pertemanan.TabWord[19]='E';
    daftar_permintaan_pertemanan.TabWord[20]='R';
    daftar_permintaan_pertemanan.TabWord[21]='T';
    daftar_permintaan_pertemanan.TabWord[22]='E';
    daftar_permintaan_pertemanan.TabWord[23]='M';
    daftar_permintaan_pertemanan.TabWord[24]='A';
    daftar_permintaan_pertemanan.TabWord[25]='N';
    daftar_permintaan_pertemanan.TabWord[26]='A';
    daftar_permintaan_pertemanan.TabWord[27]='N';

    setujui_pertemanan.Length=18;
    setujui_pertemanan.TabWord[0]='S';
    setujui_pertemanan.TabWord[1]='E';
    setujui_pertemanan.TabWord[2]='T';
    setujui_pertemanan.TabWord[3]='U';
    setujui_pertemanan.TabWord[4]='J';
    setujui_pertemanan.TabWord[5]='U';
    setujui_pertemanan.TabWord[6]='I';
    setujui_pertemanan.TabWord[7]='_';
    setujui_pertemanan.TabWord[8]='P';
    setujui_pertemanan.TabWord[9]='E';
    setujui_pertemanan.TabWord[10]='R';
    setujui_pertemanan.TabWord[11]='T';
    setujui_pertemanan.TabWord[12]='E';
    setujui_pertemanan.TabWord[13]='M';
    setujui_pertemanan.TabWord[14]='A';
    setujui_pertemanan.TabWord[15]='N';
    setujui_pertemanan.TabWord[16]='A';
    setujui_pertemanan.TabWord[17]='N';

    kicau.Length=5;
    kicau.TabWord[0]='K';
    kicau.TabWord[1]='I';
    kicau.TabWord[2]='C';
    kicau.TabWord[3]='A';
    kicau.TabWord[4]='U';

    kicauan.Length=7;
    kicauan.TabWord[0]='K';
    kicauan.TabWord[1]='I';
    kicauan.TabWord[2]='C';
    kicauan.TabWord[3]='A';
    kicauan.TabWord[4]='U';
    kicauan.TabWord[5]='A';
    kicauan.TabWord[6]='N';

    suka_kicauan.Length=13;
    suka_kicauan.TabWord[0]='S';
    suka_kicauan.TabWord[1]='U';
    suka_kicauan.TabWord[2]='K';
    suka_kicauan.TabWord[3]='A';
    suka_kicauan.TabWord[4]='_';
    suka_kicauan.TabWord[5]='K';
    suka_kicauan.TabWord[6]='I';
    suka_kicauan.TabWord[7]='C';
    suka_kicauan.TabWord[8]='A';
    suka_kicauan.TabWord[9]='U';
    suka_kicauan.TabWord[10]='A';
    suka_kicauan.TabWord[11]='N';
    suka_kicauan.TabWord[12]=' ';

    ubah_kicauan.Length=13;
    ubah_kicauan.TabWord[0]='U';
    ubah_kicauan.TabWord[1]='B';
    ubah_kicauan.TabWord[2]='A';
    ubah_kicauan.TabWord[3]='H';
    ubah_kicauan.TabWord[4]='_';
    ubah_kicauan.TabWord[5]='K';
    ubah_kicauan.TabWord[6]='I';
    ubah_kicauan.TabWord[7]='C';
    ubah_kicauan.TabWord[8]='A';
    ubah_kicauan.TabWord[9]='U';
    ubah_kicauan.TabWord[10]='A';
    ubah_kicauan.TabWord[11]='N';
    ubah_kicauan.TabWord[12]=' ';

    balas.Length=6;
    balas.TabWord[0]='B';
    balas.TabWord[1]='A';
    balas.TabWord[2]='L';
    balas.TabWord[3]='A';
    balas.TabWord[4]='S';
    balas.TabWord[5]=' ';

    balasan.Length=8;
    balasan.TabWord[0]='B';
    balasan.TabWord[1]='A';
    balasan.TabWord[2]='L';
    balasan.TabWord[3]='A';
    balasan.TabWord[4]='S';
    balasan.TabWord[5]='A';
    balasan.TabWord[6]='N';
    balasan.TabWord[7]=' ';

    hapus_balasan.Length=14;
    hapus_balasan.TabWord[0]='H';
    hapus_balasan.TabWord[1]='A';
    hapus_balasan.TabWord[2]='P';
    hapus_balasan.TabWord[3]='U';
    hapus_balasan.TabWord[4]='S';
    hapus_balasan.TabWord[5]='_';
    hapus_balasan.TabWord[6]='B';
    hapus_balasan.TabWord[7]='A';
    hapus_balasan.TabWord[8]='L';
    hapus_balasan.TabWord[9]='A';
    hapus_balasan.TabWord[10]='S';
    hapus_balasan.TabWord[11]='A';
    hapus_balasan.TabWord[12]='N';
    hapus_balasan.TabWord[13]=' ';

    buat_draf.Length=9;
    buat_draf.TabWord[0]='B';
    buat_draf.TabWord[1]='U';
    buat_draf.TabWord[2]='A';
    buat_draf.TabWord[3]='T';
    buat_draf.TabWord[4]='_';
    buat_draf.TabWord[5]='D';
    buat_draf.TabWord[6]='R';
    buat_draf.TabWord[7]='A';
    buat_draf.TabWord[8]='F';

    lihat_draf.Length=10;
    lihat_draf.TabWord[0]='L';
    lihat_draf.TabWord[1]='I';
    lihat_draf.TabWord[2]='H';
    lihat_draf.TabWord[3]='A';
    lihat_draf.TabWord[4]='T';
    lihat_draf.TabWord[5]='_';
    lihat_draf.TabWord[6]='D';
    lihat_draf.TabWord[7]='R';
    lihat_draf.TabWord[8]='A';
    lihat_draf.TabWord[9]='F';

    utas.Length=5;
    utas.TabWord[0]='U';
    utas.TabWord[1]='T';
    utas.TabWord[2]='A';
    utas.TabWord[3]='S';
    utas.TabWord[4]=' ';

    sambung_utas.Length=13;
    sambung_utas.TabWord[0]='S';
    sambung_utas.TabWord[1]='A';
    sambung_utas.TabWord[2]='M';
    sambung_utas.TabWord[3]='B';
    sambung_utas.TabWord[4]='U';
    sambung_utas.TabWord[5]='N';
    sambung_utas.TabWord[6]='G';
    sambung_utas.TabWord[7]='_';
    sambung_utas.TabWord[8]='U';
    sambung_utas.TabWord[9]='T';
    sambung_utas.TabWord[10]='A';
    sambung_utas.TabWord[11]='S';
    sambung_utas.TabWord[12]=' ';

    hapus_utas.Length=11;
    hapus_utas.TabWord[0]='H';
    hapus_utas.TabWord[1]='A';
    hapus_utas.TabWord[2]='P';
    hapus_utas.TabWord[3]='U';
    hapus_utas.TabWord[4]='S';
    hapus_utas.TabWord[5]='_';
    hapus_utas.TabWord[6]='U';
    hapus_utas.TabWord[7]='T';
    hapus_utas.TabWord[8]='A';
    hapus_utas.TabWord[9]='S';
    hapus_utas.TabWord[10]=' ';

    cetak_utas.Length=11;
    cetak_utas.TabWord[0]='C';
    cetak_utas.TabWord[1]='E';
    cetak_utas.TabWord[2]='T';
    cetak_utas.TabWord[3]='A';
    cetak_utas.TabWord[4]='K';
    cetak_utas.TabWord[5]='_';
    cetak_utas.TabWord[6]='U';
    cetak_utas.TabWord[7]='T';
    cetak_utas.TabWord[8]='A';
    cetak_utas.TabWord[9]='S';
    cetak_utas.TabWord[10]=' ';

    simpan.Length=6;
    simpan.TabWord[0]='S';
    simpan.TabWord[1]='I';
    simpan.TabWord[2]='M';
    simpan.TabWord[3]='P';
    simpan.TabWord[4]='A';
    simpan.TabWord[5]='N';

    muat.Length=4;
    muat.TabWord[0]='M';
    muat.TabWord[1]='U';
    muat.TabWord[2]='A';
    muat.TabWord[3]='T';

    if(isWordEqual(command,daftar)){
        return 0;
    }
    else if(isWordEqual(command,masuk)){
        return 1;
    }
    else if(isWordEqual(command,keluar)){
        return 2;
    }
    else if(isWordEqual(command,tutup_program)){
        return 3;
    }
    else if(isWordEqual(command,ganti_profil)){
        return 4;
    }
    else if(isEarlyCharInWordEqual(command,lihat_profil)){
        return 5;
    }
    else if(isWordEqual(command,atur_jenis_akun)){
        return 6;
    }
    else if(isWordEqual(command,ubah_foto_profil)){
        return 7;
    }
    else if(isWordEqual(command,daftar_teman)){
        return 8;
    }
    else if(isWordEqual(command,hapus_teman)){
        return 9;
    }
    else if(isWordEqual(command,tambah_teman)){
        return 10;
    }
    else if(isWordEqual(command,daftar_permintaan_pertemanan)){
        return 11;
    }
    else if(isWordEqual(command,setujui_pertemanan)){
        return 12;
    }
    else if(isWordEqual(command,kicau)){
        return 13;
    }
    else if(isWordEqual(command,kicauan)){
        return 14;
    }
    else if(isEarlyCharInWordEqual(command,suka_kicauan)){
        return 15;
    }
    else if(isEarlyCharInWordEqual(command,ubah_kicauan)){
        return 16;
    }
    else if(isEarlyCharInWordEqual(command,balas)){
        return 17;
    }
    else if(isEarlyCharInWordEqual(command,balasan)){
        return 18;
    }
    else if(isEarlyCharInWordEqual(command,hapus_balasan)){
        return 19;
    }
    else if(isWordEqual(command,buat_draf)){
        return 20;
    }
    else if(isWordEqual(command,lihat_draf)){
        return 21;
    }
    else if(isEarlyCharInWordEqual(command,utas)){
        return 22;
    }
    else if(isEarlyCharInWordEqual(command,sambung_utas)){
        return 23;
    }
    else if(isEarlyCharInWordEqual(command,hapus_utas)){
        return 24;
    }
    else if(isEarlyCharInWordEqual(command, cetak_utas)){
        return 25;
    }
    else if(isWordEqual(command,simpan)){
        return 26;
    }
    else if(isWordEqual(command,muat)){
        return 27;
    }
    else{
        return -999;
    }
}

Word parameterWord(Word command)
{
    int length = 0;
    int newlength,i;
    Word retval;
    while(command.TabWord[length]!=' ')
    {
        length++;
    }
    newlength = command.Length-length;
    retval.Length = newlength-1;
    length++;
    for(i=0;i<newlength;i++){
        retval.TabWord[i] = command.TabWord[length];
        length++;
    }
    return retval;
}

int oneIntParam(Word command)
{
    int length = 0;
    int newlength,i;
    int retval = 0;
    while(command.TabWord[length]!=' ')
    {
        length++;
    }
    newlength = command.Length-length;
    length++;
    for(i=0;i<newlength-1;i++){
        retval = retval*10 + (command.TabWord[length]-'0');
        length++;
    }
    return retval;
}

int twoIntParamFirst(Word command)
{
    int firstspace;
    int scndspace = 0;
    int retval = 0;
    int i;
    while(command.TabWord[scndspace]!=' ')
    {
        scndspace++;
    }
    firstspace = scndspace;
    scndspace++;
    while(command.TabWord[scndspace]!=' ')
    {
        scndspace++;
    }
    for(i=firstspace+1;i<scndspace;i++){
        retval = retval*10 + (command.TabWord[i]-'0');
    }
    return retval;
}

int twoIntParamSecond(Word command)
{
    int scndspace = 0;
    int retval = 0;
    int i;
    while(command.TabWord[scndspace]!=' ')
    {
        scndspace++;
    }
    scndspace++;
    while(command.TabWord[scndspace]!=' ')
    {
        scndspace++;
    }
    for(i=scndspace+1;command.TabWord[i]!='\0';i++){
        retval = retval*10 + (command.TabWord[i]-'0');
    }
    return retval;
}
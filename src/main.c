#include <stdio.h>
#include "./ADT/ADT_Boolean/boolean.h"
#include "./ADT/ADT_Balasan/balasan.h"
#include "./ADT/ADT_Datetime/datetime.h"
#include "./ADT/ADT_Draf/draf.h"
#include "./ADT/ADT_Graf/graf.h"
#include "./ADT/ADT_Kicauan/kicauan.h"
#include "./ADT/ADT_Matrix/matrix.h"
#include "./ADT/ADT_MesinKar/mesinkar.h"
#include "./ADT/ADT_MesinKata/mesinkata.h"
#include "./ADT/ADT_MesinTxt/mesintxt.h"
#include "./ADT/ADT_PermintaanPertemanan/permintaanpertemanan.h"
#include "./ADT/ADT_Profile/profile.h"
#include "./ADT/ADT_User/user.h"
#include "./Functions/Commands/commands.h"
#include "./Functions/Login/login.h"
#include "./Functions/PColor/pcolor.h"
#include "./Functions/SimpanDanMuat/muat.h"
#include "./Functions/SimpanDanMuat/simpan.h"
#include "./Functions/Teman/teman.h"
#include "./Functions/Utas/utas.h"

int main() {

    // Inisialisasi
    int choice;
    boolean running = true;
    currentUser.id = -1;


    printf(".______    __    __  .______      .______    __  .______  \n");
    printf("|   _  \\  |  |  |  | |   _  \\     |   _  \\  |  | |   _  \\\n");
    printf("|  |_)  | |  |  |  | |  |_)  |    |  |_)  | |  | |  |_)  |\n");    
    printf("|   _  <  |  |  |  | |      /     |   _  <  |  | |      /\n");     
    printf("|  |_)  | |  `--'  | |  |\\  \\----.|  |_)  | |  | |  |\\  \\----.\n");
    printf("|______/   \\______/  | _| `._____||______/  |__| | _| `._____|\n");
    printf("\n");

    printf("Selamat datang di BurBir.\n");
    printf("Aplikasi untuk studi kualitatif mengenai perilaku manusia dengan menggunakan metode (pengambilan data berupa) Focused Group Discussion kedua di zamannya.\n");
    printf("\n");

    printf("Silahkan masukan folder konfigurasi untuk dimuat: ");
    STARTWORD();
    printf("\n");
    muat(currentWord);

    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");
    printf("\n");

    while (running) {
        
        printf(">> ");
        STARTSENTENCE();
        choice = command_to_int(currentWord);
        printf ("\033c");
        switch (choice) {
            case 0:
                daftar();
                break;
            case 1:
                masuk();
                break;
            case 2:
                keluar();
                break;
            case 3:
                running = false;
                printf("Anda telah keluar dari program BurBir. Sampai jumpa di penjelajahan berikutnya.\n");
                break;
            case 4:
                gantiProfil();
                break;
            case 5:
                lihatProfil(parameterWord(currentWord));
                break;
            case 6:
                aturJenisAkun(); 
                break;
            case 7:
                ubahFotoProfil();
                break;
            case 8:
                daftarTeman();
                break;
            case 9:
                //hapus teman
                break;
            case 10:
                // tambah teman
                break;
            case 11:
                // daftar friend request
                break;
            case 12:
                // setujui pertemnanan
                break;
            case 13:
                // kicau
                break;
            case 14:
                // kicauan
                break;
            case 15:
                // suka kicauan
                break;
            case 16:
                // ubah kicauan
                break;
            case 17:
                // balas
                break;
            case 18:
                // suka kicauan
                break;
            case 19:
                // hapus balasan
                break;
            case 20:
                // buat draf
                break;
            case 21:
                // lihat draf
                break;
            case 22:
                // utas
                break;
            case 23:
                // sambung utas
                break;
            case 24:
                // hapus utas
                break;
            case 25:
                // cetak utas
                break;
            case 26:
                //simpan
                break;
            case 27:
                // muat
                break;
            case -999:
                printf("Perintah Invalid, cek kembali penulisan perintah atau parameter perintah\n");
                break;
            default:
                break;
        }

    }

    return 0;
    
}
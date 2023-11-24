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
                hapusTeman();
                break;
            case 10:
                TambahTeman();
                break;
            case 11:
                DaftarPermintaanPertemanan();
                break;
            case 12:
                SetujuiPertemanan();
                break;
            case 13:
                AddKicau();
                break;
            case 14:
                PrintKicau();
                break;
            case 15:
                SukaKicau(oneIntParam(currentWord));
                break;
            case 16:
                UbahKicau(oneIntParam(currentWord));
                break;
            case 17:
                Balas(twoIntParamFirst(currentWord),twoIntParamSecond(currentWord));
                break;
            case 18:
                CetakBalasan(oneIntParam(currentWord));
                break;
            case 19:
                HapusBalasan(twoIntParamFirst(currentWord),twoIntParamSecond(currentWord));
                break;
            case 20:
                BuatDraf();
                break;
            case 21:
                LihatDraf();
                break;
            case 22:
                AddUtas(oneIntParam(currentWord));
                break;
            case 23:
                SambungUtas(twoIntParamFirst(currentWord),twoIntParamSecond(currentWord));
                break;
            case 24:
                HapusUtas(twoIntParamFirst(currentWord),twoIntParamSecond(currentWord));
                break;
            case 25:
                CetakUtas(oneIntParam(currentWord));
                break;
            case 26:
                printf("Masukkan nama folder : ");
                STARTSENTENCE();
                simpan(currentWord);
                break;
            case 27:
                if(!isLoggedIn){
                    printf("Masukkan nama folder : ");
                    STARTSENTENCE();
                    muat(currentWord);
                }
                else{
                    printf("Keluar terlebih dahulu untuk melakukan muat!");
                }
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
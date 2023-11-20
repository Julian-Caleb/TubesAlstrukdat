#include <stdio.h>
#include "./ADT/ADT_MesinKata/mesinkata.h"
#include "./ADT/ADT_Boolean/boolean.h"

int main() {

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
    printf("File konfigurasi berhasil dimuat! Selamat berkicau!\n");

    while (true) {
        
        STARTWORD();

        if (currentWord.TabWord[0] == 'a') {
            break;
        } else {
            printWord(currentWord);
        }

    }


    
}
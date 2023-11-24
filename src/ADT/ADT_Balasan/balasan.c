#include <stdio.h>
#include "balasan.h"
#include "../ADT_Kicauan/kicauan.h"

AddressBalasan newBalasan() {
    Balasan *balasan = (Balasan *)malloc(sizeof(Balasan));
    if (balasan != NULL) {
        balasan->sibling = NULL;
        balasan->child = NULL;
    }
    return balasan;    
}

AddressBalasan makeBalasan(int idBalasanBaru) {
    AddressBalasan b = newBalasan();
    while (b == NULL) {
        printf("Alokasi memori gagal!");
        b = newBalasan();
    } 
    printf("Masukkan kicau:\n");
    STARTSENTENCE();
    printf("\n");
    while (isKicauAllSpace(currentWord)) {
        printf("Kicau tidak boleh hanya berisi spasi!");
        STARTSENTENCE();
        printf("\n");
    }
    b->idBalasan = idBalasanBaru;
    b->nama = currentUser.username;
    b->time = setTime();
    b->kicau = CopyToNewWord(currentWord);
    return b;
}

void Balas(int index, int idBalasan) {
    int idBalasanBaru;
    AddressBalasan b, newb;
    if(isLoggedIn){
        if (!isIdExist(index)) {
            printf("Wah, tidak terdapat kicauan yang ingin Anda balas!");
        } else if (!(idBalasan == -1 || (idBalasan >= 1 && idBalasan <= TotalBalasanDariKicauan(index)))) {
            printf("Wah, tidak terdapat balasan yang ingin Anda balas!");
        } else if (arrayOfProfile.buffer[index-1].private && !isTeman(kicauan.buffer[index-1].nama)) {
            printf("Wah, akun tersebut merupakan akun privat dan anda belum berteman dengan akun tersebut!");    
        } else {
            idBalasanBaru = MaxIdBalasan(kicauan.buffer[index-1].balasan);
            newb = makeBalasan(idBalasanBaru + 1);
            if (idBalasan == -1) {
                if (kicauan.buffer[index-1].balasan == NULL) {
                    kicauan.buffer[index-1].balasan = newb;
                } else {
                    b = kicauan.buffer[index-1].balasan;
                    while (b->sibling != NULL) {
                        b = b->sibling;
                    }
                    b->sibling = newb;
                }        
            } else {
                b = CariBalasanDariKicau(index, idBalasan);
                if (b->child == NULL) {
                    b->child = newb;
                } else {
                    b = b->child;
                    while (b->sibling != NULL) {
                        b = b->sibling;
                    }
                    b->sibling = newb;
                }
            }
            printf("Selamat, balasan telah diterbitkan!\n");
            CetakBalasanSingular(newb);
        }
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void CetakBalasanCertainId(int index, int idBalasan) {
    AddressBalasan balasan = CariBalasanDariKicau(index, idBalasan);
    printf("| ");
    printf("ID = %d", balasan->idBalasan);
    printf("\n");
    printf("| ");
    printWordNoNewLine(balasan->nama);
    printf("\n");
    printf("| ");
    displayTime(balasan->time);
    printf("\n");
    printf("| ");
    printWordNoNewLine(balasan->kicau);
    printf("\n");
    printf("\n");
}

void CetakBalasanSingular(AddressBalasan balasan) {
    printf("| ");
    printf("ID = %d", balasan->idBalasan);
    printf("\n");
    printf("| ");
    printWordNoNewLine(balasan->nama);
    printf("\n");
    printf("| ");
    displayTime(balasan->time);
    printf("\n");
    printf("| ");
    printWordNoNewLine(balasan->kicau);
    printf("\n");
    printf("\n");
}

void CetakBalasan(int index) {
    if(isLoggedIn){
        CetakBalasanIndented(kicauan.buffer[index-1].balasan, 0);
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void CetakBalasanIndented(AddressBalasan balasan, int level) {
    if (balasan != NULL) {
        for (int i = 0; i < level; ++i) {
            printf("\t");
        }
        printf("| ");
        printf("ID = %d", balasan->idBalasan);
        printf("\n");
        for (int i = 0; i < level; ++i) {
            printf("\t");
        }
        printf("| ");
        printWordNoNewLine(balasan->nama);
        printf("\n");
        for (int i = 0; i < level; ++i) {
            printf("\t");
        }
        printf("| ");
        displayTime(balasan->time);
        printf("\n");
        for (int i = 0; i < level; ++i) {
            printf("\t");
        }
        printf("| ");
        printWordNoNewLine(balasan->kicau);
        printf("\n");
        printf("\n");
        
        AddressBalasan current = balasan->child;
        while (current != NULL) {
            CetakBalasanIndented(current, level + 1);
            current = current->sibling;
        }
    }
}

void HapusBalasan(int index, int idBalasan) {
    AddressBalasan b, beforeb;
    if(isLoggedIn){
        if (!isIdExist(index)) {
            printf("Wah, tidak terdapat kicauan yang ingin Anda hapus balasannya!");
        } else if (!(idBalasan == -1 || (idBalasan >= 1 && idBalasan <= TotalBalasanDariKicauan(index)))) {
            printf("Wah, tidak terdapat balasan yang ingin Anda hapus!");
        } else {
            b = CariBalasanDariKicau(index, idBalasan);
            if (!isWordEqual(b->nama, currentUser.username)) {
                printf("Ini bukan balasan Anda!");
            } else {
                if (kicauan.buffer[index-1].balasan == b) {
                    kicauan.buffer[index-1].balasan = b->sibling;
                } else {
                    beforeb = CariParent(kicauan.buffer[index-1].balasan, b);
                    if (beforeb != NULL) {
                        beforeb->child = b->sibling;
                    } else {
                        beforeb = CariPreSibling(kicauan.buffer[index-1].balasan, b);
                        beforeb->sibling = b->sibling;
                    }
                }
                DealokasiBalasan(b);
            }
        }
    }
    else{
        printf("Anda belum login! Masuk terlebih dahulu untuk menikmati layanan BurBir.\n");
    }
}

void DealokasiBalasan(AddressBalasan balasan) {
    if (balasan != NULL) {
        DealokasiBalasan(balasan->child);
        DealokasiBalasan(balasan->sibling);
        free(balasan);
    }
}

AddressBalasan CariBalasanDariKicau(int index, int idBalasan) {
    AddressBalasan b;
    if (!isIdExist(index)) {
        b = NULL;
    } else {
        b = CariBalasan(kicauan.buffer[index-1].balasan, idBalasan);
    }
    return b;
}

AddressBalasan CariBalasan(AddressBalasan balasan, int idBalasan) {
    AddressBalasan foundBalasan;
    if (balasan->idBalasan == idBalasan) {
        return balasan;
    }
    foundBalasan = CariBalasan(balasan->child, idBalasan);
    if (foundBalasan == NULL) {
        foundBalasan = CariBalasan(balasan->sibling, idBalasan);
    }
    return foundBalasan;
}

AddressBalasan CariParent(AddressBalasan balasanParent, AddressBalasan balasan) {
    if (balasanParent == NULL) {
        return NULL;
    }
    if (balasanParent->child == balasan) {
        return balasanParent;
    }
    AddressBalasan foundParent = CariParent(balasanParent->child, balasan); 
    if (foundParent == NULL) {
        foundParent = CariParent(balasanParent->sibling, balasan);
    }
    return foundParent;
}

AddressBalasan CariPreSibling(AddressBalasan balasanPreSibling, AddressBalasan balasan) {
    if (balasanPreSibling == NULL || balasanPreSibling->sibling == NULL || balasanPreSibling->sibling == balasan) {
        return NULL;
    }
    if (balasanPreSibling->sibling->sibling == balasan) {
        return balasanPreSibling->sibling;
    }
    AddressBalasan foundPreSibling = CariPreSibling(balasanPreSibling->sibling, balasan); // Search in the sibling subtree
    if (foundPreSibling == NULL) {
        foundPreSibling = CariPreSibling(balasanPreSibling->child, balasan); // Search in the child subtree
    }
    return foundPreSibling;
}

int TotalBalasanDariKicauan(int index) {
    int totalBalasan;
    if (!isIdExist(index)) {
        totalBalasan = -999;
    } else {
        totalBalasan = TotalBalasan(kicauan.buffer[index-1].balasan);
    }
    return totalBalasan;
}

int TotalBalasan(AddressBalasan balasan) {
    if (balasan == NULL) {
        return 0;
    } else {
        int totalBalasan = 1; 
        totalBalasan += TotalBalasan(balasan->child);   
        totalBalasan += TotalBalasan(balasan->sibling);
        return totalBalasan;
    }
}

int MaxIdBalasan(AddressBalasan balasan) {
    if (balasan == NULL) {
        return 0; 
    }
    int maxId = balasan->idBalasan;
    int childMaxId = MaxIdBalasan(balasan->child);
    int siblingMaxId = MaxIdBalasan(balasan->sibling);
    
    if (childMaxId > maxId) {
        maxId = childMaxId;
    }
    if (siblingMaxId > maxId) {
        maxId = siblingMaxId;
    }
    return maxId;
}
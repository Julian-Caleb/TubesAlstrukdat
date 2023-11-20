#ifndef __USER_H__
#define __USER_H__

#include "../ADT_Boolean/boolean.h"
#include "../ADT_MesinKata/mesinkata.h"

#define CAPACITYNAMA 20

typedef struct {
    Word username; 
    Word password;
    int id;
} User;

void setUser(User *user, Word namaInput, Word sandiInput);

boolean isUsernameValid (Word namaInput);

boolean isPasswordValid (Word sandiInput);


#endif

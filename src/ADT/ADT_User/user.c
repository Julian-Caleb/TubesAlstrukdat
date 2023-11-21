#include <stdio.h>
#include "user.h"

void setUser(User *user, Word namaInput, Word sandiInput, int id) {
    if (isUsernameValid(namaInput)) {
        (*user).username = namaInput;
    } 
    if (isPasswordValid(sandiInput)) {
        (*user).password = sandiInput;
    }
    (*user).id = id;
}

boolean isUsernameValid (Word namaInput) {
    return (namaInput.Length <= 20);
}

boolean isPasswordValid (Word sandiInput) {
    return (sandiInput.Length <= 20);
}
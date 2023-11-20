#ifndef __LOGIN_H__
#define __LOGIN_H__

#include "../../ADT/ADT_Boolean/boolean.h"
#include "../../ADT/ADT_MesinKata/mesinkata.h"
#include "../../ADT/ADT_User/user.h"
#include "../../ADT/ADT_Profile/profile.h"

extern boolean isLoggedIn;
extern User currentUser;
extern ArrayOfProfile arrayOfProfile;

void daftar();

void masuk();

void keluar();

boolean isUnameExist(Word uname);

boolean isPasswordExist(Word pass);

#endif



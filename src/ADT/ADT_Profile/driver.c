#include <stdio.h>
#include "profile.h"

int main() {

    Word temp, weton, no;
    Profile profile;

    temp.TabWord[0] = 'a';
    temp.Length = 1;

    weton.TabWord[0] = 'p';
    weton.TabWord[1] = 'o';
    weton.TabWord[2] = 'n';
    weton.Length = 3;

    no.TabWord[0] = '1';
    no.Length = 1;

    setUsername(&profile, temp);
    setPassword(&profile, temp);
    setBio(&profile, temp);
    setNomorHP(&profile, no);
    setWeton(&profile, weton);
    displayProfile(profile);

    return 0;

}
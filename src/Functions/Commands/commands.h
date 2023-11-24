#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "../../ADT/ADT_Boolean/boolean.h"
#include "../../ADT/ADT_MesinKata/mesinkata.h"

int command_to_int(Word command);

Word parameterWord(Word command);

int oneIntParam(Word command);

int twoIntParamFirst(Word command);

int twoIntParamSecond(Word command);

#endif
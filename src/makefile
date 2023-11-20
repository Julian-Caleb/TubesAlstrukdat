CC = gcc
CFLAGS = -Wall -Werror -std=c11

# List program dan ADT
# Main program
SRC_MAIN = main.c
OBJ_MAIN = $(SRC_MAIN:.c=.o)

# Test program
SRC_TEST = test.c
OBJ_TEST = $(SRC_TEST:.c=.o)

# Driver program
SRC_DRIVER = ADT/ADT_Profile/driver.c
OBJ_DRIVER = $(SRC_DRIVER:.c=.o)

# ADT MesinKar
SRC_MESINKAR = ADT/ADT_MesinKar/mesinkar.c
OBJ_MESINKAR = $(SRC_MESINKAR:.c=.o)

# ADT MesinKata
SRC_MESINKATA = ADT/ADT_MesinKata/mesinkata.c
OBJ_MESINKATA = $(SRC_MESINKATA:.c=.o)

# ADT Matrix
SRC_MATRIX = ADT/ADT_Matrix/matrix.c
OBJ_MATRIX = $(SRC_MATRIX:.c=.o)

# ADT User
SRC_USER = ADT/ADT_User/user.c
OBJ_USER = $(SRC_USER:.c=.o)

# ADT Matrix
SRC_PROFILE = ADT/ADT_Profile/profile.c
OBJ_PROFILE = $(SRC_PROFILE:.c=.o)

# Functions Login
SRC_LOGIN = Functions/Login/login.c
OBJ_LOGIN = $(SRC_LOGIN:.c=.o)

# Functions PColor
SRC_PCOLOR = Functions/PColor/pcolor.c
OBJ_PCOLOR = $(SRC_PCOLOR:.c=.o)

.PHONY: all clean test

# Nama file executable
all: main_program 

# Compiling and building
main_program: $(OBJ_DRIVER) $(OBJ_MESINKAR) $(OBJ_MESINKATA) $(OBJ_MATRIX) $(OBJ_USER) $(OBJ_PROFILE) $(OBJ_LOGIN) $(OBJ_PCOLOR)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program $(OBJ_DRIVER) $(OBJ_MESINKAR) $(OBJ_MESINKATA) $(OBJ_MATRIX) $(OBJ_USER) $(OBJ_PROFILE) $(OBJ_LOGIN) $(OBJ_PCOLOR)

run: all
	./main_program	


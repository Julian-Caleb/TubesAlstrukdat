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
SRC_DRIVER = Functions/Teman/driver.c
OBJ_DRIVER = $(SRC_DRIVER:.c=.o)

# ADT MesinKar
SRC_MESINKAR = ADT/ADT_MesinKar/mesinkar.c
OBJ_MESINKAR = $(SRC_MESINKAR:.c=.o)

# ADT MesinKata
SRC_MESINKATA = ADT/ADT_MesinKata/mesinkata.c
OBJ_MESINKATA = $(SRC_MESINKATA:.c=.o)

# ADT MesinTxt
SRC_MESINTXT = ADT/ADT_MesinTxt/mesintxt.c
OBJ_MESINTXT = $(SRC_MESINTXT:.c=.o)

# ADT Matrix
SRC_MATRIX = ADT/ADT_Matrix/matrix.c
OBJ_MATRIX = $(SRC_MATRIX:.c=.o)

# ADT Graf
SRC_GRAF = ADT/ADT_Graf/graf.c
OBJ_GRAF = $(SRC_GRAF:.c=.o)

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

# Functions PColor
SRC_TEMAN = Functions/Teman/teman.c
OBJ_TEMAN = $(SRC_TEMAN:.c=.o)

# Functions SimpanDanMuat
SRC_SIMPANDANMUAT = Functions/SimpanDanMuat/simpandanmuat.c
OBJ_SIMPANDANMUAT = $(SRC_SIMPANDANMUAT:.c=.o)

.PHONY: all clean test

# Nama file executable
all: main_program 

# Compiling and building
main_program: $(OBJ_DRIVER) $(OBJ_MESINKAR) $(OBJ_MESINKATA) $(OBJ_MESINTXT) $(OBJ_MATRIX) $(OBJ_GRAF) $(OBJ_USER) $(OBJ_PROFILE) $(OBJ_LOGIN) $(OBJ_PCOLOR) $(OBJ_TEMAN) $(OBJ_SIMPANDANMUAT)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f main_program $(OBJ_DRIVER) $(OBJ_MESINKAR) $(OBJ_MESINKATA) $(OBJ_MESINTXT) $(OBJ_MATRIX) $(OBJ_GRAF) $(OBJ_USER) $(OBJ_PROFILE) $(OBJ_LOGIN) $(OBJ_PCOLOR) $(OBJ_TEMAN) $(OBJ_SIMPANDANMUAT)

run: all
	./main_program	


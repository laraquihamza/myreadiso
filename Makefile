SRC = $(wildcard src/*.c)
OBJ= ${SRC:.c=.o}
CFLAGS= -Wall -Wextra -Werror -pedantic -std=c99
all: my_read_iso
my_read_iso: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o my_read_iso

test: all
	tests/test.sh
clean:  all
	rm $(OBJ) my_read_iso
	rm -rf tests/dir* tests/TOTO.TXT


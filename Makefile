PRJ=error.o interpret.o htab_free.o htab_clear.o htab_init.o htab_typ.o hash_function.o htab_lookup.o lexana.o  mystring.o  paser.o
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -lm

interpret: error.o interpret.o htab_free.o htab_clear.o htab_init.o htab_typ.o hash_function.o htab_lookup.o lexana.o  mystring.o  paser.o 

	$(CC) error.o interpret.o htab_free.o htab_clear.o htab_init.o htab_typ.o hash_function.o htab_lookup.o lexana.o  paser.o mystring.o  -lm -o interpret

clean:
	$(RM)   *.o
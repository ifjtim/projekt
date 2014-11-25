PRJ=error.o interpret.o htab_free.o htab_clear.o htab_init.o htab_typ.o hash_function.o htab_lookup.o lexana.o   string.o
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -lm

interpret: $(PRJ)
	$(CC) $(CFLAGS) $(PRJ) -o interpret

funkce.o: error.c htab_free.c htab_clear.c htab_init.c htab_typ.c hash_function.c htab_lookup.c lexana.c string.c
	$(CC) $(CFLAGS) error.c htab_free.c htab_clear.c htab_init.c htab_typ.c hash_function.c htab_lookup.c lexana.c string.c  -c

main.o: interpret.c interpret.h 
	$(CC) $(CFLAGS) main.c -c
	
clean:
	rm -f *.o *.out $(PRJ)
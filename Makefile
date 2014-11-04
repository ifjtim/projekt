PRJ=error.o interpret.o
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -lm

interpret: $(PRJ)
	$(CC) $(CFLAGS) $(PRJ) -o interpret

funkce.o: error.c
	$(CC) $(CFLAGS) error.c -c

main.o: interpret.c interpret.h
	$(CC) $(CFLAGS) main.c -c

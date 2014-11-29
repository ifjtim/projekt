PRJ=error.o interpret.o ial.o lexana.o  mystring.o  paser.o
CC=gcc
CFLAGS=-Wall -std=c99 -pedantic -lm

interpret: error.o interpret.o ial.o lexana.o  mystring.o  paser.o 

	$(CC) error.o interpret.o ial.o lexana.o  paser.o mystring.o  -lm -o interpret

clean:
	$(RM)   *.o
	
CFLAGS=-std=c99 -Wall -pedantic -g
BIN=interpret
CC=gcc
RM=rm -f

ALL: error.o interpret.o ial.o lexana.o  mystring.o  paser.o main.o
	$(CC) $(CFLAGS) -o $(BIN) error.o interpret.o ial.o lexana.o  mystring.o  paser.o main.o

clean:
	$(RM) *.o $(BIN)
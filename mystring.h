
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct String{
  int length;
  char *data;
  int allocSize;
} string;


int lenght(string *s);
int newStrAlloc(char *p);
int newStr(char *p);
int cString(string *s1, char *p);
int strAddChar(string *s1, char c);
int strInit(string *s);
void strFree(string *s);
char *copy(string *s, int i, int n);
 /*	hm
  *		tak
  *	tohle
  *		bude
  *	pekny
  *		orisek
  *	damy
  *		a
  *	panove
  */

 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct String{
  int length;
  char *data;
  int allocSize;
} string;

string str_g;



int newStrAlloc(char *p);
int newStr(char *p);

int cString(string *s1, char *p);

int strAddChar(string *s1, char c);

int strInit(string *s);

void strFree(string *s);
int length(string *s);

char *copy(string *s, int i, int n);
char *strPlusStr(string *s1, string *s2);


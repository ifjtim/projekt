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

void cString(string *s1, string *p);

int strAddChar(string *s1, char c);

int strInit(string *s);
void clearStr(string *s);
void strFree(string *s);
int length(string *s);

char *copy(string *s, int i, int n);
char *strPlusStr(string *s1, string *s2);

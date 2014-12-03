#ifndef my_H
#define my_H 
 
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


typedef struct {
  int length;
  char *data;
  int allocSize;
} string1;

string1 str_g;



void cString(string1 *s1, string1 *p);

int strAddChar(string1 *s1, char c);

int strInit(string1 *s);
void clearStr(string1 *s);
void strFree(string1 *s);
int length(string1 *s);

char *copy(string1 *s, int i, int n);
char *strPlusStr(string1 *s1, string1 *s2);
#endif
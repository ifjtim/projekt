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
} string;

string str_g;

void bLast(string *search, int *last);
int find(string *s, string *search);

char *sort(string *s);

void cString(string *s1, string *p);

int strAddChar(string *s1, char c);

int strInit(string *s);
void clearStr(string *s);
void strFree(string *s);
int length(string *s);

char *copy(string *s, int i, int n);
char *strPlusStr(string *s1, string *s2);

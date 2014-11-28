  
#include <string.h>  
#include <stdio.h>

 typedef struct String{
  int length;
  char *data;
  int allocSize;
} string;



void bLast(string *search, int *last);
int find(string *s, string *search);

char *sort(string *s);

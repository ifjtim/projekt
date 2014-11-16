
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

typedef struct SubString{
  int length;
  char *data;
  int allocSize;
} substring;

int lenght(string *s);
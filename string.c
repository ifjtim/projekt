#include "interpret.h"

int newStr(char *p)
{
  unsigned int i = 0;
  char c;
  while((c = getchar()) != '\n')
  { 
    if (i >= strlen(p)) 
    {
      p = (char *) realloc(p, strlen(p) + 1);
    }
    p[i] = c;
    i++;
  }
  return 1;
}

int strAddChar(string *s1, char c)
// prida na konec retezce jeden znak
{
   if (s1->length + 1 >= s1->allocSize)
   {
      if ((s1->data = (char*) realloc(s1->data, s1->length + 8)) == NULL)
         return -1;
      s1->allocSize = s1->length + 8;
   }
   s1->data[s1->length] = c;
   s1->length++;
   s1->data[s1->length] = '\0';
   return 1;
}

int strInit(string *s)
// funkce vytvori novy retezec
{
   if ((s->data = (char*) malloc(8)) == NULL)
      return -1;
   s->data[0] = '\0';
   s->length = 0;
   s->allocSize = 8;
   return 1;
}

void strFree(string *s)
{
   free(s->data);
}

int length(string *s)
{
  return s->length;
}

char *copy(string *s, int i, int n)	// hmhm potreba dodelat tuto fci
{					// nevim do ceho ukladat podretezec
  i -=1;
  char ch[n];
  ch[n] = '\0';
  if ((i+n-1) > s->length)
  {
    return '\0';
  }
  else
  {
    for (int l = 0; l < n ; l++)
    {
      ch[l] = s->data[i++];
    }
    printf("substring = %s\n", ch);
   // return ch;			// :((
  }
  return "a";
}
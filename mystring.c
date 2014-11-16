#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mystring.h"

int newStrAlloc(char *p);
int newStr(char *p);
int cString(string *s1, char *p);
int strAddChar(string *s1, char c);
int strInit(string *s);
void strFree(string *s);
int length(string *s);
char *copy(string *s, int i, int n);

int main()
{
  string str;
  char *p;
  if ((p = malloc(sizeof(char))) == NULL)
  {
    return 0;
  }
  int strlength = 0;
  if (strInit(&str) != 1)
  {
    return 0;
  }
  printf("Zadejte retezec:\n");
  if (newStr(p) != 1) 
  {
    return 0;
  }
  printf("string = %s\n", p);
  cString(&str, p);
  printf("cString = %s\n", str.data);
  if (strlength < 0)
  {
    printf("Neplatny retezec\n");
    return 0;
  }
  else
  {
    printf("Delka retezce je:%d\n", length(&str));
  }
  int i, n;
  printf("Podretezec: zadejte parametry funkce\ni = zacatek\n");
  scanf("%d", &i);
  printf("n = delka\n");
  scanf("%d", &n);
  if (*copy(&str, i, n) == '\0')
  {
    return 0;
  }
  strFree(&str);
  return 0;
}

int cString(string *s1, char *p)
{
  int lenp = strlen(p);
  char ascii = 0;
  int len = 0;
  int index = 1;
  s1->length = strlen(s1->data);
  if ((p[0] != '\'') && (p[lenp-1] != '\'')) 
  {
    return -1;
  }
  else 
  {
    while (index < lenp-1)
    {
      if (p[index] != '\'')
      {
	strAddChar(s1, p[index]);
	index++;
	len++;
      }
      else
      {
	index++;
	if (p[index] == '\'')
	{
	  strAddChar(s1, p[index]);
	  len++;
	  index++;
	}
	else if (p[index] == '\0')
	{
	  return len;
	}
	else if (p[index] != '#')
	{
	  return -3;
	}
	else
	{
	  int isnum = -1;
	  index++;
	  while (p[index] >= '0' && p[index] <= '9')
	  {
	    if (isnum == -1) 
	    {
	      int num = 0;
	      if ((num = strtol(&p[index], NULL, 10)) <= 255)
	      {
		ascii = num;
	      }
	    }
	    index++;
	    isnum = 1;
	  }
	  if (p[index] != '\'' || isnum == -1)
	  {
	    return -2;
	  }
	  else
	  {
	    strAddChar(s1, ascii);
	    len++;
	    index++;
	  }
	}
      }
    }
    s1->length = len;
    return len;
  }
}

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
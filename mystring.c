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
#include "mystring.h"
#include "ial.h"


void cString(string1 *s1, string1 *p)
{
  int lenp = strlen(p->data);
  char ascii = 0;
  int len = 0;
  int index = 1;
  p->length = strlen(p->data);
  if ((p->data[0] != '\'') && (p->data[lenp-1] != '\'')) 
  {
    error(4);
  }
  else 
  {
    while (index < lenp-1)
    {
      if (p->data[index] != '\'')
      {
	strAddChar(s1, p->data[index]);
	index++;
	len++;
      }
      else
      {
	index++;
	if (p->data[index] == '\'')
	{
	  strAddChar(s1, p->data[index]);
	  len++;
	  index++;
	}
	else if (p->data[index] == '\0')
	{
	  error(4);
	}
	else if (p->data[index] != '#')
	{
	  error(4);
	}
	else
	{
	  int isnum = -1;
	  index++;
	  while (p->data[index] >= '0' && p->data[index] <= '9')
	  {
	    if (isnum == -1) 
	    {
	      int num = 0;
	      if ((num = strtol(&p->data[index], NULL, 10)) <= 255)
	      {
		ascii = num;
	      }
	    }
	    index++;
	    isnum = 1;
	  }
	  if (p->data[index] != '\'' || isnum == -1)
	  {
	    error(4);
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
  }
}

int strAddChar(string1 *s1, char c)
{
   if (s1->length + 1 >= s1->allocSize)
   {
      if ((s1->data = (char*) realloc(s1->data, s1->length + 8)) == NULL)
        error(99);
      s1->allocSize = s1->length + 8;
   }
   s1->data[s1->length] = c;
   s1->length++;
   s1->data[s1->length] = '\0';
   return 1;
}

int strInit(string1 *s)
{
   if ((s->data = (char*) malloc(8)) == NULL)
      error(99);
   s->data[0] = '\0';
   s->length = 0;
   s->allocSize = 8;
   return 1;
}

void clearStr(string1 *s)
{
  s->data[0] = '\0';
  s->length = 0;
}

void strFree(string1 *s)
{
   free(s->data);
}

int length(string1 *s)
{
  return s->length;
}

char *copy(string1 *s, int i, int n)	// hmhm potreba dodelat tuto fci
{
  char *s2 = NULL;
  if ((s2 = (char *) malloc((sizeof(char))*(n+1))) == NULL)
    error(99);
  else
  {
    i -=1;
    if ((i+n) > s->length)
    {
      error(4);
    }
    else
    {
      for (int l = 0; l < n ; l++)
      {
	s2[l] = s->data[i++];
      }
    return s2;
    }
  }
  return s2;
}

char *strPlusStr(string1 *s1, string1 *s2)
{
  int i = strlen(s1->data);
  int o = strlen(s2->data);
  char *result = NULL;
  if ((result = (char *) malloc((sizeof(char))*(i+o+1))) == NULL)
    error(99);
  if (s1->data != NULL)
    strcpy(result, s1->data);
  if (s2->data != NULL)
  {
    for (int j = 0; i < (strlen(s1->data)+o+1); i++)
    {
      result[i] = s2->data[j++];
    }
  }
  return result;
}

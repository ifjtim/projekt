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

 
#include "mystring.h"


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
{	
				// nevim do ceho ukladat podretezec
  string s2;
  if (strInit(&s2) == -1)
  {
    s2.data[0] = 'x';
    return s2.data;
  }
  else
  {
    i -=1;
    if ((i+n) > s->length)
    {
      s2.data[0] = 'x';
      return s2.data;
    }
    else
    {
      for (int l = 0; l < n ; l++)
      {
	s2.data[l] = s->data[i++];
      }
   // return ch;			// :((
    }
  }
  return s2.data;
}

/*char *strPlusStr(string *s1, string *s2)
{
  int i = strlen(s1->data);
  s2->length = strlen(s2->data);
  char *result = NULL;
  if ((result = (char *) malloc(sizeof((char)*(i+s2->length+1)))) == NULL)
    return NULL;
  if (s1->data != NULL)
      memcpy(result, s1->data, s1->lenght);
  if (s2->data != NULL)
  {
    for (int j = 0; i < (i+s2->length+1); i++)
    {
      result[i] = s2->data[j++];
    }
  }
  return result;
}*/
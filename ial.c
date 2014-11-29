   /*
    *
    *
    *
    */

#include "ial.h"
   
void bLast(string *search, int *last)
{					// pomocna funkce find
  int ahoj = 0;
  for (int i = 0; i < 256; i++)
  {
    last[i] = -1;
  }
  
  for (int i = 0; i < strlen(search->data); i++)
  {
    ahoj = search->data[i];
    last[ahoj] = i;
  }
}  

int find(string *s, string *search)
{					// Boyer-Mooruv alg na hledani podretezce
  int last[256];
  bLast(search, &last[0]);
  int k = 0;
  int n = strlen(s->data);
  int m = strlen(search->data);
  int i = m-1;
  int j = i;
  if (i > (n - 1))
  {
    return -1;
  }
  do {
    if (search->data[j] == s->data[i])
    {
	if (j == 0)
	  return i + 1;
	else
	{
	  i--;
	  j--;
	}
    }
    else
    {
	k = s->data[i];
	k = last[k];
	if (j < (k + 1))
	  i = i + m - j;
	else
	  i = i + m - (k + 1);
	j = m - 1;
    }
  } while(i < n);
  return -1;
}

char *sort(string *s)
{					// shell sort
  int i, j, step, tmp, n;
  n = strlen(s->data);
  char *sortstr = NULL;
  if ((sortstr = (char *) malloc((sizeof(char))*(n+1))) == NULL)
    return NULL;
  strcpy(sortstr, s->data);
  step = n/2;
  while (step > 0)
  {
    for (i = step; i < n; i++)
    {
      j = i;
      tmp = sortstr[i];
      while (j >= step && ((int)sortstr[j-step]) > tmp)
      {
	sortstr[j] = sortstr[j-step];
	j -= step;
      }
      sortstr[j] = tmp;
    }
    step /= 2;
  }
  return sortstr;
}

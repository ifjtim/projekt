#include "mystring.h"

int main()
{
  string str;
  //string str2;
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
  if (*copy(&str, i, n) == 'x')
  {
    printf("Chyba copy\n");
    return 0;
  }
  printf("Podretezec = %s\n", copy(&str, i, n));
  strFree(&str);
  return 0;
}

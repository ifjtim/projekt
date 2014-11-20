#include "interpret.h"

void htab_typ(struct htab_listitem *seznam,int typ){
  if(seznam==NULL)   //ovìøuji jestli takovy seznam ekzistuje
  error(99);
  else
  {
    if(seznam->data==0)     //ovšøi jestli nahodou nesaham na nìjaky prvek ktery už bys zapsany a ma èislo
    {
          seznam->typ=typ;
    }
    else error(99);
  }
}
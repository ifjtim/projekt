#include "interpret.h"

void htab_typ(struct htab_listitem *seznam,int typ){
  if(seznam==NULL)   //ovìøuji jestli takovy seznam ekzistuje
  error(99);
  else
  {
    if(seznam->typ==0)     //ovšøi jestli nahodou nesaham na nìjaky prvek ktery už bys zapsany a ma èislo
    {
          seznam->typ=typ;
    }
    else error(99);
  }
}

void htab_typg(struct htab_listglobal *seznam,int typ){
  if(seznam==NULL)   //ovìøuji jestli takovy seznam ekzistuje
  error(99);
  else
  {
    if(seznam->typg==0)     //ovšøi jestli nahodou nesaham na nìjaky prvek ktery už bys zapsany a ma èislo
    {
          seznam->typg=typ;
    }
    else error(99);
  }
}
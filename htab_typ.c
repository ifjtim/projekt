#include "interpret.h"

void htab_typ(struct htab_listitem *seznam,int typ){
  if(seznam==NULL)   //ov��uji jestli takovy seznam ekzistuje
  error(99);
  else
  {
    if(seznam->typ==0)     //ov��i jestli nahodou nesaham na n�jaky prvek ktery u� bys zapsany a ma �islo
    {
          seznam->typ=typ;
    }
    else error(99);
  }
}

void htab_typg(struct htab_listglobal *seznam,int typ){
  if(seznam==NULL)   //ov��uji jestli takovy seznam ekzistuje
  error(99);
  else
  {
    if(seznam->typg==0)     //ov��i jestli nahodou nesaham na n�jaky prvek ktery u� bys zapsany a ma �islo
    {
          seznam->typg=typ;
    }
    else error(99);
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpret.h"
#include "mystring.h"
#include "ial.h"
#include "paser.h"

vrat *initListe (vrat *L)
{
	if ((L = malloc(sizeof( vrat))) == NULL) error(99);
  L->First = NULL;
  L->Last = NULL;
  return L;
}

void initListi (vrati *L)
{
  L->First = NULL;
  L->Last = NULL;
}

void pushvrat(vrat *L,struct TreAdres *new){

 struct ewh *newItem;
  if ((newItem = malloc(sizeof( struct ewh))) != NULL) {
    newItem->spetna = new;
    newItem->lptr = NULL;
    newItem->rptr = NULL;
	 
  if (L->Last == NULL) 
	{		//  pokud je vkladany prvek prvni
      L->First = newItem;
		L->Last= newItem;//  nastavi prvni prvek na vkladany
    }
    else 
	 {				//  pokud neni prvnim vkladanym prvkem
			L->Last->rptr = newItem;
			newItem->lptr = L->Last;		//  zaradi vkladany prvek za posledni prvek seznamu
    }
    L->Last = newItem;	//  aktualizuje posledni prvek na nove vlozeny
  }
  else 
    error(99);  // tady upravit *****
  }



struct TreAdres *pope(vrat *L)
{
  struct TreAdres *pom;
   struct ewh * helpPtr;
   if(L->Last != NULL) 
	{	//  pokud neni seznam prazdny ulozi hodnotu posledniho prvku do ukazatele val
    pom = L->Last->spetna;
    helpPtr = L->Last;
    if (L->First == L->Last)
	 {
      L->First = NULL;
      L->Last = NULL;
		free(helpPtr);
    }
	else
	{
    L->Last = helpPtr->lptr;
    L->Last->rptr = NULL;
    free(helpPtr);
	}
  }
  else
  {				//  pokud je seznam prazdny error
    return NULL; // dopsat cislo erroru******
  }
  return pom;
}

void pushvrati(vrati *L,struct TreAdres *new){

 struct iwh *newItem;
  if ((newItem = malloc(sizeof( struct iwh))) != NULL) {
    newItem->spetna = new;
    newItem->lptr = L->Last;
    newItem->rptr = NULL;
    if (L->Last == NULL) {		//  pokud je vkladany prvek prvni
      L->First = newItem;		//  nastavi prvni prvek na vkladany
    }
    else 
	 {				//  pokud neni prvnim vkladanym prvkem
      L->Last->rptr = newItem;		//  zaradi vkladany prvek za posledni prvek seznamu
    }
    L->Last = newItem;			//  aktualizuje posledni prvek na nove vlozeny
  }
  else 
    error(99);  // tady upravit *****
  }



struct TreAdres *popi(vrati *L)
{
  struct TreAdres *pom;
   struct iwh * helpPtr;
   if(L->Last != NULL) 
	{	//  pokud neni seznam prazdny ulozi hodnotu posledniho prvku do ukazatele val
    pom = L->Last->spetna;
    helpPtr = L->Last;
    if (L->First == L->Last)
	 {
      L->First = NULL;
      L->Last = NULL;
    }
  
    L->Last = helpPtr->lptr;
    L->Last->rptr = NULL;
    free(helpPtr);
  }
  else {				//  pokud je seznam prazdny error
    error(99); // dopsat cislo erroru******
  }
  return pom;
}
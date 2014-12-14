	#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpret.h"
#include<stdbool.h>
#include "mystring.h"
#include "ial.h"
#include "predik.h"




void initList (tListVar *L)
{
  L->First = NULL;
  L->Act = NULL;
  L->Last = NULL;
}

void disposeList (tListVar *L)
{
  tListVarItem helpPtr, delPtr;		//  pomocne promenne; delPtr - pro ulozeni prvku urcenych k uvolneni
  helpPtr = L->First;
  while (helpPtr != NULL) {		//  pokud seznam neni prazdny
    delPtr = helpPtr;			//  do delPtr se ulozi prvek
    free(delPtr);			//  uvolnime prvek
    helpPtr = helpPtr->rptr;		//  nasledne posuneme se na dalsi prvek doprava
  }
  L->First = NULL;
  L->Act = NULL;
  L->Last = NULL;
}

void pushVar(tListVar *L,struct htab_listitem *new)
{
  tListVarItem newItem;
  if ((newItem = malloc(sizeof(tListVarItem))) != NULL) {
    newItem->listItem = new;
    newItem->lptr = NULL;
    newItem->rptr = NULL;
    if (L->Last == NULL) {		//  pokud je vkladany prvek prvni
      L->First = newItem;	
		newItem->lptr = newItem;//  nastavi prvni prvek na vkladany
    }
    else {				//  pokud neni prvnim vkladanym prvkem
      L->Last->rptr = newItem;
		newItem->lptr =  L->Last;		//  zaradi vkladany prvek za posledni prvek seznamu
    }
    L->Last = newItem;			//  aktualizuje posledni prvek na nove vlozeny
  }
  else {
    error(99);  // tady upravit *****
  }
}

struct htab_listitem *pop(tListVar *L)
{
  struct htab_listitem *pom;
   tListVarItem helpPtr;
   if(L->Last != NULL) {	//  pokud neni seznam prazdny ulozi hodnotu posledniho prvku do ukazatele val
		pom = L->Last->listItem;
		helpPtr = L->Last;
		if (L->First == L->Last) {
			L->First = NULL;
			L->Act = NULL;
			L->Last = NULL;
		}
		if (L->Last == L->Act) {
			L->Act = NULL;
		}
		L->Last = helpPtr->lptr;
		L->Last->rptr = NULL;
		free(helpPtr);
  }
  else {				//  pokud je seznam prazdny error
    error(2); // dopsat cislo erroru******
  }
  return pom;
}
bool isEmpty (tListVar *L)
{
  return(L->First==NULL);
}

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "mystring.h"
#include "ial.h"
#include "predik.h"


///////////////


void initListp (tListOp *L)
{
  L->First = NULL;
  L->Act = NULL;
  L->Last = NULL;
}
/////////////////




////////////

void disposeListp (tListOp *L)
{
  tListOpItem helpPtr, delPtr;		//  pomocne promenne; delPtr - pro ulozeni prvku urcenych k uvolneni
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

/////////////////







void pushOp(tListOp *L, int OperType)
{
  tListOpItem newItem;
  printf("aloha");
  if ((newItem = malloc(sizeof(tListOpItem))) != NULL) {
    newItem->data = OperType;
    newItem->lptr = NULL;
    newItem->rptr = NULL;
    if (L->Last == NULL) {		//  pokud je vkladany prvek prvni
      L->First = newItem;
		newItem->lptr = newItem;		//  nastavi prvni prvek na vkladany
    }
    else {				//  pokud neni prvnim vkladanym prvkem
      L->Last->rptr = newItem;
		newItem->lptr = L->Last;		//  zaradi vkladany prvek za posledni prvek seznamu
    }
    L->Last = newItem;			//  aktualizuje posledni prvek na nove vlozeny
  }
  else {
    error(2);  // tady upravit *****
  }
}


int popOp(tListOp *L)
{
   int pom;
   tListOpItem helpPtr;
   if(L->Last != NULL) {	//  pokud neni seznam prazdny ulozi hodnotu posledniho prvku do ukazatele val
    pom = L->Last->data;
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

bool isEmptyp (tListOp *L)
{
  return(L->First==0);
}

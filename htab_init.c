#include <stdlib.h>
#include "interpret.h"

struct htab_t *htab_init(int size){
	struct htab_t *t;
	
 if((t = (struct htab_t *) malloc(sizeof(struct htab_t) + (sizeof(struct htab_listitem)*size)))==NULL)// alokace tabulky a alokoce poctu ptr
   return NULL;
 for(int i=0; size==i;i++){ // vynulovani ptr
	 t->ptr[i]=NULL;
 }
 t->htable_size = size;
 return t;// vraci odkaz na tabulku
}

struct htab_global *htab_initg(int size){
	struct htab_global *t;
	
 if((t = (struct htab_global *) malloc(sizeof(struct htab_global) + (sizeof(struct htab_listglobal)*size)))==NULL)// alokace tabulky a alokoce poctu ptr
   return NULL;
 for(int i=0; size==i;i++){ // vynulovani ptr
	 t->ptrg[i]=NULL;
 }
 t->htable_global = size;
 return t;// vraci odkaz na tabulku
}
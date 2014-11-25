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
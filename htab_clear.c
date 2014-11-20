#include "interpret.h"
#include <stdlib.h>
#include <string.h>

void htab_clear(struct htab_t *t){
	struct htab_listitem *seznam, *pomocna;
	
	 for(unsigned int pocet=0;pocet<t->htable_size;pocet++){ // projeti všech seznamu v tabulce
			seznam=t->ptr[pocet]; // natčeni prvniho prvku
		while(seznam!=NULL){ // projeti celeho seznamu
			pomocna=seznam->next; // zapamotovani pristiho
			free(seznam->key);// uvolneni pro slovo
			free(seznam);//uvolni aktualniho seznamu
			seznam=pomocna;//nahrani pristiho seznamu
		}
		t->ptr[pocet]=NULL;// vynulovani ptr
	}
}
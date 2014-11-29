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

/*void free_kod(tList *L)
struct TreAdres *seznam,*pomocna;
		seznam=L->First; 			// natčeni prvniho prvku
		while(seznam!=NULL){ 	// projeti celeho seznamu
			pomocna=seznam->ptr; // zapamotovani pristiho
			free(seznam);			//uvolni aktualniho seznamu
			seznam=pomocna;		//nahrani pristiho seznamu
		}
	L->Act=NULL; 					 //aby nezustali odkazy v aktivnim a prvnim
   L->First=NULL;
                  
}*/

void htab_clearg(struct htab_global *t){
struct htab_listglobal *seznam, *pomocna;
//tList kod;
struct htab_t *tt;
//struct TreAdres kod;
	 for(unsigned int pocet=0;pocet<t->htable_global;pocet++){ // projeti všech seznamu v tabulce
			seznam=t->ptrg[pocet]; // natčeni prvniho prvku
		while(seznam!=NULL){
			tt=seznam->ktera;
			htab_free(tt);
			//kod=seznam->adres;
			//free_kod(kod);
			pomocna=seznam->nextg; // zapamotovani pristiho
			free(seznam->keyg);// uvolneni pro slovo
			free(seznam);//uvolni aktualniho seznamu
			seznam=pomocna;//nahrani pristiho seznamu
		}
		t->ptrg[pocet]=NULL;// vynulovani ptr
	}	
}


#include "interpret.h"
#include <stdlib.h>
#include <string.h>


struct htab_listitem * htab_lookup(struct htab_t *t, const char *key){
	struct htab_listitem *seznam;

	unsigned int pozice=hash_function(key,t->htable_size); // ziskani ktere seznamu bude zapisovane(ktere ptr)
	seznam=t->ptr[pozice];

		while(seznam!=NULL){// projeti celeho seznamu
		if(strcmp(key,seznam->key)==0) //hledani schodz kli4u
			error(3);
		else 
			seznam=seznam->next; 
	}
	
	if((seznam= (struct htab_listitem *) malloc(sizeof(struct htab_listitem)))==NULL)// pokud neni chyba vztvoøi se novy prvek
	error(99);
	seznam->key=(char *) malloc(sizeof(char)*(strlen(key)+1));// nevime jak je velke slovo musime pro nìho takzy alokovat misto
	strcpy(seznam->key,key); // nahrani udaju
  // free(key);// uvolnìi globalniho stringu
  // key=NULL; // nahrani na nìho nulu
			seznam->typ=0; 
			seznam->next=NULL;
			t->ptr[pozice]=seznam;
			return seznam;
}
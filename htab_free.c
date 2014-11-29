#include "interpret.h"
#include <stdlib.h>
#include <string.h>
void freeg(struct htab_global *t){
	
	 htab_clearg(t); // uvolneni všech seznamu
	 free(t); // uvolneni cele tabul
	
}
void htab_free(struct htab_t *t){
	
	 htab_clear(t); // uvolneni všech seznamu
	 free(t); // uvolneni cele tabulky
	 
}
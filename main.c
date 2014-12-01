#include "interpret.h"
#include "mystring.h"
#include "ial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	typp a=nic;
	int c;
	strInit(&str_g);
	if((global=htab_initg(POCET))==NULL)
	{
		error(99);
	}
	
 if (argc > 1) {
        if (opensrcfile(argv[1]) == 0) { //otevøu soubor
			  /* while(a!=konec)
				{
			  a=get_token();  
			 printf("%d\n",a);
			if(a==1)
			{
				
				 strFree(&str_g);
				 strInit(&str_g);
			}
			  }*/
			  neww=1;
			c= func();
				
			 
		  }
 }
 else error(99);
 closesrcfile();
/*	struct htab_global *t;
	struct htab_t *tt;
	struct htab_listitem *seznam, *pomocna;
	struct htab_listglobal *polozka,*kolo;
	if((t=htab_initg(POCET))==NULL)
	{
		error(99);
	}
	else
	{
			polozka=htab_lookupg(t,"ss");
						kolo=htab_lookupg(t,"rsr");
			//	error(99);
			htab_typg(polozka,2);
			htab_typg(kolo,3);
			tt=polozka->ktera;
			pomocna=htab_lookup(tt,"ahoj");
			seznam=htab_lookup(tt,"ahob");
			seznam=pomocna->next;
		printf("%s\t%u\n",polozka-> keyg,polozka->typg);
		printf("%s\t%u\n",seznam-> key,seznam->typ);
		printf("%s\t%u\n",kolo-> keyg,kolo->typg);
		htab_clearg(t);
	}*/
return 0;
}
//zkouska
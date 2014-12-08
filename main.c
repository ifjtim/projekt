#include "interpret.h"
#include "mystring.h"
#include "ial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	//typp a=nic;
	int c;
  pomo=NULL;
	struct htab_listglobal *polozka;//poloyki globalni urovne
	
	strInit(&str_g);
	if((global=htab_initg(POCET))==NULL)
	{
		error(99);
	}
	
	if((polozka=htab_lookupg(global,"1main"))==NULL) error(99);//zakladam tabulku symbolu pro funkci main a ukladam do globalni prmenne pod nayvem 1main
					lokal=polozka->ktera;
					lokal_lobal=lokal;
	
 if (argc > 1) {
        if (opensrcfile(argv[1]) == 0) { //otevøu soubor
		/*	  while(a!=konec)
				{
			  a=get_token();  
			 printf("%d\n",a);
			if(a==1)
			{
				
				 strFree(&str_g);
				 strInit(&str_g);
			}
			  }
			 */neww=1;
			c= func();
			if(c!=0)
				error(9);
				
			 
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
/*vypis(lokal_lobal);
printf("\n");
if(pomo!=NULL)
vypis(pomo);*/
return 0;
}
//zkouska
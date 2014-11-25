#include "interpret.h"

int main(int argc, char *argv[])
{
	typp a=nic;
	strInit(&str_g);
 if (argc > 1) {
        if (opensrcfile(argv[1]) == 0) { //otevøu soubor
			   while(a!=konec)
				{
			  a=get_token();  //tady mi to nìkde sahne kde nema nevim proè skus to vyøe¹it
			 printf("%d\n",a);
			if(a==1)
			{
				printf("%s",str_g.data);
				 strFree(&str_g);
				 strInit(&str_g);
			}
				}
			 
		  }
 }
 else error(99);
 closesrcfile();
	/*struct htab_t *t;
	struct htab_listitem *polozka;
	if((t=htab_init(POCET))==NULL)
		error(99);
	else
	{
			polozka=htab_lookup(t,"ss");
			//	error(99);
			htab_typ(polozka,2);
		printf("%s\t%u\n",polozka-> key,polozka->typ);
		htab_clear(t);
	}*/
return 0;
}
//zkouska


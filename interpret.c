#include "interpret.h"
int main(int argc, char *argv[])
{
	int a=0;
 if (argc > 1) {
        if (opensrcfile(argv[1]) == 0) { //otev�u soubor
			 a= get_token();  //tady mi to n�kde sahne kde nema nevim pro� skus to vy�e�it
			 printf("%d",a);
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


#include "interpret.h"
int main(int argc, char *argv[])
{

 
	struct htab_t *t;
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
	}
return 0;
}
//zkouska


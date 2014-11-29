#include<stdio.h>
#include "interpret.h"

int error(int cislo_err){
	switch (cislo_err) {	
 

		case 1:
			smaz();
		exit(1);;
		
		case 2:
			smaz();
		exit(2);
		
		case 3:
			smaz();
		exit(3);
		
		case 4:
			smaz();
		exit(4);
		
		case 5:
			smaz();
		exit(5);
		
		case 6:
			smaz();
		exit(6);

		case 7:
			smaz();
		exit(7);

		case 8:
			smaz();
		exit(8);

		case 9:
			smaz();
		exit(9);

		case 99:
			smaz();
			printf("jede to");
		exit(99);
		
		default:
			
			printf("chybny error");
			exit(99);
	}

}

void smaz()
	{
		printf("smazS");
		/*htab_free(t);                                    //uvolneni tabuky
		htab_clear(t);*/
	}

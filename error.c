#include<stdio.h>
#include "interpret.h"

int error(int cislo_err){
	switch (cislo_err) {	
 

		case 1:
			smaz();
		return 1;
		
		case 2:
			smaz();
		return 2;
		
		case 3:
			smaz();
		return 3;
		
		case 4:
			smaz();
		return 4;
		
		case 5:
			smaz();
		return 5;
		
		case 6:
			smaz();
		return 6;

		case 7:
			smaz();
		return 7;

		case 8:
			smaz();
		return 8;

		case 9:
			smaz();
		return 9;

		case 99:
			smaz();
			printf("jede to");
		return 99;
		
		default:
			
			printf("chybnz error");
			return 99;
	}

}

void smaz()
	{
		printf("smazS");
		/*htab_free(t);                                    //uvolneni tabuky
		htab_clear(t);*/
	}

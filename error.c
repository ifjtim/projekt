	#include<stdio.h>
#include "interpret.h"
#include "ial.h"

int error(int cislo_err){
	switch (cislo_err) {	
 

		case 1:
			smaz();
			printf("1");
		exit(1);
		
		case 2:
			smaz();
			printf("2");
		exit(2);
		
		case 3:
			smaz();
			printf("3");
		exit(3);
		
		case 4:
			smaz();
			printf("4");
		exit(4);
		
		case 5:
			smaz();
			printf("5");
		exit(5);
	
		case 6:
			smaz();
			printf("6");
		exit(6);

		case 7:
			smaz();
			printf("7");
		exit(7);

		case 8:
			smaz();
			printf("8");
		exit(8);

		case 9:
			smaz();
			printf("9");
		exit(9);

		case 99:
			smaz();
			printf("99");
		exit(99);
		
		default:
			
			printf("chybnz error");
			exit(99);
	}

}

void smaz()
	{
		printf("smazS");
		/*htab_free(t);                                    //uvolneni tabuky
		htab_clear(t);*/
	}

	#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interpret.h"

#include "mystring.h"
#include "ial.h"
void smaz()
	{
		//printf("smazS");
		/*htab_free(t);                                    //uvolneni tabuky
		htab_clear(t);*/
	}

int error(int cislo_err){
	switch (cislo_err) {	
 

		case 1:
			smaz();
			printf("e1");
		exit(1);
		
		case 2:
			smaz();
			printf("e2");
		exit(2);
		
		case 3:
			smaz();
			
			printf("e3");
		exit(3);
		
		case 4:
			smaz();
			printf("e4");
		exit(4);
		
		case 5:
			smaz();
			printf("e5");
		exit(5);
	
		case 6:
			smaz();
			printf("e6");
		exit(6);

		case 7:
			smaz();
			printf("e7");
		exit(7);

		case 8:
			smaz();
			printf("e8");
		exit(8);

		case 9:
			smaz();
			printf("e9");
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



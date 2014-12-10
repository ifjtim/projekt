#include "interpret.h"
#include "mystring.h"
#include "ial.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

void jede()
{
	struct TreAdres *rozjedemto=NULL;
	struct htab_listitem *prvek=NULL;
	 int a;
	
	rozjedemto=lokal_lobal->adres->First;
	while(rozjedemto!=NULL){
		 switch (rozjedemto->indetifikator)
        {

		case cti:   /* int, real, 3, boolean  (id : typ ;)*/
             prvek=rozjedemto-> operat;
				
				 if(prvek->typ == 1)
				 {
					if(scanf("%d",&(a))==EOF) error(6);
					prvek->hodnota.inger=a;
					prvek->deklarr=TRUE;
				 }
				else if(prvek->typ == 2)
				{
					if(scanf("%g",&(prvek->hodnota.dvouger))==EOF) error(6);
					prvek->deklarr=TRUE;
				}
				else if(prvek->typ == 3)
				{
					if(scanf("%s",&(prvek->hodnota.stringer.data))==EOF) error(6);//alokace mista
					prvek->deklarr=TRUE;
				}
				else error(6);
			break;
		case zapis :
                prvek=rozjedemto-> operand1;
					 if(prvek->deklarr)
					 {
						 
						 if(prvek->typ  == 1)
					printf("%d",prvek->hodnota.inger);
				else if(prvek->typ  == 2)
					printf("%g",prvek->hodnota.dvouger);
				else if(prvek->typ  == 3)
				{
					printf(" %s ",prvek->hodnota.stringer.data);
					//printf("%s",a.data);/* musime doresit*/
				}
				else error(9);
					 }
						 
					else error(7);
			
			break;
			default:
			printf("nemam");
			break;
		
		  }
		  rozjedemto=rozjedemto->ptrr;
	}
}
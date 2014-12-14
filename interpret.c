#include "interpret.h"
#include "mystring.h"
#include "ial.h"
#include "lexana.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>

void jede()
{
	struct TreAdres *rozjedemto=NULL;
	struct htab_listitem *prvek=NULL,*prvek2=NULL,*vysl=NULL;
	 int a;
	 int c=0;
	string1 beta;
	char *seremeto=NULL;
	char *neco=NULL;
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
				else if(prvek->typ == 2)// upravit
				{
					if(scanf("%f",&(prvek->hodnota.dvouger))==EOF) error(6);
					
					prvek->deklarr=TRUE;
				}
				else if(prvek->typ == 3)//nejede to opravit
				{
					
					
					c= getchar();
					while(c!=EOF)
					{
						printf("%c",c);
						strAddChar(&str_g,c);//asi nekde tady chyba oprav
						c= getchar();
						printf("%c",c);
						
					}
					
					printf("%s",str_g.data);
					prvek->hodnota.stringer.allocSize=beta.allocSize;
					prvek->hodnota.stringer.length=beta.length;
					if ((seremeto = (char *) malloc((sizeof(char))*(strlen(beta.data)+1))) == NULL) error(99);
					strcpy(seremeto,beta.data);
					prvek->hodnota.stringer.data=seremeto;
					strFree(&str_g);
					strInit(&str_g);
					prvek->deklarr=TRUE;
				}
				else if(prvek->typ == 4) error(4);
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
			case secti :
				
                prvek=rozjedemto-> operand1;
					 prvek2=rozjedemto-> operand2;
					 vysl=rozjedemto-> operat;
					 
					 if(prvek->deklarr && prvek2->deklarr)
					 {
						 //printf(" vole ");
						 	if(vysl->typ  == 1)
							{
								vysl->hodnota.inger=prvek->hodnota.inger+prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
							}
							else if(vysl->typ  == 2)
							{
								if(prvek2->typ==1)
								{
								vysl->hodnota.dvouger=prvek->hodnota.dvouger+prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
								}
								else if(prvek->typ==1)
								{
								vysl->hodnota.dvouger=prvek->hodnota.inger+prvek2->hodnota.dvouger;
								vysl->deklarr=TRUE;
								}
								else if(prvek->typ==1 && prvek2->typ==1)//vzresic y pretipovanim
								{
								vysl->hodnota.dvouger=prvek->hodnota.inger+prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
								}
								else error(9);
							}
							/*else if(vysl->typ  == 3)
							{
								neco=strPlusStr( prvek->hodnota.stringer,prvek2->hodnota.stringer);
								vysl->hodnota.stringer.length= strlen(neco);
								vysl->hodnota.stringer.allocSize= strlen(neco)+1;
								vysl->hodnota.stringer.data=neco;
								vysl->deklarr=TRUE;
							}*/
							else error(9);//kouknout se kvuli boolean
					
					 }
						 
					else error(7);
			
			break;
			case odecti :
				
                prvek=rozjedemto-> operand1;
					 prvek2=rozjedemto-> operand2;
					 vysl=rozjedemto-> operat;
					 
					 if(prvek->deklarr && prvek2->deklarr)
					 {
						 //printf(" vole ");
						 	if(vysl->typ  == 1)
							{
								vysl->hodnota.inger=prvek->hodnota.inger-prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
							}
							else if(vysl->typ  == 2)
							{
								if(prvek2->typ==1)
								{
								vysl->hodnota.dvouger=prvek->hodnota.dvouger-prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
								}
								else if(prvek->typ==1)
								{
								vysl->hodnota.dvouger=prvek->hodnota.inger-prvek2->hodnota.dvouger;
								vysl->deklarr=TRUE;
								}
								else if(prvek->typ==1 && prvek2->typ==1)//vzresic y pretipovanim
								{
								vysl->hodnota.dvouger=prvek->hodnota.inger-prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
								}
								else error(9);
							}
							
							else error(9);//kouknout se kvuli boolean
					
					 }
						 
					else error(7);
			
			break;
			case vynasob :
				
                prvek=rozjedemto-> operand1;
					 prvek2=rozjedemto-> operand2;
					 vysl=rozjedemto-> operat;
					 
					 if(prvek->deklarr && prvek2->deklarr)
					 {
						 //printf(" vole ");
						 	if(vysl->typ  == 1)
							{
								vysl->hodnota.inger=prvek->hodnota.inger*prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
							}
							else if(vysl->typ  == 2)
							{
								if(prvek2->typ==1)
								{
								vysl->hodnota.dvouger=prvek->hodnota.dvouger*prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
								}
								else if(prvek->typ==1)
								{
								vysl->hodnota.dvouger=prvek->hodnota.inger*prvek2->hodnota.dvouger;
								vysl->deklarr=TRUE;
								}
								else if(prvek->typ==1 && prvek2->typ==1)//vzresic y pretipovanim
								{
								vysl->hodnota.dvouger=prvek->hodnota.inger*prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
								}
								else error(9);
							}
							
							else error(9);//kouknout se kvuli boolean
					
					 }
						 
					else error(7);
			
			break;
			case vydel :
				
                prvek=rozjedemto-> operand1;
					 prvek2=rozjedemto-> operand2;
					 vysl=rozjedemto-> operat;
					 
					 if(prvek->deklarr && prvek2->deklarr)
					 {
						 if(prvek->hodnota.inger==0) error(8);
						 //printf(" vole ");
						 	if(vysl->typ  == 1)
							{
								vysl->hodnota.inger=prvek->hodnota.inger/prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
							}
							else if(vysl->typ  == 2)
							{
								if(prvek2->typ==1)
								{
								vysl->hodnota.dvouger=prvek->hodnota.dvouger*prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
								}
								else if(prvek->typ==1)
								{
								vysl->hodnota.dvouger=prvek->hodnota.inger*prvek2->hodnota.dvouger;
								vysl->deklarr=TRUE;
								}
								else if(prvek->typ==1 && prvek2->typ==1)//vzresic y pretipovanim
								{
								vysl->hodnota.dvouger=prvek->hodnota.inger*prvek2->hodnota.inger;
								vysl->deklarr=TRUE;
								}
								else error(9);
							}
							
							else error(9);//kouknout se kvuli boolean
					
					 }
						 
					else error(7);
			
			break;
				case  prirad :
                prvek=rozjedemto-> operand1;
					 vysl=rozjedemto-> operat;
					 
					 if(prvek->deklarr )
					 {
						 //printf(" vole ");
						 	if(vysl->typ  == 1)
							{
								vysl->hodnota.inger=prvek->hodnota.inger;
								vysl->deklarr=TRUE;
							}
						
					 }
						 
					else error(7);
			
			break;
			
			case konec_while :
// 				printf(" skok ");
				 rozjedemto=rozjedemto->skok;
				break;
				case nici :
				 
				break;
			default:
			printf("nemam");
			break;
		
		  }
		  rozjedemto=rozjedemto->ptrr;
	}
}
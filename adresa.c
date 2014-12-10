#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "interpret.h"
#include "mystring.h"
#include "ial.h"
#include "paser.h"

struct TreAdres *generuj(struct htab_t *s,struct htab_listitem * op1,struct htab_listitem * op2,struct htab_listitem * opp, int i){
		
		tList *kod,*jeseter;
		struct TreAdres *adrr,*pom;
		kod=s->adres;
		
		if(kod==NULL){
		
		if((adrr= (struct TreAdres * ) malloc(sizeof(struct TreAdres )))==NULL)error(99);
		 adrr->ptrr=NULL;
		 adrr->skok=NULL;
		adrr->operand1=op1;
		adrr->operand2=op2;
		adrr->operat=opp;
		adrr->indetifikator=i;
		if((jeseter= (tList  * ) malloc(sizeof(tList  )))==NULL)error(99);
		kod=jeseter;
		s->adres=kod;
		kod->First=adrr;
		kod->Lost=adrr;
		}
		else
		{
			if((adrr= (struct TreAdres * ) malloc(sizeof(struct TreAdres )))==NULL)error(99);
			 adrr->ptrr=NULL;
		 adrr->skok=NULL;
		adrr->operand1=op1;
		adrr->operand2=op2;
		adrr->operat=opp;
		adrr->indetifikator=i;
		pom=kod->Lost;
		pom->ptrr=adrr;
		kod->Lost=adrr;
		
		}
		//printf(" %s aloha ",kod->First->operand1->key);
		return adrr;

	}
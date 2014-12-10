#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "interpret.h"
#include "mystring.h"
#include "ial.h"
#include "paser.h"
#include "lexana.h"

struct htab_listglobal *pocet;

int provertyp(){
	
 if(token==K_integer) {return 1; }
 else if(token==K_real) {return 2;}
 else if(token==K_string) {return 3;}
 else if(token==K_boolean) {return 4;}
 else {error(2);}
 return 0;
}


void new_token()
{
	
	if(neww==1) //pokud potrebuji novy token
	{
		token=get_token();
	}
	else if(neww==2)// pokud potrebuji tam nechat ten stavajici token kvuli epsilon pravidlu
	{
		neww=1;
	}
	else error(99);
}

int func()
{

	int ok=1;
	struct htab_listglobal *polozka;//poloyki globalni urovne
	struct htab_listitem *seznam; //polozki lokani urovne
	while(ok==1)
	{
		new_token();
		if(token==K_begin)// pokud zaciname begin prvidla ll
		{ 
			lokal=lokal_lobal;
			sts();
			
			en();
			
			new_token();
			if(token==tecka)//token se musi rovnat tecte
			{
				ok=0;
			}
		}
		else if(token==K_var)//pokud = var
		{
			
			new_token();
			if(token!=id)error(2);//pokud se nerovna id
			else
			{

					if((seznam=htab_lookup(lokal_lobal,str_g.data))==NULL) error(99);// ukladam do lokalni tabulkz symbolu data
					 strFree(&str_g);
					strInit(&str_g);
				
			}
			new_token();
			if(token!=dvojtecka)error(2);//token se nerona se dvijtecka
			type();
			strFree(&str_g);
		strInit(&str_g);
			int c=provertyp();
			
			htab_typ(seznam,c);
			
			new_token();
			if(token!=strednik)error(2);//token se nerovna ;
			next();
		}
		else if(token==K_function)//pokud se rovna func
		{	
			new_token();
			if(token!=id)//musi rovnat id
			{
				error(2);
			}
			else{
						if((polozka=htab_lookupg(global,(str_g.data)))==NULL) error(99);//vlozeni jmeno fukce
						if((seznam=htab_lookup(lokal_lobal,(str_g.data)))==NULL) error(99);
						strFree(&str_g);
						strInit(&str_g);
						lokal=polozka->ktera;
						pomo=lokal;
						pocet=polozka;
			}
			new_token();
			if(token!=zavorkaP)error(2);//musi rovnat(
			params();
			new_token();
			if(token!=zavorkaD)error(2);//musi rovnat)
			new_token();
			if(token!=dvojtecka)error(2);//token se nerona se dvijtecka
				type();
			strFree(&str_g);
		strInit(&str_g);
			int c=provertyp();
			htab_typg(polozka,c);
			htab_typ(seznam,c);
			new_token();
			if(token!=strednik)error(2);//token se nerovna ;
			returnn();
		}
		else error(2);
	}
	return 0;
}

struct htab_listitem * type(){
	struct htab_listitem *seznam=NULL,*g=NULL;
	int p;
	new_token();
	
	if(token==K_integer){
		
	}
	else if(token==K_real){}
	else if(token==cislo_real){
		seznam=zapisreal();//oprav z e
		return seznam;
	}
	else if(token==cislo_integer)
	{
		seznam=zapisint();
		return seznam;
		//printf(" i%d ", vysledek);
		
	}
	else if(token==hodnota_string){
	seznam=zapisstring();	
	return seznam;
	
	}
	else if(token==K_string){}
	else if(token==K_boolean){}
	else if(token==id)
	{ 
		g=over(str_g.data,lokal,&p);//proveri jestli je v lokani tabulce
								if(g==NULL)
								{
									
									g=gover(str_g.data,&p);//proveri jestli je v tabulce od main
									if(g==NULL) error(3);
								}
								return g;
		
	}//dopis jak budes chctit id doplnit id chyba
	else {error(2);}	
	return NULL;
}

void params(){
	//poloyki globalni urovne
	struct htab_listitem *seznam;
	struct zapis *nevim;
	new_token();
	if(token==id)
	{
		if((seznam=htab_lookup(lokal,str_g.data))==NULL) error(99);// ukladam do lokalni tabulkz symbolu data
		if((nevim=lookup_zapis(seznam,lokal))==NULL) error(99);
					strFree(&str_g);
					strInit(&str_g);
	
		new_token();
		if(token!=dvojtecka)error(2);//token se nerona se dvijtecka
		type();
		strFree(&str_g);
		strInit(&str_g);
		int c=provertyp();
			htab_typ(seznam,c);
		params_next();
	}
	else neww=2;
}

void params_next(){
	//poloyki globalni urovne
	struct htab_listitem *seznam=NULL;
	struct zapis *nevim=NULL;
	new_token();
	if(token==strednik)
	{
		
		new_token();
		if(token!=id) error(2);
		else
		{ 
			if((seznam=htab_lookup(lokal,str_g.data))==NULL) error(99);// ukladam do lokalni tabulkz symbolu data
			
			if((nevim=lookup_zapis(seznam,lokal))==NULL) error(99);
			
			//printf("%sk",str_g.data);
					strFree(&str_g);
						strInit(&str_g);
			
			new_token();
			if(token!=dvojtecka)error(2);
			type();
			int c=provertyp();
				htab_typ(seznam,c);//token se nerona se dvijtecka
			
			
			strFree(&str_g);
			strInit(&str_g);
			params_next();
			
		}
	}
	else neww=2;
	
}
void returnn()
{
	
	struct htab_listitem *seznam;
	new_token();
	if(token==K_forward)
	{ 
		new_token();
		if(token!=dvojtecka)error(2);
		
	}
	else if(token==K_begin)
	{
		sts();
		en();
		new_token();
		if(token!=strednik)error(2);
	}
	else if(token==K_var){
			new_token();
			if(token!=id)error(2);//pokud se nerovna id
			else
			{
					 if((seznam=htab_lookup(lokal,str_g.data))==NULL) error(99);// ukladam do lokalni tabulkz symbolu data
					 strFree(&str_g);
					strInit(&str_g);	
			}
			
			new_token();
			if(token!=dvojtecka)error(2);//token se nerona se dvijtecka
			type();
			strFree(&str_g);
		strInit(&str_g);
			int c=provertyp();
			htab_typ(seznam,c);
			new_token();
			if(token!=strednik)error(2);//token se nerovna ;
			next();
			new_token();
			if(token!=K_begin)error(2);
			else
			{
				sts();
				en();	
				new_token();
				if(token!=strednik)error(2);
			}
	}
	else error(2);	
	
}

void op()
{
	new_token();
	
	if(token==krat){}
	else if(token==deleno){}
	else if(token==minus){}
	else if(token==plus){}
	else if(token==vetsi){}
	else if(token==mensi){}
	else if(token==mensi_rovnase){}
	else if(token==vetsi_rovnase)	{}
	else if(token==rovnase){}
	else if(token==nerovna){}
	else if(token==zavorkaP){}
	else if(token==zavorkaD){}
	else if(token==dvojtecka){}
	else if(token==carka){}
	else if(token==strednik){}
	else if(token==tecka){}	
	else {error(2);}
		
	
}
void sts(){
	struct htab_listitem *g=NULL;
	struct htab_listitem *vul=NULL;
	int p;
	new_token();
	if(token==id)
	{
		//g=proverfukci();
		
			g=over(str_g.data,lokal,&p);
			if(g==NULL)
			{
				
				g=gover(str_g.data,&p);
				if(g==NULL) error(3);	
			}
		
		strFree(&str_g);
		strInit(&str_g);
		new_token();
		if(token!=dvojtecka)error(2);
			new_token();
		if(token!=rovnase)error(2);
		
		expr();
		
	
			
	}
	else if(token==K_while){
		type();
		strFree(&str_g);
		strInit(&str_g);
		op();
		type();
		strFree(&str_g);
		strInit(&str_g);
		new_token();
		if(token!=K_do)error(2);
		new_token();
		if(token!=K_begin)error(2);
		sts();
		en();
	}
	else if(token==K_if){
		type();
		strFree(&str_g);
		strInit(&str_g);
		op();
		type();
		strFree(&str_g);
		strInit(&str_g);
		new_token();
		if(token!=K_then)error(2);
		new_token();
		if(token!=K_begin)error(2);
		sts();
		en();
		new_token();
		if(token!=K_else)error(2);
		new_token();
		if(token!=K_begin)error(2);
		sts();
		en();
	}
	/*pokud je token readln klicove slovo*/
	else if(token==K_readln){
		
		new_token();
		if(token!=zavorkaP)error(2);
		new_token();
		if(token!=id)error(2);
		
		else
		{
			
				g=over(str_g.data,lokal,&p);//proveri jestli je v lokani tabulce
			if(g==NULL)
			{
				
				g=gover(str_g.data,&p);//proveri jestli je v tabulce od main
				if(g==NULL) error(3);	
			}
				
				//generuj(lokal,g ,NULL,NULL, 5);
				generuj(lokal,NULL,NULL,g, cti);
			strFree(&str_g);
			strInit(&str_g);
		}
		new_token();
		if(token!=zavorkaD)error(2);
		
		
		
	}
	/*pokud je token write klicove slovo*/
	else if(token==K_write){
	
		new_token();
		if(token!=zavorkaP)error(2);
		vul=type();
		strFree(&str_g);
		strInit(&str_g);
		generuj(lokal,vul,NULL,NULL, zapis);
		rite();
		new_token();
		if(token!=zavorkaD)error(2);
	
	}
	else {neww=2;}
}

void rite()

{
	struct htab_listitem *vul=NULL;
	new_token();
	if(token==carka)
	{
		vul=type();
		generuj(lokal,vul,NULL,NULL, zapis);
		strFree(&str_g);
		strInit(&str_g);
		rite();
	}
	else neww=2;
}

void expr()
{
	struct htab_listitem *g,*pom,*pom2;
	int p;
	struct htab_listglobal *vypomoc;
	struct zapis *sracka;
	new_token();
	//printf("%d ", token);
	if(token==K_sort)
	{
		
			new_token();
			if(token!=zavorkaP)error(2);
			type();
				if((token==id))
				{
					g=over(str_g.data,lokal,&p);//proveri jestli je v lokani tabulce
					if(g==NULL)
					{
						
						g=gover(str_g.data,&p);//proveri jestli je v tabulce od main
						if(g==NULL) error(3);
						if(p!=3) error(4);
					}
					else if(p==3){}
					else error(4);
				}
				else if(token== hodnota_string){}
				else error(4);
				strFree(&str_g);
				strInit(&str_g);
			new_token();
			if(token!=zavorkaD)error(2);
		
	}
	else if(token==F_copy)
	{
				new_token();
				if(token!=zavorkaP)error(2);
				type();
				if((token==id))
					{
						
						g=over(str_g.data,lokal,&p);//proveri jestli je v lokani tabulce
						if(g==NULL)
						{
							
							g=gover(str_g.data,&p);//proveri jestli je v tabulce od main
							if(g==NULL) error(3);
							if(p!=3) error(4);
						}
						else if(p==3){}
						else error(4);
					}
					else if(token== hodnota_string){}
					else error(4);
					strFree(&str_g);
					strInit(&str_g);
				new_token();
				if(token!=carka)error(2);
				type();
				if((token==id))
					{
						g=over(str_g.data,lokal,&p);//proveri jestli je v lokani tabulce
						if(g==NULL)
						{
							
							g=gover(str_g.data,&p);//proveri jestli je v tabulce od main
							if(g==NULL) error(3);
							if(p!=1) error(4);
						}
						else if(p==1){}
						else error(4);
					}
					else if(token== cislo_integer){}
					else error(4);
					strFree(&str_g);
					strInit(&str_g);
				new_token();
				if(token!=carka)error(2);
				type();
				if((token==id))
					{
						g=over(str_g.data,lokal,&p);//proveri jestli je v lokani tabulce
						if(g==NULL)
						{
							
							g=gover(str_g.data,&p);//proveri jestli je v tabulce od main
							if(g==NULL) error(3);
							if(p!=1) error(4);
						}
						else if(p==1){}
						else error(4);
					}
					else if(token== cislo_integer){}
					else error(4);
					strFree(&str_g);
					strInit(&str_g);
				new_token();
				if(token!=zavorkaD)error(2);
	}
	else if(token==F_leight)
	{
					new_token();
					if(token!=zavorkaP)error(2);
					type();
					if((token==id))
						{
							g=over(str_g.data,lokal,&p);//proveri jestli je v lokani tabulce
							if(g==NULL)
							{
								
								g=gover(str_g.data,&p);//proveri jestli je v tabulce od main
								if(g==NULL) error(3);
								if(p!=3) error(4);
							}
							else if(p==3){}
							else error(4);
						}
						else if(token== hodnota_string){}
						else error(4);
						strFree(&str_g);
						strInit(&str_g);
					new_token();
					if(token!=zavorkaD)error(2);
	}
	
		else if(token==K_find)
		{
			new_token();
			if(token!=zavorkaP)error(2);
			type();
			if((token==id))
				{
					g=over(str_g.data,lokal,&p);//proveri jestli je v lokani tabulce
						if(g==NULL)
						{
							
							g=gover(str_g.data,&p);//proveri jestli je v tabulce od main
							if(g==NULL) error(3);
							if(p!=3) error(4);
						}
					else if(p==3){}
					else error(4);
				}
				else if(token== hodnota_string){}
				else error(4);
				strFree(&str_g);
			strInit(&str_g);
			new_token();
			if(token!=carka)error(2);
			type();
			if((token==id))
				{
					g=over(str_g.data,lokal,&p);//proveri jestli je v lokani tabulce
						if(g==NULL)
						{
							
							g=gover(str_g.data,&p);//proveri jestli je v tabulce od main
							if(g==NULL) error(3);
							if(p!=3) error(4);
						}
					else if(p==3){}
					else error(4);
				}
				else if(token== hodnota_string){}
				else error(4);
				strFree(&str_g);
				strInit(&str_g);
			new_token();
			if(token!=zavorkaD)error(2);
	}
	
	
	else if(token==id)
	{
		if((vypomoc=volanifukce(str_g.data))==NULL)
		{
			neww=2;
			strFree(&str_g);
				strInit(&str_g);
			prediktiv();
		}
		else{
			sracka=vypomoc->ktera->co;
			strFree(&str_g);
			strInit(&str_g);
			new_token();
			if(token==zavorkaP)
			{
				//printf(" a%d ",vypomoc->pocet_parametru);
				while(sracka!=NULL){
				pom=sracka->promenna;
					sracka=sracka->next;
					new_token();
						if(token==id)
							
						{
								g=over(str_g.data,lokal,&p);//proveri jestli je v lokani tabulce
								if(g==NULL)
								{
									
									g=gover(str_g.data,&p);//proveri jestli je v tabulce od main
									if(g==NULL) error(3);
									if(p!=pom->typ) error(4);
								}
							else if(p==pom->typ){}
							else error(4);
									
						}
						else if(token==hodnota_string)
						{
							zapisstring();
							if(3!=pom->typ) error(4);
						}
						else if(token==cislo_integer)
						{
							zapisint();
							if(1!=pom->typ) error(4);
						}
						else if(token==cislo_real)
						{
							zapisreal();
							if(2!=pom->typ) error(4);
							
						}
						else error(2);
				
				}
					prediktiv();
			}
			else
			{
			neww=2;
			prediktiv();
			}
		}
	}
	
	else
	{
		neww=2;
		prediktiv();
	}
}

void next()//opravit
{
	struct htab_listitem *seznam;
	new_token();
	
		if(token==id)
		{
			if((seznam=htab_lookup(lokal,str_g.data))==NULL) error(99);// ukladam do lokalni tabulkz symbolu data
					strFree(&str_g);
				 strInit(&str_g);
				new_token();
			if(token!=dvojtecka)error(2);//token se nerona se dvijtecka
			type();
			strFree(&str_g);
		strInit(&str_g);
			int c=provertyp();
			
			htab_typ(seznam,c);
			new_token();
			if(token!=strednik)error(2);//token se nerovna ;
			
			next();
		}
		else neww=2;
		
}
void en()
{
	int konec=0;
	while(konec!=1){
			new_token();
			if(token==K_end)
			{

				konec=1;
			}
			else if(token==strednik){ 
				new_token();
				if(token==K_end) error(2); //kvuli kontrole ze pred end neni ;
				else neww =2;
				sts();
				
				
			}
			else {error(2);}
	}
	
	
}

void  prediktiv(){
	
	//int g;
	
	while(token!=K_end && token!=strednik){
		new_token();
		/*if(token==id)
		{
				g=over(str_g.data,lokal);//proveri jestli je v lokani tabulce
			if(g==0)
			{
				
				g=gover(str_g.data);//proveri jestli je v tabulce od main
				if(g==0) error(3);	
			}
			
		}*/
				
				strFree(&str_g);
				strInit(&str_g);
			
		
	}
	neww=2;
	
}	

int proverfukci(){
struct htab_listglobal *seznam, *pomocna;
	 for(unsigned int pocet=0;pocet<global->htable_global;pocet++){ // projeti všech seznamu v tabulce
			seznam=global->ptrg[pocet]; // natčeni prvniho prvku
		while(seznam!=NULL){ // projeti celeho seznamu
			pomocna=seznam->nextg; // zapamotovani pristiho
			if(strcmp(str_g.data,seznam->keyg)==0) return 1;
			seznam=pomocna;//nahrani pristiho seznamu
		}	
	 }
	 return 0;
}

void prevodint(int velikost,string1 *s){
	
	int pocet;
	pocet=velikost/10 +1;
	if ((s->data = (char*) malloc((sizeof(char))*(pocet+1))) == NULL) error(99);
	
	sprintf(s->data, "%i", velikost); 
}

struct htab_listitem * zapisstring(){
	string1 key;
	struct htab_listitem *seznam;
	char *seremeto;
	
	prevodint(lokal->nahradni,&key);
	if((seznam=htab_lookup(lokal,key.data))==NULL) error(99);
	lokal->nahradni=lokal->nahradni+1;
	seznam->hodnota.stringer.allocSize=str_g.allocSize;
	seznam->hodnota.stringer.length=str_g.length;
	if ((seremeto = (char *) malloc((sizeof(char))*(strlen(str_g.data)+1))) == NULL) error(99);
	strcpy(seremeto,str_g.data);
	seznam->hodnota.stringer.data=seremeto;
	//pom=seznam->hodnota.stringer;
	htab_typ(seznam,3);
	seznam->deklarr=TRUE;
	//printf(" %s ",seznam->hodnota.stringer.data);
		strFree(&str_g);
		strInit(&str_g);
		return seznam;
	
}

struct htab_listitem * zapisint(){
	string1 key;
	//int pom;
	struct htab_listitem *seznam;
	
	prevodint(lokal->nahradni,&key);
	if((seznam=htab_lookup(lokal,key.data))==NULL) error(99);
	lokal->nahradni=lokal->nahradni+1;
	seznam->hodnota.inger=vysledek;
	//pom=seznam->hodnota.inger;
	htab_typ(seznam,1);
	seznam->deklarr=TRUE;
	//printf(" %d ",pom);
		strFree(&str_g);
		strInit(&str_g);
		return seznam;
	
}

struct htab_listitem * zapisreal(){
	string1 key;
	//double pom;
	struct htab_listitem *seznam;
	
	prevodint(lokal->nahradni,&key);
	if((seznam=htab_lookup(lokal,key.data))==NULL) error(99);
	lokal->nahradni=lokal->nahradni+1;
	seznam->hodnota.dvouger=vysldouble;
	//pom=seznam->hodnota.dvouger;
	htab_typ(seznam,2);
	seznam->deklarr=TRUE;
	//printf(" %f ",pom);
		strFree(&str_g);
		strInit(&str_g);
		return seznam;
	
}



struct htab_listitem * zapisboll(){
	string1 key;
	//bool  pom;
	struct htab_listitem *seznam;
	
	prevodint(lokal->nahradni,&key);
	if((seznam=htab_lookup(lokal,key.data))==NULL) error(99);
	lokal->nahradni=lokal->nahradni+1;
	seznam->hodnota.bunger=vysldouble;
	//pom=seznam->hodnota.bunger;
	htab_typ(seznam,4);
	seznam->deklarr=TRUE;
	//printf(" %d",pom);
		strFree(&str_g);
		strInit(&str_g);
		return seznam;
	
}

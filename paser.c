#include "interpret.h"
#include "mystring.h"

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
	int loki=0;
	struct htab_listglobal *polozka;//poloyki globalni urovne
	struct htab_listitem *seznam; //polozki lokani urovne
	while(ok==1)
	{
		new_token();
		//printf("%d", token);
		if(token==K_begin)// pokud zaciname begin prvidla ll
		{ 
			
			sts();
			en();
			printf("Q");
			new_token();
			if(token==tecka)//token se musi rovnat tecte
			{
				ok=0;// konec programu
			}
		}
		else if(token==K_var)//pokud = var
		{
			
			new_token();
			if(token!=id)error(2);//pokud se nerovna id
			else
			{
				if(loki==0)// pokud je globalni var tak je to pro main a musim zalozit tabulku pro funkci main
				{
					if((polozka=htab_lookupg(global,"1main"))==NULL) error(99);//zakladam tabulku symbolu pro funkci main a ukladam do globalni prmenne pod nayvem 1main
					lokal=polozka->ktera;
					if((seznam=htab_lookup(lokal,(str_g.data)))==NULL) error(99);// ukladam do lokalni tabulkz symbolu data
					 strFree(&str_g);
				 strInit(&str_g);
				 loki=1;
					
				}
				else
				{
					if((seznam=htab_lookup(lokal,str_g.data))==NULL) error(99);// ukladam do lokalni tabulkz symbolu data
					 strFree(&str_g);
				 strInit(&str_g);
				}
			}
			//printf("ok");
			new_token();
			if(token!=dvojtecka)error(2);//token se nerona se dvijtecka
			
			type();
			
			new_token();
			if(token!=strednik)error(2);//token se nerovna ;
			
			next();
		}
		else if(token==K_function)//pokud se rovna func
		{	
			loki=1;
			new_token();
			if(token!=id)error(2);//musi rovnat id
			new_token();
			if(token!=zavorkaP)error(2);//musi rovnat(
				params();
			new_token();
			if(token!=zavorkaD)error(2);//musi rovnat)
			new_token();
			if(token!=dvojtecka)error(2);//token se nerona se dvijtecka
				type();
			new_token();
			if(token!=strednik)error(2);//token se nerovna ;
			returnn();
			
		}
		else error(2);
	}
	return 0;
}

void type(){
	new_token();
	if(token==K_integer){}
	else if(token==K_real){}
	else if(token==cislo_real){}
	else if(token==cislo_integer){}
	else if(token==hodnota_string){}
	
	else if(token==K_string){}
	else if(token==K_boolean){}
	else if(token==id)
	{ 
		strFree(&str_g);
		strInit(&str_g);
	}//dopis jak budes chctit id doplnit id chyba
	else {error(2);}			
}

void params(){
	new_token();
	if(token==id)
	{
		new_token();
		if(token!=dvojtecka)error(2);//token se nerona se dvijtecka
		type();
		params_next();
	}
	else neww=2;
}

void params_next(){
	new_token();
	if(token==id)
	{ 
		new_token();
		if(token!=dvojtecka)error(2);//token se nerona se dvijtecka
		type();
		params_next();
		
	}
	else neww=2;
	
}
void returnn()
{
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
	new_token();
	if(token==id)
	{
		new_token();
		if(token!=dvojtecka)error(2);
			new_token();
		if(token!=rovnase)error(2);
		type();
		expr();
	
			
	}
	else if(token==K_while){
		type();
		op();
		type();
		new_token();
		if(token!=K_do)error(2);
		new_token();
		if(token!=K_begin)error(2);
		
		
	}
	else if(token==K_if){
		
		type();
	
		op();
		type();
		
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
		printf("tadz");
		en();
		
		
		
		
	}
	else if(token==K_readln){
		
		new_token();
		if(token!=zavorkaP)error(2);
		new_token();
		if(token!=id)error(2);
		else
		{
			strFree(&str_g);
			strInit(&str_g);
		}
		new_token();
		if(token!=zavorkaD)error(2);
		
		
	}
	else if(token==K_write){
		new_token();
		if(token!=zavorkaP)error(2);
		type();
		rite();
		new_token();
		if(token!=zavorkaD)error(2);
		
		
	}
	else {neww=2;}
		
		
}

void rite()
{
	new_token();
	if(token==carka)
	{
		type();
		rite();
	}
	else neww=2;
}

void expr()
{
	new_token();
	if(token==K_sort)
	{
		new_token();
		if(token!=zavorkaP)error(2);
		type();
		new_token();
		if(token!=zavorkaD)error(2);
	}
	/*else if(token==K_copy)
	{
		new_token();
		if(token!=zavorkaP)error(2);
		type();
		new_token();
		if(token!=dvojtecka)error(2);
		type();
		new_token();
		if(token!=dvojtecka)error(2);
		type();
		new_token();
		if(token!=zavorkaD)error(2);
	}
	if(token==K_leight)
	{
		new_token();
		if(token!=zavorkaP)error(2);
		type();
		new_token();
		if(token!=zavorkaD)error(2);
	}*/
	
	else neww=2;
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
			else if(token==strednik){ sts();}
			else {error(2);}
	}
	
	
}
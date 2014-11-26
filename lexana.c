#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "interpret.h"

#define INVALID_SRCFILE 1
#define VALID_SRCFILE 0
FILE* srcfile;
//otevirani souboru
int opensrcfile(char *filename)
{
    srcfile = fopen(filename,"r");
    if (srcfile == NULL)
    {
        printf("\nSoubor %s neexistuje \n",filename);
        return INVALID_SRCFILE;
    }
    return VALID_SRCFILE;
}
void closesrcfile (){
        fclose(srcfile);
        return;
}


int get_token(){
	int znak;
	int stav=0;
	typp co;
	while(stav!=8){
	znak=fgetc(srcfile);
	switch(stav)
	{
	case 0:
	 if((znak==' ') || (znak=='\n')) stav=0;// bily znak
	else if ((znak == '_') || ((znak >= 'A')&& (znak<='Z')) || ((znak >= 'a') && (znak <='z')))
	{
		stav=1;// id
		strAddChar(&str_g,znak);
	}
	else if ((znak >= '0') && (znak <='9')) stav=2; //cislo dodelej cislo predavani cisla
	else if (znak=='{') stav=3; //komentar
	else if (znak=='>')stav=4;
	else if	 (znak=='<') stav=5;
	else if (znak=='=') return rovnase;
	else if (znak==';') return strednik;
	else if (znak=='+') return plus;
	else if (znak=='*') return krat;
	else if	(znak=='-') return minus;
	else if (znak=='/') return deleno;
	else if	(znak=='(') return zavorkaP;
	else if	 (znak==')') return zavorkaD; 
	else if	 (znak==':') return dvojtecka;
	else if	 (znak==',') return carka;
	else if	 (znak=='.') return tecka;
	else if  (znak==EOF)
	{ 
		stav=8;
		return konec;
	}
		 
	else if (znak=='?') stav=6;
	else if (znak == '#') stav=2;
	else error(1);
		 break;
	case 1:
	 
		 if ((znak == '_') || ((znak >= 'A')&& (znak<='Z')) || ((znak >= 'a') && (znak <='z')) || ((znak >= '0') && (znak <='9')))
		 {
			
		strAddChar(&str_g,znak);
	 
			 stav=1;
		 }
		 else 
		 {
			 stav=0;
			  
			 ungetc(znak, srcfile);
			 co=porovnej();
			 return co;
			  
		 }
		 break;
	case 2:
		if ((znak >= '0') && (znak <='9')) stav=2;
		else if(znak=='.') stav=9;
		 else
		 {
			 stav=0;
			 ungetc(znak, srcfile);
			 return cislo_integer;
		 }
		break;
	case 3:
		if (znak=='}') stav=0;
		 else stav=3;
		 break;
	case 4:
		if(znak=='=')
		{
			stav=0;
			return vetsi_rovnase;
		}
		 else 
		 {
			  stav=0;
			 ungetc(znak, srcfile);
			 return vetsi;
		 }
		break;
	 case 5:
		 if(znak=='=')
		 {
			 stav=0;
			 return mensi_rovnase;
			
		 }
		 else if(znak=='>')
		 {
			 stav=0;
			 return nerovna;
		 }
		  else 
		 {
			  stav=0;
			 ungetc(znak, srcfile);
			 return mensi;
		 }
		 break;
	 case 6:
		 if(znak=='?') 
		 {
			  
			 stav=11;
			 
		 }
		 else if(znak=='#')
		 {
			 stav=10;
		 }
		 
		 else stav=6;
		 break;
	 case 7:
		if ((znak >= '0') && (znak <='9')) stav=7;
		 break;
	case 9:
		 if ((znak >= '0') && (znak <='9')) stav=9;
		 else
			  {
			 stav=0;
			 ungetc(znak, srcfile);
			 return cislo_real;
		 }
		 break;
	case 10:
		if ((znak >= '0') && (znak <='9')) stav=10;
		 if(znak=='?') 
			  {
			 stav=0;
			 return hodnota_string;//udelej prechod kuba ho mozna ma
		 }
		 else error(1);
		break;
	case 11:
		if(znak=='#')
			stav=12;
			else
			  {
			 stav=0;
			 ungetc(znak, srcfile);
			 return hodnota_string;
			}
			break;
	case 12:
		if ((znak >= '0') && (znak <='9')) stav=12;
		if(znak=='?') 
			  {
			 stav=6;
			 //udelej prechod kuba ho mozna ma
		 }
		
		
	}
	
	}	
	return 0;
}

typp porovnej()//porovna jestli je to klicove slovo
{
	 if (strcmp(str_g.data, "begin") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_begin;
	 }
	 else if (strcmp(str_g.data, "boolean") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_boolean;
	 }
	 else if (strcmp(str_g.data, "do") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_do;
	 }
	 else if (strcmp(str_g.data, "else") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_else;
	 }
	 else if (strcmp(str_g.data, "end") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_end;
	 }
	 else if (strcmp(str_g.data, "find") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_find;
	 }
	 else if (strcmp(str_g.data, "forward") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_forward;
	 }
	 else if (strcmp(str_g.data, "function") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_function;
	 }
	 else if (strcmp(str_g.data, "if") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_if;
	 }
	 else if (strcmp(str_g.data, "integer") == 0){
		  strFree(&str_g);		
			strInit(&str_g);
			return K_integer;
	 }
	 else if (strcmp(str_g.data, "readln") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_readln;
	 }
	 else if (strcmp(str_g.data, "real") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_real;
	 }
	 else if (strcmp(str_g.data, "sort") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_sort;
	 }
	 else if (strcmp(str_g.data, "string") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_string;
	 }
	 else if (strcmp(str_g.data, "then") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_then;
	 }
	 else if (strcmp(str_g.data, "true") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_true;
	 }
	 else if (strcmp(str_g.data, "var") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_var;
	 }
	 else if (strcmp(str_g.data, "while") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_while;
	 }
	 else if (strcmp(str_g.data, "write") == 0){
		  strFree(&str_g);
			strInit(&str_g);
			return K_write;
	 }
	 
	 else return id;

}
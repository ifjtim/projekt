#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "interpret.h"
#include "mystring.h"
#include "ial.h"
#define INVALID_SRCFILE 1
#define VALID_SRCFILE 0
string1 pomoc,term;
FILE* srcfile;
//otevirani souboru
	int opensrcfile(char *filename)
	{
		srcfile = fopen(filename,"r");
		if (srcfile == NULL)
		{
			printf("\nSoubor %s neexistuje \n",filename);
			error(99);
			return INVALID_SRCFILE;
		}
	return VALID_SRCFILE;
	}
	void closesrcfile (){
	fclose(srcfile);
	return;	
	}
	int get_token(){
	int znak,pomoc0,pomoc2;
	int stav=0;
	typp co;
	
	
		while(stav!=8){
		znak=fgetc(srcfile);
		
		switch(stav)
		{	
			case 0:
				if (isspace(znak)) stav=0;// bily znak
				else if ((znak == '_') || ((znak >= 'A')&& (znak<='Z')) || ((znak >= 'a') && (znak <='z')))
				{
						stav=1;// id
						strAddChar(&str_g,znak);
				}
				else if ((znak >= '0') && (znak <='9'))
				{
					stav=2;
					strAddChar(&str_g,znak);
					strAddChar(&pomoc,znak);
				}//cislo dodelej cislo predavani cisla
				else if (znak=='{') stav=3; //komentar
				else if (znak=='>')stav=4;
				else if	(znak=='<') stav=5;
				else if (znak=='=') return rovnase;
				else if (znak==';') return strednik;
				else if (znak=='+') return plus;
				else if (znak=='*') return krat;
				else if	(znak=='-') return minus;
				else if (znak=='/') return deleno;
				else if	(znak=='(') return zavorkaP;
				else if	(znak==')') return zavorkaD;
				else if	(znak==':') return dvojtecka;
				else if	(znak==',') return carka;
				else if	(znak=='.') return tecka;
				else if (znak==EOF)
				{
					stav=8;
					return konec;
				}
				else if (znak=='\'')
				{
					
					stav=6;
					strAddChar(&term,znak);
				}
				else if (znak == '#') stav=2;
				else error(1);
				break;
				/*kdzy je to id*/
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
				/*kdyz je to cislo*/
				case 2:
					if ((znak >= '0') && (znak <='9'))
					{
						strAddChar(&str_g,znak);
						strAddChar(&pomoc,znak);
						stav=2;
					}
					else if(znak=='.')
					{
						strAddChar(&str_g,znak);
						strFree(&pomoc);
							strInit(&pomoc);
						
						stav=9;
					}
					else if((znak=='+') || (znak=='-')) //poze tyto znaki ukoncuji literar ciselny 
					{
							stav=14;
							strAddChar(&pomoc,znak);
							pomoc0=znak;
					}
					else if((znak=='e') || (znak=='E'))
					{
						stav=13;
						strAddChar(&pomoc,znak);
					}
					else if((znak=='*')||(znak=='/')||(znak=='(')||(znak==')')||(znak==';')) //poze tyto znaki ukoncuji literar ciselny
					{
							stav=0;
							ungetc(znak, srcfile);
							strtoint (str_g.data);
							strFree(&pomoc);
							strInit(&pomoc);
							return cislo_integer;
					}
					else if((znak=='{')||(znak=='<')||(znak=='>')||(znak==',')||(znak=='=')||(znak==':')) //poze tyto znaki ukoncuji literar ciselny
					{
								stav=0;
							ungetc(znak, srcfile);
							strtoint (str_g.data);
							strFree(&pomoc);
							strInit(&pomoc);
							return cislo_integer;
					}
					else if (isspace(znak)) //poze tyto znaki ukoncuji literar ciselny
					{
						stav=0;
						ungetc(znak, srcfile);
						strtoint (str_g.data);
						strFree(&pomoc);
							strInit(&pomoc);
						return cislo_integer;
					}
					else
					{
						error(1);
					}
				break;
				/*kdzy je to kometar*/
				case 3:
					if (znak=='}') stav=0;// ukonceni komentare
					else stav=3;
				break;
				/*kdyz je vetsi nebo vetsi rovnase*/
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
				/*kdyz je mensi nebo mensi rovnase*/
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
				//je to retezec
				case 6:
					if(znak=='\'')
						{
						stav=11;
					  strAddChar(&term,znak);
						}
					else if(znak=='#')
						{
						stav=10;
						}
					else
					{
						strAddChar(&term,znak);
						stav=6;
					}
				break;
				case 7:
					if ((znak >= '0') && (znak <='9')) stav=7;
				break;
				/*hodnota typu real*/
				case 9:
					if ((znak >= '0') && (znak <='9'))
					{
						strAddChar(&str_g,znak);
						stav=9;
					}
					else if((znak=='+') || (znak=='-')) 
					{
							stav=0;
							ungetc(znak, srcfile);
							strtofloat(str_g.data);
							return cislo_real;
					}
					else if((znak=='*')||(znak=='/')||(znak=='(')||(znak==')')||(znak==';'))
					{
							stav=0;
							ungetc(znak, srcfile);
							strtofloat(str_g.data);
							return cislo_real;
					}
					else if((znak=='{')||(znak=='<')||(znak=='>')||(znak==',')||(znak=='=')||(znak==':')) 
					{
								stav=0;
							ungetc(znak, srcfile);
							strtofloat(str_g.data);
							return cislo_real;
					}
					else if (isspace(znak))
					{
						stav=0;
						ungetc(znak, srcfile);
						strtofloat(str_g.data);
						return cislo_real;
					}
					else
					{
						error(1);
					}
					break;
					case 10:
						if ((znak >= '0') && (znak <='9')) stav=10;
						if(znak=='\'')
						{
						stav=0;
						return hodnota_string;//udelej prechod kuba ho mozna ma
						}
						else error(1);
					break;
					case 11:
						if(znak=='#')
						{
						stav=12;
						strAddChar(&term,znak);
						}
						else
						{
						stav=0;
						
						ungetc(znak, srcfile);
						
						//printf(" %s ",term.data);
						//printf(" %d ",term.data[0]);
						cString(&str_g,&term);
						strFree(&term);
						strInit(&term);
						return hodnota_string;
						}
					break;
					case 12:
						if ((znak >= '0') && (znak <='9')) 
						{
							strAddChar(&term,znak);
							stav=12;
						}
						if(znak=='\'')
						{
							strAddChar(&term,znak);
						stav=6;
						
					//udelej prechod kuba ho mozna ma
						}
					break;
					case 13:
						if ((znak >= '0') && (znak <='9')) 
						{
							strAddChar(&pomoc,znak);
							stav=13;
						}//over e na 0
						else if((znak=='+') || (znak=='-')) //poze tyto znaki ukoncuji literar ciselny 
						{
							stav=0;
							ungetc(znak, srcfile);
							prevede();
							return cislo_real;
						}
				
						else if((znak=='*')||(znak=='/')||(znak=='(')||(znak==')')||(znak==';')) //poze tyto znaki ukoncuji literar ciselny
						{
								stav=0;
								ungetc(znak, srcfile);
								prevede();
								return cislo_real;
						}
						else if((znak=='{')||(znak=='<')||(znak=='>')||(znak==',')||(znak=='=')||(znak==':')) //poze tyto znaki ukoncuji literar ciselny
						{
									stav=0;
								ungetc(znak, srcfile);
								prevede();
								return cislo_real;
						}
						else if (isspace(znak)) //poze tyto znaki ukoncuji literar ciselny
						{
							stav=0;
							ungetc(znak, srcfile);
							prevede();
							return cislo_real;
						}
						else
						{
							error(1);
						}
					break;
					case 14:
						if ((znak == 'E') || (znak =='e'))
						{
							pomoc2=znak;
							strAddChar(&pomoc,znak);
							stav=15;
						}
						else
						{
							stav=0;
							ungetc(znak, srcfile);
							ungetc(pomoc0, srcfile);
							strtoint (str_g.data);
							strFree(&pomoc);
							strInit(&pomoc);
							return cislo_integer;
						}
					break;
					case 15:
						if ((znak >= '0') && (znak <='9')) 
						{
							strAddChar(&pomoc,znak);
							stav=13;
						}
						else if((znak=='+') || (znak=='-')) //poze tyto znaki ukoncuji literar ciselny 
						{
							stav=0;
							ungetc(znak, srcfile);
							prevede();
							return cislo_real;
						}
				
						else if((znak=='*')||(znak=='/')||(znak=='(')||(znak==')')||(znak==';')) //poze tyto znaki ukoncuji literar ciselny
						{
								stav=0;
								ungetc(znak, srcfile);
								prevede();
								return cislo_real;
						}
						else if((znak=='{')||(znak=='<')||(znak=='>')||(znak==',')||(znak=='=')||(znak==':')) //poze tyto znaki ukoncuji literar ciselny
						{
									stav=0;
								ungetc(znak, srcfile);
								prevede();
								return cislo_real;
						}
						else if (isspace(znak)) //poze tyto znaki ukoncuji literar ciselny
						{
							stav=0;
							ungetc(znak, srcfile);
							prevede();
							return cislo_real;
						}
						else
						{
							stav=0;
							ungetc(znak, srcfile);
							ungetc(pomoc0, srcfile);
							ungetc(pomoc2, srcfile);
							strtoint (str_g.data);
							strFree(&pomoc);
							strInit(&pomoc);
							return cislo_integer;
						}
					break;
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
		else if (strcmp(str_g.data, "copy") == 0){
		strFree(&str_g);
		strInit(&str_g);
		return F_copy;
		}
		else if (strcmp(str_g.data, "leight") == 0){
		strFree(&str_g);
		strInit(&str_g);
		return F_leight;
		}
		else return id;
	}

void prevede(){
int jedna=0,dva=0,povol=0,povoll=0;
 int c=0;
int x=0;
for (x=0;x<strlen(pomoc.data);x++){

c=(pomoc.data)[x];

if((c=='e' )|| (c=='E') || (c=='+' ))
{
	povol=1;
	continue;
}
if(c=='-')
{
	povoll=3;
	continue;
}
	

c=c-'0';
if(povol==1)
{
dva=dva*10; //dekadicky posun
dva=dva+c;
}
else
{
	jedna=jedna*10; //dekadicky posun
jedna=jedna+c;
}

}

if(povoll==3)
{
	prevedfloat(jedna,dva);
}
else prevedint(jedna,dva);

strFree(&pomoc);
strInit(&pomoc);
}

void prevedfloat(int jedna, int dva)
{
	float v=1;
	for(int a=0;a<dva;a++){

	v=v*jedna;
}
v=1/v;
vysldouble=v;

}

void prevedint(int jedna, int dva)
{
	int v=1;
	for(int a=0;a<dva;a++){

	v=v*jedna;
}
vysledek=v;
}

void strtoint (char * S1)
{
	int c=0;
	int x=0;
	int v=0;
	for (x=0;x<strlen(S1);x++){
		c=S1[x]-'0';//aktualní char na int
		v=v*10; //dekadicky posun
		v=v+c;
	}
	 vysledek=v;
}

	void strtofloat(char *S1)
	{
		char *stopstring;
		double b;
		b = strtod(S1,&stopstring);
		vysldouble=b;
	}
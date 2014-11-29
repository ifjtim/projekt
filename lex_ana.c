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
	char znak;
	int stav;
	while(stav!=7){
	znak=fgetc(srcfile);
	switch(stav)
	{
	case 0:
	if(znak==' ') stav=0;// bily znak
	if ((znak == '_') || (znak >= 'A')&& (znak<='Z')) || ((znak >= 'a') && (znak <='z')))stav=1;// id
	if ((znak >= '0') && (znak <='9')|| ((znak >= '#')) stav=2; //cislo
	if (znak=='{') stav=3; //komentar
	if (znak=='>')stav=4;
	if	 (znak=='<') stav=5;
	if (znak=='=') return rovnase;
	if (znak=='+') return plus;
	if (znak=='*') return krat;
	if	(znak=='-') return minus;
	if (znak=='/') return deleno;
	if	(znak=='(') return zavorkaP;
	if	 (znak==')') return zavorkaD; 
	if	 (znak==':') return dvojtecka;
	if	 (znak==',')return carka;
		 
	if ((znak=='?')stav=6;
	case 1:
	 
		 if ((znak == '_') || (znak >= 'A')&& (znak<='Z')) || ((znak >= 'a') && (znak <='z')) || (znak >= '0') && (znak <='9')) stav=1;
		 else 
		 {
			 stav=0;
			 ungetc(znak, srcfile);
			 return id;
			  
		 }
		 break;
	case 2:
		if ((znak >= '0') && (znak <='9')) stav=2;
		 else
		 {
			 ungetc(znak, srcfile);
			 return cislo_integer;
		 }
		break;
	case 3:
		if (znak=='}') stav=0;
		 else stav=3;
	case 4:
		if(znak=='=')
		{
			stav=0;
			return vetsi_nerovnase;
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
			 return mensi_nerovnase;
			
		 }
		 if else(znak=='>')
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
			 stav=0;
			 return K_string;
		 }
		 else stav=6;
		 break;
		 
	}
	}	
	return 0;
}
/*
int get_token(){
	char ch;
	stav_type stav = start;
do {
        if ((ch = getc(srcfile)) == EOF) {
            // jestlize se jedna o prvni cteni, tj. neni rozecten zadny token, vrati se NULL= konec zdrojoveho souboru
					if (stav == start)
					{
						return 0;
					} 
					else
					{
                ungetc(ch, srcfile); // vrat eof do cteneho suboru aby se priste ukoncilo korektne nacitani zdrojoveho souboru
					}

        }
        switch (stav) {
        case start:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = cele_cislo;
                    
                    break;
                case pismeno:
                    stav = identifikator;
                    
                    break;
                case pismeno_e:
                    stav = identifikator;
                    
                    break;
                case strednik:
                    return 3;
                    break;
                case plus_znak:
                    return 4;
                    break;
                case minus_znak:
                    return 5;
                    break;
                case krat_znak:
                    return 6;
                    break;
                case lomeno_znak:
                    return 7;
                    break;
                case rovno_znak:
                    return 12;
                    break;
                case vetsi_znak:
                    stav = vetsi_stav;
                    break;
                case dvoj_tecka:
                    stav = dvoj_tecka_stav;
                    break;
                case apostrof:
                    return 13;
                    break;
                case ls_zavorka:
                    return 14;
                    break;
                case ps_zavorka:
                    return 15;
                    break;
                case escape:
                    stav = escape_stav;
                    
                    break;
                case ls_zavorka_kom:
                    stav = komentar;
                    break;
                case white_space:
                    stav = start;
                    break;
                default:
                   stav=konec;
                    break;
                }
            break;
        case dvoj_tecka_stav:
                switch (get_char_type(ch)) {
                case rovno_znak:
                    return 40;
                    break;
                default:
                    ungetc(ch, srcfile);
                    return 18;
                    break;
                }
        case vetsi_stav:
                switch (get_char_type(ch)) {
                case rovno_znak:
                    return 10;
                    break;
                default:
                    ungetc(ch, srcfile);
                    return 8;
                    break;
                }
        case mensi_stav:
                switch (get_char_type(ch)) {
                case rovno_znak:
                    return 11;
                    break;
                case vetsi_znak:
                    return 41;
                    break;
                default:
                    ungetc(ch, srcfile);
                    return 9;
                    break;
                }
        case cele_cislo:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = cele_cislo;
                    
                    break;
                case tecka:
                    stav = realne_cislo;
                    
                    break;
                case pismeno_e:
                    stav = cislo_e;
                    
                    break;
                case plus_znak:
                    stav = cislo_operator;
                    
                    break;
                default:
                    ungetc(ch, srcfile);
                    //sscanf(token_str,"%d", &(token.value.intval));
                    return 2;
                }
        case realne_cislo:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = realne_cislo;
                    
                    break;
                case pismeno_e:
                    stav = cislo_e;
                   
                    break;
                case plus_znak:
                    stav = cislo_operator;
                    
                    break;
                case minus_znak:
                    stav = cislo_operator;
                    
                    break;
                default:
                    ungetc(ch, srcfile);
                    //sscanf(token_str,"%d", &(token.value.intval));
                    return 2;
                }
        case escape_stav:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = escape_stav;
                    
                    break;
                default:
                    ungetc(ch, srcfile);
                    //sscanf(token_str,"%d", &(token.value.intval));
                    return 16;
                }
        case cislo_e:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = cislo_e;
                    
                    break;
                default:
                    ungetc(ch, srcfile);
                    //sscanf(token_str,"%d", &(token.value.intval));
                    return 2;
                }
        case cislo_operator:
                switch (get_char_type(ch)) {
                case pismeno_e:
                    stav = cislo_e;
                    
                    break;
                default:
                    ungetc(ch, srcfile);
                    ungetc(ch, srcfile);
                    
                    //sscanf(token_str,"%d", &(token.value.intval));
                    return 2;
                }
        case identifikator:
                switch (get_char_type(ch)){
                case pismeno:
                    stav = identifikator;
                    
                    break;
                case pismeno_e:
                    stav = identifikator;
                    
                    break;
                default:
                   /* switch (identifikator_compare (token_str)){
                    case begin_id:
                        ungetc(ch, srcfile);
                        return 20;
                    case boolean_id:
                        ungetc(ch, srcfile);
                        return 21;
                    case do_id:
                        ungetc(ch, srcfile);
                        return 22;
                    case else_id:
                        ungetc(ch, srcfile);
                        return 23;
                    case end_id:
                        ungetc(ch, srcfile);
                        return 24;
                    case false_id:
                        ungetc(ch, srcfile);
                        return 25;
                    case find_id:
                        ungetc(ch, srcfile);
                        return 26;
                    case forward_id:
                        ungetc(ch, srcfile);
                        return 27;
                    case function_id:
                        ungetc(ch, srcfile);
                        return 28;
                    case if_id:
                        ungetc(ch, srcfile);
                        return 29;
                    case integer_id:
                        ungetc(ch, srcfile);
                        return 30;
                    case readln_id:
                        ungetc(ch, srcfile);
                        return 31;
                    case real_id:
                        ungetc(ch, srcfile);
                        return 32;
                    case sort_id:
                        ungetc(ch, srcfile);
                        return 33;
                    case string_id:
                        ungetc(ch, srcfile);
                        return 34;
                    case then_id:
                        ungetc(ch, srcfile);
                        return 35;
                    case true_id:
                        ungetc(ch, srcfile);
                        return 36;
                    case var_id:
                        ungetc(ch, srcfile);
                        return 37;
                    case while_id:
                        ungetc(ch, srcfile);
                        return 38;
                    case write_id:
                        ungetc(ch, srcfile);
                        return 39;
                    default:
                        ungetc(ch, srcfile);
                        return 1;
                    }
                   
                    break;
                }
        case komentar:
                switch (get_char_type(ch)) {
                case ps_zavorka_kom:
                    stav = start;
                    break;
                default:
                    stav = komentar;
                    break;
                }
			 case konec:
				 stav=konec;
				 break;
        }

    } while(stav != konec);
}
*/
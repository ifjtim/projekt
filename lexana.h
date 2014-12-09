#ifndef lexana_H
#define lexana_H

int opensrcfile(char *filename);// tom: otevøeni souboru
void closesrcfile ();           // tom: zavøeni souboru
int get_token();
void prevede();
void prevedfloat(int jedna, int dva);
void prevedint(int jedna, int dva);
void strtoint (char * S1);
void strtofloat(char *S1);
int vysledek;
double vysldouble;
typedef enum{ nic,id,cislo_real,cislo_integer,hodnota_string,plus,minus,krat,deleno,vetsi,mensi,mensi_rovnase,vetsi_rovnase,rovnase,nerovna,
zavorkaP,zavorkaD,dvojtecka,carka,strednik,tecka,K_begin,K_boolean,K_do,K_else,K_end,K_false,K_find,K_forward,K_function,K_if,K_integer,K_readln,K_real,K_sort,
K_string,K_then,K_true,K_var,K_while,K_write,F_copy,F_leight,konec}typp;

typp token; //typ tokenu
/********************************************************string*******************************************************************/
typp porovnej();
#endif
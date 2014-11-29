/*************************************TABULKA ZNAKU*********************************************************************/
#include<stdio.h>
#include<stdlib.h>

/***************************************SYNTAKTCKA ANALIZA***************************************************************/

int opensrcfile(char *filename);// tom: otevøeni souboru
void closesrcfile ();           // tom: zavøeni souboru
int get_token();

typedef enum{ nic,id,cislo_real,cislo_integer,hodnota_string,plus,minus,krat,deleno,vetsi,mensi,mensi_rovnase,vetsi_rovnase,rovnase,nerovna,
zavorkaP,zavorkaD,dvojtecka,carka,strednik,tecka,K_begin,K_boolean,K_do,K_else,K_end,K_false,K_find,K_forward,K_function,K_if,K_integer,K_readln,K_real,K_sort,
K_string,K_then,K_true,K_var,K_while,K_write,konec}typp;
// globalni promenna
//extern char *token_str;
/********************************************************string*******************************************************************/
typp porovnej();
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct String{
  int length;
  char *data;
  int allocSize;
} string;


int lenght(string *s);
int newStrAlloc(char *p);
int newStr(char *p);
int cString(string *s1, char *p);
int strAddChar(string *s1, char c);
int strInit(string *s);
void strFree(string *s);
char *copy(string *s, int i, int n);
*/
/*******************************parser*************************************************************************************************************/
int neww;
typp token;
void sts();
void new_token();
int func();
void type();
void params();
void params_next();
void op();
void sts();
void rite();
void expr();
void next();
void returnn();
void en();

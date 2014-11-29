/*************************************TABULKA ZNAKU*********************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define VELIKOST 127
#define POCET 16381

int error(int cislo_err);

struct htab_listitem{  // struktura pro tabulku znaku key je jmeno idefikatora
char *key;
unsigned int typ;
struct htab_listitem *next;
};

struct htab_t{
unsigned int htable_size;
struct htab_listitem *ptr[];
};

struct htab_global{
unsigned int htable_global;
struct htab_listglobal *ptrg[];
};

struct htab_listglobal{  // struktura pro tabulku znaku key je jmeno idefikatora
char *keyg;
unsigned int typg;
struct htab_t *ktera;
//tList *adres;// zacatek seynamu instrukci 
struct htab_listglobal *nextg;
};
// struktura instrukci
 struct TreAdres {
struct TreAdres *ptrr;
struct TreAdres *skok;
struct htab_listitem  operand1;
struct htab_listitem  operand2;
struct htab_listitem  operat;
int indetifikator;
};

typedef struct { 
    struct TreAdres Act;
    struct TreAdres First;
} tList;
struct htab_global *global;
struct htab_t *lokal;
//char *funkce;

void smaz();
struct htab_global *htab_initg(int size);
struct htab_listglobal * htab_lookupg(struct htab_global *t, const char *key); //vlo¾eni id
void htab_typg(struct htab_listglobal *seznam,int typ);                  //vlozeni typu
void freeg(struct htab_global *t);                                    //uvolneni tabuky
void htab_clearg(struct htab_global *t);    

struct htab_t *htab_init(int size);
struct htab_listitem * htab_lookup(struct htab_t *t, const char *key); //vlo¾eni id
void htab_typ(struct htab_listitem *seznam,int typ);                  //vlozeni typu
void htab_free(struct htab_t *t);                                    //uvolneni tabuky
void htab_clear(struct htab_t *t);   //uvoleneni seynamu
unsigned int hash_function(const char *str, unsigned htable_size);   //hash_funkce


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

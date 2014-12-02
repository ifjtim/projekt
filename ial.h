
void bLast(string1 *search, int *last);
int find(string1 *s, string1 *search);

char *sort(string1 *s);



#define VELIKOST 127
#define POCET 16381
#include<stdbool.h>

#define FALSE 0
#define TRUE 1

int error(int cislo_err);

typedef union co
{
	bool bunger;
	int inger;
	double dvouger;
	string1 stringer;
}Tco;

struct htab_listitem{  // struktura pro tabulku znaku key je jmeno idefikatora
char *key;
unsigned int typ;
Tco  hodnota;
struct htab_listitem *next;
};

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

struct htab_global *global;
struct htab_t *lokal;
struct htab_t *lokal_lobal;
//char *funkce;


void smaz();
int over(char *k,struct htab_t *t);
struct htab_global *htab_initg(int size);
struct htab_listglobal * htab_lookupg(struct htab_global *t, const char *key); //vloženi id
void htab_typg(struct htab_listglobal *seznam,int typ);                  //vlozeni typu
void freeg(struct htab_global *t);                                    //uvolneni tabuky
void htab_clearg(struct htab_global *t);    

struct htab_t *htab_init(int size);
struct htab_listitem * htab_lookup(struct htab_t *t, const char *key); //vloženi id
void htab_typ(struct htab_listitem *seznam,int typ);                  //vlozeni typu
void htab_free(struct htab_t *t);                                    //uvolneni tabuky
void htab_clear(struct htab_t *t);   //uvoleneni seynamu
unsigned int hash_function(const char *str, unsigned htable_size);   //hash_funkce
void vypis(struct htab_t *t);
void vypisg(struct htab_global *t);

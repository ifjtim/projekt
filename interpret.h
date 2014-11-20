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


struct htab_t *htab_init(int size);
struct htab_listitem * htab_lookup(struct htab_t *t, const char *key); //vlo¾eni id
void htab_typ(struct htab_listitem *seznam,int typ);                  //vlozeni typu
void htab_free(struct htab_t *t);                                    //uvolneni tabuky
void htab_clear(struct htab_t *t);                                   //uvoleneni seynamu
unsigned int hash_function(const char *str, unsigned htable_size);   //hash_funkce
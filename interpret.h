#include<stdio.h>
#include<stdlib.h>

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
struct htab_listitem * htab_lookup(struct htab_t *t, const char *key); //vlo�eni id
void htab_remove(struct htab_t *t,const char *key);
void htab_foreach(struct htab_t *t,void (*function) (const char *key,unsigned int data ));
void htab_free(struct htab_t *t);
void htab_clear(struct htab_t *t);
unsigned int hash_function(const char *str, unsigned htable_size);
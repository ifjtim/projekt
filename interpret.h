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
struct TreAdres *adres;// zacatek seynamu instrukci 
struct htab_listglobal *nextg;
};
// struktura instrukci
 struct TreAdres {
struct TreAdres *ptr;
struct TreAdres *skok;
int operand1;
int operand2;
int operat;
int indetifikator;
};

void smaz();
struct htab_t *htab_init(int size);
struct htab_listitem * htab_lookup(struct htab_t *t, const char *key); //vlo¾eni id
void htab_typ(struct htab_listitem *seznam,int typ);                  //vlozeni typu
void htab_free(struct htab_t *t);                                    //uvolneni tabuky
void htab_clear(struct htab_t *t);                                   //uvoleneni seynamu
unsigned int hash_function(const char *str, unsigned htable_size);   //hash_funkce


/***************************************SYNTAKTCKA ANALIZA***************************************************************/

int opensrcfile(char *filename);// tom: otevøeni souboru
void closesrcfile ();           // tom: zavøeni souboru
int get_token();
typedef enum{
    start,
    cele_cislo, realne_cislo, cislo_e, cislo_operator,
    identifikator, escape_stav,
    dvoj_tecka_stav, komentar, vetsi_stav, mensi_stav,
    konec
} stav_type;

typedef enum{
    white_space, cislo, pismeno, strednik, apostrof, ls_zavorka, ps_zavorka, escape, tecka, dvoj_tecka, ls_zavorka_kom, ps_zavorka_kom, carka, ostatni_znaky,
    plus_znak, minus_znak, krat_znak, lomeno_znak, vetsi_znak, mensi_znak, rovno_znak, pismeno_e
} character_type;

typedef enum{
begin_id, boolean_id, do_id, else_id, end_id, false_id, find_id, forward_id, function_id, if_id, integer_id, readln_id, real_id, sort_id, string_id, then_id, true_id, var_id, while_id, write_id,
} identifikator_type;
// globalni promenna
//extern char *token_str;

/*******************************parser*************************************************************************************************************/


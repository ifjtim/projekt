/* ------------------Název-projektu------------------
 * Implementace interptetu imperativního jazyka IFJ14
 * ----------------------Autoři----------------------
 * xkonde03  Konderla Tomasz  -----------------------
 * xneuzi05  Neužil Antonín  ------------------------
 * xsabel01  Sabela David  --------------------------
 * xkrbec02  Krbec Jakub  ---------------------------
 * xmrkva00  Mrkva Marek  ---------------------------
 * --------------------------------------------------
 */

#include "ial.h"
#include "mystring.h"
   
/*void bLast(string *search, int *last)
{					// pomocna funkce find
  int ahoj = 0;
  for (int i = 0; i < 256; i++)
  {
    last[i] = -1;
  }
  
  for (int i = 0; i < strlen(search->data); i++)
  {
    ahoj = search->data[i];
    last[ahoj] = i;
  }
}  

int find(string *s, string *search)
{					// Boyer-Mooruv alg na hledani podretezce
  int last[256];
  bLast(search, &last[0]);
  int k = 0;
  int n = strlen(s->data);
  int m = strlen(search->data);
  int i = m-1;
  int j = i;
  if (i > (n - 1))
  {
    return -1;
  }
  do {
    if (search->data[j] == s->data[i])
    {
	if (j == 0)
	  return i + 1;
	else
	{
	  i--;
	  j--;
	}
    }
    else
    {
	k = s->data[i];
	k = last[k];
	if (j < (k + 1))
	  i = i + m - j;
	else
	  i = i + m - (k + 1);
	j = m - 1;
    }
  } while(i < n);
  return -1;
}

char *sort(string *s)
{					// shell sort
  int i, j, step, tmp, n;
  n = strlen(s->data);
  char *sortstr = NULL;
  if ((sortstr = (char *) malloc((sizeof(char))*(n+1))) == NULL)
    return NULL;
  strcpy(sortstr, s->data);
  step = n/2;
  while (step > 0)
  {
    for (i = step; i < n; i++)
    {
      j = i;
      tmp = sortstr[i];
      while (j >= step && ((int)sortstr[j-step]) > tmp)
      {
	sortstr[j] = sortstr[j-step];
	j -= step;
      }
      sortstr[j] = tmp;
    }
    step /= 2;
  }
  return sortstr;
}
*/

struct htab_t *htab_init(int size){ //lokalni tabulka
	struct htab_t *t;
	
 if((t = (struct htab_t *) malloc(sizeof(struct htab_t) + (sizeof(struct htab_listitem)*size)))==NULL)// alokace tabulky a alokoce poctu ptr
   return NULL;
 for(int i=0; size==i;i++){ // vynulovani ptr
	 t->ptr[i]=NULL;
 }
 t->htable_size = size;
 return t;// vraci odkaz na tabulku
}

struct htab_global *htab_initg(int size){
	struct htab_global *t;
	
 if((t = (struct htab_global *) malloc(sizeof(struct htab_global) + (sizeof(struct htab_listglobal)*size)))==NULL)// alokace tabulky a alokoce poctu ptr
   return NULL;
 for(int i=0; size==i;i++){ // vynulovani ptr
	 t->ptrg[i]=NULL;
 }
 t->htable_global = size;
 return t;// vraci odkaz na tabulku
}



struct htab_listitem * htab_lookup(struct htab_t *t, const char *key){
	struct htab_listitem *seznam;

	unsigned int pozice=hash_function(key,t->htable_size); // ziskani ktere seznamu bude zapisovane(ktere ptr)
	seznam=t->ptr[pozice];

		while(seznam!=NULL){// projeti celeho seznamu
		if(strcmp(key,seznam->key)==0) //hledani schodz kli4u
			error(3);
		else 
			seznam=seznam->next; 
	}
	
	if((seznam= (struct htab_listitem *) malloc(sizeof(struct htab_listitem)))==NULL)// pokud neni chyba vztvoři se novy prvek
	error(99);
	seznam->key=(char *) malloc(sizeof(char)*(strlen(key)+1));// nevime jak je velke slovo musime pro něho takzy alokovat misto
	strcpy(seznam->key,key); // nahrani udaju
  // free(key);// uvolněi globalniho stringu
  // key=NULL; // nahrani na něho nulu
			seznam->typ=0; 
			
			seznam->next=t->ptr[pozice];
			
			t->ptr[pozice]=seznam;
			return seznam;
}




struct htab_listglobal * htab_lookupg(struct htab_global *t, const char *key){
	struct htab_listglobal *seznam;
	struct htab_t *ktera;
	unsigned int pozice=hash_function(key,t->htable_global); // ziskani ktere seznamu bude zapisovane(ktere ptr)
	seznam=t->ptrg[pozice];

		while(seznam!=NULL){// projeti celeho seznamu
		if(strcmp(key,seznam->keyg)==0) //hledani schodz kli4u
			error(3);
		else 
			seznam=seznam->nextg; 
	}
	
	if((seznam= (struct htab_listglobal *) malloc(sizeof(struct htab_listglobal)))==NULL)// pokud neni chyba vztvoři se novy prvek
	error(99);
	seznam->keyg=(char *) malloc(sizeof(char)*(strlen(key)+1));// nevime jak je velke slovo musime pro něho takzy alokovat misto
	strcpy(seznam->keyg,key); // nahrani udaju
  // free(key);// uvolněi globalniho stringu
  // key=NULL; // nahrani na něho nulu
			seznam->typg=0; 
			
			seznam->nextg=t->ptrg[pozice];
			t->ptrg[pozice]=seznam;
			
			ktera=htab_init(16381);
			seznam->ktera=ktera;
			return seznam;
}

void htab_typ(struct htab_listitem *seznam,int typ){
  if(seznam==NULL)   //ověřuji jestli takovy seznam ekzistuje
  error(99);
  else
  {
    if(seznam->typ==0)     //ovři jestli nahodou nesaham na nějaky prvek ktery u bys zapsany a ma čislo
    {
          seznam->typ=typ;
    }
    else error(99);
  }
}

void htab_typg(struct htab_listglobal *seznam,int typ){
  if(seznam==NULL)   //ověřuji jestli takovy seznam ekzistuje
  error(99);
  else
  {
    if(seznam->typg==0)     //ovři jestli nahodou nesaham na nějaky prvek ktery u bys zapsany a ma čislo
    {
          seznam->typg=typ;
    }
    else error(99);
  }
}


void htab_clear(struct htab_t *t){
	struct htab_listitem *seznam, *pomocna;
	
	 for(unsigned int pocet=0;pocet<t->htable_size;pocet++){ // projeti všech seznamu v tabulce
			seznam=t->ptr[pocet]; // natčeni prvniho prvku
		while(seznam!=NULL){ // projeti celeho seznamu
			pomocna=seznam->next; // zapamotovani pristiho
			free(seznam->key);// uvolneni pro slovo
			free(seznam);//uvolni aktualniho seznamu
			seznam=pomocna;//nahrani pristiho seznamu
		}
		t->ptr[pocet]=NULL;// vynulovani ptr
	}
}

/*void free_kod(tList *L)
struct TreAdres *seznam,*pomocna;
		seznam=L->First; 			// natčeni prvniho prvku
		while(seznam!=NULL){ 	// projeti celeho seznamu
			pomocna=seznam->ptr; // zapamotovani pristiho
			free(seznam);			//uvolni aktualniho seznamu
			seznam=pomocna;		//nahrani pristiho seznamu
		}
	L->Act=NULL; 					 //aby nezustali odkazy v aktivnim a prvnim
   L->First=NULL;
                  
}*/

void htab_clearg(struct htab_global *t){
struct htab_listglobal *seznam, *pomocna;
//tList kod;
struct htab_t *tt;
//struct TreAdres kod;
	 for(unsigned int pocet=0;pocet<t->htable_global;pocet++){ // projeti všech seznamu v tabulce
			seznam=t->ptrg[pocet]; // natčeni prvniho prvku
		while(seznam!=NULL){
			tt=seznam->ktera;
			htab_free(tt);
			//kod=seznam->adres;
			//free_kod(kod);
			pomocna=seznam->nextg; // zapamotovani pristiho
			free(seznam->keyg);// uvolneni pro slovo
			free(seznam);//uvolni aktualniho seznamu
			seznam=pomocna;//nahrani pristiho seznamu
		}
		t->ptrg[pocet]=NULL;// vynulovani ptr
	}	
}

unsigned int hash_function(const char *str, unsigned htab_size) { 
	unsigned int h=0; 
	const unsigned char *p;
	 for(p=(const unsigned char*)str; *p!='\0'; p++) 
		h = 65599*h + *p; 
		return h % htab_size;
 }

void freeg(struct htab_global *t){
	
	 htab_clearg(t); // uvolneni všech seznamu
	 free(t); // uvolneni cele tabul
	
}
void htab_free(struct htab_t *t){
	
	 htab_clear(t); // uvolneni všech seznamu
	 free(t); // uvolneni cele tabulky
	 
}

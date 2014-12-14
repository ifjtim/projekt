#ifndef interpret_H
#define interpret_H

void jede();

typedef enum {
secti, odecti, vynasob, vydel, porovnej_mensi, porovnej_vetsi,porovnej_nerovnase,porovnej_rovna,porovnej_mensirovnase,
porovnej_vetsirovnase,  prirad, cti, zapis, skok_if,skok_else,konec_while,skok_funkce,sortni,leig,fid,copy1,copy2,nici
} operat_type;


 struct ewh {
	struct TreAdres *spetna;
        //int data;
        struct ewh *lptr;
        struct ewh *rptr;
};

typedef struct {
	struct ewh *Last;
    struct ewh *First;
} vrat;

struct iwh {
	struct TreAdres *spetna;
        //int data;
        struct iwh *lptr;
        struct iwh *rptr;
};

typedef struct {
    struct iwh *First;
    struct iwh *Last;
} vrati;

vrat *fuj;

void initListi (vrati *L);
vrat *initListe (vrat *L);
void pushvrat(vrat *L,struct TreAdres *new);
struct TreAdres *pope(vrat *L);
void pushvrati(vrati *L,struct TreAdres *new);
struct TreAdres *popi(vrati *L);

struct htab_listitem *prediktiv(struct htab_listitem *t);
#endif
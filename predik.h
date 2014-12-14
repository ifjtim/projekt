typedef struct tListOpItem {

        int data;
        struct tListOpItem *lptr;
        struct tListOpItem *rptr;
} *tListOpItem;



typedef struct {
    tListOpItem First;
    tListOpItem Act;
    tListOpItem Last;
} tListOp;

typedef struct tListVarItem {
	struct htab_listitem *listItem;
        //int data;
        struct tListVarItem *lptr;
        struct tListVarItem *rptr;
} *tListVarItem;

typedef struct {
    tListVarItem First;
    tListVarItem Act;
    tListVarItem Last;
} tListVar;

void initListp (tListOp *L);
void disposeListp (tListOp *L);
void pushOp(tListOp *L, int OperType);
int popOp(tListOp *L);
bool isEmptyp (tListOp *L);

void initList (tListVar *L);
void disposeList (tListVar *L);
void pushVar(tListVar *L,struct htab_listitem *new);
struct htab_listitem *pop(tListVar *L);
bool isEmpty (tListVar *L);
void redukuj ();

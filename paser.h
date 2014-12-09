#ifndef paser_H
#define paser_H


int neww; //urcuje jestli nasist novy tokone nebo ne

 //vysledek intu kdyz je zapsan primo
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
void  prediktiv();
int proverfukci();
struct htab_listitem * zapisstring();
struct htab_listitem * zapisint();
struct htab_listitem * zapisreal();
struct htab_listitem * zapisboll();

#endif
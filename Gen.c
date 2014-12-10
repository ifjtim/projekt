#include<stdio.h>
#include "ial.h"


int pluss(struct TreAdres *L)
{
    int pocitadlo;
    if(L->operand1.typ == 1 && L->operand2.typ == 1)/* nadefiunovat*/
            {
                if(L->indetifikator.typ == 1)
                            L->indetifikator.hodnota.inger = L->operand1.hodnota.inger+L->operand2.hodnota.inger;
                else L->indetifikator.hodnota.dvouger=L->operand1.hodnota.inger+L->operand2.hodnota.inger;
					}
    else if(L->operand1.typ == 1 && L->operand2.typ == 2)
					        L->indetifikator.hodnota.dvouger=L->operand1.hodnota.inger+L->operand2.hodnota.dvouger;

    else if(L->operand1.typ == 2 && L->operand2.typ == 1)
					        L->indetifikator.hodnota.dvouger=L->operand1.hodnota.dvouger+L->operand2.hodnota.inger;

    else if(L->operand1.typ == 2 && L->operand2.typ == 2)
					        L->indetifikator.hodnota.dvouger=L->operand1.hodnota.dvouger+L->operand2.hodnota.dvouger;
    else if(L->operand1.typ == 3)
					{
					strPlusStr( &L->operand1,&L->operand2);


					}
        else return error(9); /* error*/
				/* chybí 3*/
}
int minuss(struct TreAdres* L)
{

    if(L->operand1.typ == 1 && L->operand2.typ == 1)
					{
					if(L->indetifikator.typ == 1)
                            L->indetifikator.hodnota.inger=L->operand1.hodnota.inger-L->operand2.hodnota.inger;

					else L->indetifikator.hodnota.dvouger=L->operand1.hodnota.inger-L->operand2.hodnota.inger;
					}

    else if(L->operand1.typ == 1 && L->operand2.typ == 2)
                            L->indetifikator.hodnota.dvouger=L->operand1.hodnota.inger-L->operand2.hodnota.dvouger;

    else if(L->operand1.typ == 2 && L->operand2.typ == 1)
                            L->indetifikator.hodnota.dvouger=L->operand1.hodnota.dvouger-L->operand2.hodnota.inger;

    else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator.hodnota.dvouger=L->operand1.hodnota.dvouger-L->operand2.hodnota.dvouger;

        else return error(9); /* error*/

}
int nasobb(struct TreAdres* L)
{
    if(L->operand1.typ == 1 && L->operand2.typ == 1)
					{
					if(L->indetifikator.typ == 1)
                            L->indetifikator.hodnota.inger=L->operand1.hodnota.inger*L->operand2.hodnota.inger;

					else L->indetifikator.hodnota.dvouger=L->operand1.hodnota.inger*L->operand2.hodnota.inger;
					}
    else if(L->operand1.typ == 1 && L->operand2.typ == 2)
                            L->indetifikator.hodnota.dvouger=L->operand1.hodnota.inger*L->operand2.hodnota.dvouger;

    else if(L->operand1.typ == 2 && L->operand2.typ == 1)
                            L->indetifikator.hodnota.dvouger=L->operand1.hodnota.dvouger*L->operand2.hodnota.inger;

    else if(L->operand1.typ == 2 && L->operand2.typ== 2)
                            L->indetifikator.hodnota.dvouger=L->operand1.hodnota.dvouger*L->operand2.hodnota.dvouger;

    else return error(9);/* error*/
}

int dell(struct TreAdres* L)
{
    if(L->operand1.typ == 1 && L->operand2.typ == 1)
					{
					if(L->indetifikator.typ == 1 && L->operand2.hodnota.inger!= 0)
						L->indetifikator.hodnota.inger=L->operand1.hodnota.inger/L->operand2.hodnota.inger;

					else return error(9);/*chyba*/
					}
				else return error(9);/*chyba*/
}
int vetsii(struct TreAdres* L)
{
				if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.inger>L->operand2.hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.dvouger>L->operand2.hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)
					{
					if(strcmp(&(L->operand1.hodnota.stringer),&(L->operand2.hodnota.stringer))>0)
                            L->indetifikator.hodnota.inger=1;

					else L->indetifikator.hodnota.inger=0;
					}
				else return error(9);
		}

int mensii(struct TreAdres* L)
{
				if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.inger<L->operand2.hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.dvouger<L->operand2.hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)


					if(strcmp(&(L->operand1.hodnota.stringer),&(L->operand2.hodnota.stringer))<0)
                            L->indetifikator.hodnota.inger=1;

					else L->indetifikator.hodnota.inger=0;

				else return error(9);
	}
int vetsi_rovnoo(struct TreAdres* L)
{
				if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.inger>=L->operand2.hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.dvouger>=L->operand2.hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)
					{
					if(strcmp(&(L->operand1.hodnota.stringer),&(L->operand2.hodnota.stringer))>=0)
                            L->indetifikator.hodnota.inger=1;

					else L->indetifikator.hodnota.inger=0;
					}
				else return error(9);
}

int mensi_rovnoo(struct TreAdres* L)
{				if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.inger<=L->operand2.hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.dvouger<=L->operand2.hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)
					{
					if(strcmp(&(L->operand1.hodnota.stringer),&(L->operand2.hodnota.stringer))<=0)
                            L->indetifikator.hodnota.inger=1;
					else L->indetifikator.hodnota.inger=0;
					}
				else return error(9);
}

int rovnoo(struct TreAdres* L)
{

            if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.inger==L->operand2.hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.dvouger==L->operand2.hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)
					{
					if(strcmp(&(L->operand1.hodnota.stringer),&(L->operand2.hodnota.stringer))==0)
                            L->indetifikator.hodnota.inger=1;
					else L->indetifikator.hodnota.inger=0;
					}
				else return error(9);
}

int nerovnoo(struct TreAdres* L)
{

				if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.inger!=L->operand2.hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator.hodnota.inger = (int)(L->operand1.hodnota.dvouger!=L->operand2.hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)
					{
					if(strcmp(&(L->operand1.hodnota.stringer),&(L->operand2.hodnota.stringer))!=0)
                            L->indetifikator.hodnota.inger=1;
					else L->indetifikator.hodnota.inger=0;
					}
				else return error(9);
	}
int priradd(struct TreAdres* L)
{

				if(L->operand1.typ == 1 && L->indetifikator.typ == 1)
                            L->indetifikator.hodnota.inger = L->operand1.hodnota.inger;

				else if(L->operand1.typ == 2 && L->indetifikator.typ == 2)
                            L->indetifikator.hodnota.inger = L->operand1.hodnota.dvouger;

				else if(L->operand1.typ == 3 && L->indetifikator.typ == 3)
					{
					if(strcopy(&(L->indetifikator.hodnota.stringer),&(L->operand1.hodnota.stringer))== 1)
						return error(99);
					}
				else return ;/*nejakej error*/
	}


int zapiss(struct TreAdres* L)
{
				if(L->indetifikator.typ == 1)
					printf("%d",L->indetifikator.hodnota.inger);
				else if(L->indetifikator.typ == 2)
					printf("%g",L->indetifikator.hodnota.dvouger);
				else if(L->indetifikator.typ == 3)
					printf("%s",L->indetifikator.hodnota.stringer/*.str*/);/* musime doresit*/
				else return error(9);

}


int skokk(struct TreAdres* L)
{
			L = L -> skok;
	}

int skok_kdyzz(struct TreAdres* L)
{
    if(L -> indetifikator.hodnota.inger == 1)
        L = L -> ptrr;
    else if (L -> indetifikator.hodnota.inger == 0)
        L = L -> skok;
}
int cti(struct TreAdres* L)
{

				if(scanf("%d",&(L->indetifikator.hodnota.inger))==EOF)
					return error(9);
             else  if(scanf("%lg",&(L->indetifikator.hodnota.dvouger))==EOF)
					return error(9);

}

int kon_while(struct TreAdres* L)
{
      if (L->operand1.hodnota.inger==1)
      L = L -> skok;
      else return
}

int skok_fun(struct TreAdres* L)
{
L = L -> skok;

}
void Gen (struct TreAdres *L) {



     int pocitadlo;
     char c;

        while (L->operat!=EOF)
            {


        switch (L->operat)
        {

		case secti:   /* int, real, 3, boolean  (id : typ ;)*/
                                pluss(&L);
			break;
		case odecti :
                                minuss(&L);

			break;
		case vynasob:
                                nasobb(&L);
			break;
		case vydel:
                                dell(&L);
			break;
		case porovnej_vetsi:             vetsii(&L);

			break;
		case porovnej_mensi:             mensii(&L);

			break;
		case porovnej_vetsi_rovnase:       vetsi_rovnoo(&L);
			break;
		case porovnej_mensi_rovnase:       mensi_rovnoo(&L);

			break;
        case porovnej_rovna:             rovnoo(&L);

			break;
        case porovnej_nerovnase:           nerovnoo(&L);

			break;
        case prirad:            priradd(&L);

			break;
        case cti:         cti_cisloo(&L);

			break;
        case zapis:             zapiss(&L);

			break;
        case skok_else:              skokk(&L);

			break;
        case skok_if:         skok_kdyzz(&L);

			break;
         case konec_while:         kon_while(&L);
            break;
         case skok_funkce:         skok_fun(&L);
            break;
		default:
			GlobalErr ("Internal error: Invalid instruction\n");

	}
	L = L -> ptrr;



    }
   return 0;
	}


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
        else return 9; /* error*/
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

        else return 9; /* error*/

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

    else return;/* error*/
}

int dell(struct TreAdres* L)
{
    if(L->operand1.typ == 1 && L->operand2.typ == 1)
					{
					if(L->indetifikator.typ == 1 && L->operand2.hodnota.inger!= 0)
						L->indetifikator.hodnota.inger=L->operand1.hodnota.inger/L->operand2.hodnota.inger;

					else return 9;/*chyba*/
					}
				else return 9;/*chyba*/
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
				else return 9;
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

				else return 9;
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
				else return 9;
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
				else return 9;
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
				else return 9;
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
				else return 9;
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
						return 99;
					}
				else return ;/*nejakej error*/
	}
int cti_radekk(struct TreAdres* L)
				{
				    char c;
				    c=getchar();
				while(c != '\n' && c != EOF)
					{
					c=getchar();
					}
				}

int zapiss(struct TreAdres* L)
{
				if(L->indetifikator.typ == 1)
					printf("%d",L->indetifikator.hodnota.inger);
				else if(L->indetifikator.typ == 2)
					printf("%g",L->indetifikator.hodnota.dvouger);
				else if(L->indetifikator.typ == 3)
					printf("%s",L->indetifikator.hodnota.stringer/*.str*/);/* musime doresit*/
				else return 9;

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
int cti_cisloo(struct TreAdres* L)
{

				if(scanf("%d",&(L->indetifikator.hodnota.inger))==EOF)
					return 9;

}
int cti_dbb(struct TreAdres* L)
{

				if(scanf("%lg",&(L->indetifikator.hodnota.dvouger))==EOF)
					return 9;


			char c;
				c=getchar();
				while(c != '\n' && c != EOF)
					{
					if(strAddChar(&(L->indetifikator.hodnota.stringer),c)==1)
						return 99;
					c=getchar();
					}
}



void Gen (struct TreAdres L) {



     int pocitadlo;
     char c;

        while (L.operat!=EOF)
            {


        switch (L.operat)
        {

		case plus:   /* int, real, 3, boolean  (id : typ ;)*/
                                pluss(&L);
			break;
		case minus :
                                minuss(&L);

			break;
		case nasob:
                                nasobb(&L);
			break;
		case del:
                                dell(&L);
			break;
		case vetsi:             vetsii(&L);

			break;
		case mensi:             mensii(&L);

			break;
		case vetsi_rovno:       vetsi_rovnoo(&L);
			break;
		case mensi_rovno:       mensi_rovnoo(&L);

			break;
        case rovno:             rovnoo(&L);

			break;
        case nerovno:           nerovnoo(&L);

			break;
        case prirad:            priradd(&L);

			break;
        case cti_cislo:         cti_cisloo(&L);

			break;
        case cti_radek:         cti_radekk(&L);

			break;
        case cti_db:            cti_dbb(&L);

			break;
        case zapis:             zapiss(&L);

			break;
        case skok:              skokk(&L);

			break;
        case skok_kdyz:         skok_kdyzz(&L);

			break;

		default:
			GlobalErr ("Internal error: Invalid instruction\n");

	}
	L = L -> ptrr;



    }
   return 0;
	}



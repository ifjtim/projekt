#include<stdio.h>
#include "ial.h"



void plus(struct TreAdres* L)
{
    if(L->operand1.typ == 1 && L->operand2.typ == 1)/* nadefiunovat*/
            {
                if(L->indetifikator.typ==1)
                            L->indetifikator.hodnota.inger = L->operand1.hodnota.inger+L->operand2.hodnota.inger;
                else L->indetifikator->hodnota.dvouger=L->operand1->hodnota.inger+L->operand2->hodnota.inger;
					}
    else if(L->opernad1.typ == 1 && L->operand2.typ == 2)
					        L->indetifikator->hodnota.dvouger=L->operand1->hodnota.inger+L->operand2->hodnota.dvouger;

    else if(L->operand1.typ == 2 && L->operand2.typ == 1)
					        L->indetifikator->hodnota.dvouger=L->operand1->hodnota.dvouger+L->operand2->hodnota.inger;

    else if(L->operand1.typ == 2 && L->operand2.typ == 2)
					        L->indetifikator->hodnota.dvouger=L->operand1->hodnota.dvouger+L->operand2->hodnota.dvouger;
    else if(L->operand1.typ == 3)
					{
					if(strCopy3(&(L->indetifikator->hodnota.shodnota),&(L->operand1->hodnota.shodnota))==1)
						return 99;
					for(pocitadlo=0;pocitadlo < L->operand2->hodnota.shodnota.length;pocitadlo++)
						{
						if(strAddChar(&(L->indetifikator->hodnota.stringer),L->operand2->hodnota.stringer.str[pocitadlo])==1)
							return 99;
						}
					}
        else return 9; /* error*/
				/* chybí 3*/
}
void minus(struct TreAdres* L)
{

    if(L->operand1.typ == 1 && L->operand2.typ == 1)
					{
					if(L->indetifikator.typ == 1)
                            L->indetifikator->hodnota.inger=L->operand1->hodnota.inger-L->operand2->hodnota.inger;

					else L->indetifikator->hodnota.dvouger=L->operand1->hodnota.inger-L->operand2->hodnota.inger;
					}

    else if(L->operand1.typ == 1 && L->operand2.typ == 2)
                            L->indetifikator->hodnota.dvouger=L->operand1->hodnota.inger-L->operand2->hodnota.dvouger;

    else if(L->operand1.typ == 2 && L->operand2.typ == 1)
                            L->indetifikator->hodnota.dvouger=L->operand1->hodnota.dvouger-L->operand2->hodnota.inger;

    else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator->hodnota.dvouger=L->oprand1->hodnota.dvouger-L->operand2->hodnota.dvouger;

        else return 9; /* error*/

}
void nasob(struct TreAdres* L)
{
    if(L->operand1.typ == 1 && L->operand2.typ == 1)
					{
					if(L->indetifikator.typ == 1)
                            L->indetifikator->hodnota.inger=L->operand1->hodnota.inger*L->opernad2->hodnota.inger;

					else L->indetifikator->hodnota.dvouger=L->operand1->hodnota.inger*L->opernad2->hodnota.inger;
					}
    else if(L->operand1.typ == 1 && L->operand2.typ == 2)
                            L->indetifikator->hodnota.dvouger=L->operand1->hodnota.inger*L->operand2->hodnota.dvouger;

    else if(L->operand1.typ == 2 && L->operand2.typ == 1)
                            L->indetifikator->hodnota.dvouger=L->operand1->hodnota.dvouger*L->operand2->hodnota.inger;

    else if(L->operand1.typ == 2 && L->operand2.typ== 2)
                            L->indetifikator->hodnota.dvouger=L->operand1->hodnota.dvouger*L->operand2->hodnota.dvouger;

    else return;/* error*/
}

void del(struct TreAdres* L)
{
    if(L->operand1.typ == 1 && L->operand2.typ == 1)
					{
					if(L->indetifikator.typ == 1 && L->operand2->hodnota.inger!= 0)
						L->indetifikator->hodnota.inger=L->operand1->hodnota.inger/L->operand2->hodnota.inger;

					else return 9;/*chyba*/
					}
				else return 9;/*chyba*/
}
void vetsi(struct TreAdres* L)
{
				if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator->hodnota.inger = (int)(instr->operand1->hodnota.inger>instr->operand2->hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator->hodnota.inger = (int)(instr->operand1->hodnota.dvouger>L->operand2->hodnota.dvouger);

				else if(L->operand1.typ == 3 && instr->operand2.typ == 3)
					{
					if(strCmp3(&(instr->operand1->hodnota.stringer),&(instr->operand2->hodnota.stringer))>0)
                            L->indetifikator->hodnota.inger=1;

					else L->indetifikator->hodnota.inger=0;
					}
				else return 9;
		}

void mensi(struct TreAdres* L)
{
				if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator->hodnota.inger = (int)(L->operand1->hodnota.inger<instr->operand2->hodnota.inger);

				else if(L->operad1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator->hodnota.inger = (int)(L->operand1->hodnota.dvouger<instr->operand2->hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)

					{
					if(strCmp3(&(L->operand1->hodnota.stringer),&(instr->operand2->hodnota.stringer))<0)
                            L->indetifikator->hodnota.inger=1;

					else L->indetifikator->hodnota.inger=0;
					}
				else return 9;
	}
void vetsi_rovno(struct TreAdres* L)
{
				if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator->hodnota.inger = (int)(L->operand1->hodnota.inger>=L->operand2->hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator->hodnota.inger = (int)(L->operand1->hodnota.dvouger>=L->operand2->hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)
					{
					if(strCmp3(&(L->operand1->hodnota.stringer),&(L->operand2->hodnota.stringer))>=0)
                            L->indetifikator->hodnota.inger=1;

					else L->indetifikator->hodnota.inger=0;
					}
				else return 9;
}

void mensi_rovno(struct TreAdres* L)
{				if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator->hodnota.inger = (int)(L->operand1->hodnota.inger<=L->operand2->hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator->hodnota.inger = (int)(L->operand1->hodnota.dvouger<=L->operand2->hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)
					{
					if(strCmp3(&(L->operand1->hodnota.stringer),&(L->operand2->hodnota.stringer))<=0)
                            L->indetifikator->hodnota.inger=1;
					else L->indetifikator->hodnota.inger=0;
					}
				else return 9;
}

void rovno(struct TreAdres* L)
{

            if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator->hodnota.inger = (int)(L->operand1->hodnota.inger==L->operand2->hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator->hodnota.inger = (int)(L->operand1->hodnota.dvouger==L->operand2->hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)
					{
					if(strCmp3(&(L->operand1->hodnota.stringer),&(L->operand2->hodnota.stringer))==0)
                            L->indetifikator->hodnota.inger=1;
					else L->indetifikator->hodnota.inger=0;
					}
				else return 9;
}

void nerovno(struct TreAdres* L)
{

				if(L->operand1.typ == 1 && L->operand2.typ == 1)
                            L->indetifikator->hodnota.inger = (int)(L->operand1->hodnota.inger!=L->operand2->hodnota.inger);

				else if(L->operand1.typ == 2 && L->operand2.typ == 2)
                            L->indetifikator->hodnota.inger = (int)(L->operand1->hodnota.dvouger!=L->operand2->hodnota.dvouger);

				else if(L->operand1.typ == 3 && L->operand2.typ == 3)
					{
					if(strCmp3(&(L->operand1->hodnota.stringer),&(L->operand2->hodnota.stringer))!=0)
                            L->indetifikator->hodnota.inger=1;
					else L->indetifikator->hodnota.inger=0;
					}
				else return 9;
	}
void prirad(struct TreAdres* L)
{

				if(L->operand1.typ == 1 && L->indetifikator.typ == 1)
                            L->indetifikator->hodnota.inger = L->operand1->hodnota.inger;

				else if(L->operand1.typ == 2 && L->indetifikator.typ == 2)
                            L->indetifikator->hodnota.inger = L->operand1->hodnota.dvouger;

				else if(L->operand1.typ == 3 && L->indetifikator.typ == 3)
					{
					if(strCopy3(&(L->indetifikator->hodnota.stringer),&(L->operand1->hodnota.stringer))== 1)
						return 99;
					}
				else return INTERPRET_ERR;
	}
void cti_radek(struct TreAdres* L)
				{c=getchar();
				while(c != '\n' && c != EOF)
					{
					c=getchar();
					}
				}

void zapis(struct TreAdres* L)
{
				if(L->indetifikator.typ == 1)
					printf("%d",L->indetifikator->hodnota.inger);
				else if(L->indetifikator.typ == 2)
					printf("%g",L->indetifikator->hodnota.dvouger);
				else if(L->indetifikator.typ == 3)
					printf("%s",L->indetifikator->hodnota.stringer.str);
				else return 9;

}


void skok(struct TreAdres* L)
{
				listGoto(loi,instr->addr3);
	}

void skok_kdyz(struct TreAdres* L)
{

				if(L->operand1->hodnota.inger)
					listGoto(loi,instr->addr3);    /**************************LISTGOTO je funkide na skok nwm jak to udelat ***********/
	}
                if(L->operand1->typ == 3)
					{
					if(strCopy3(&(L->indetifikator->hodnota.shodnota),&(L->operand1->hodnota.shodnota))==1)
						return 99;
					for(pocitadlo=0;pocitadlo < L->operand2->hodnota.shodnota.length;pocitadlo++)
						{
						if(strAddChar(&(L->indetifikator->hodnota.shodnota),L->operand2->hodnota.shodnota.str[pocitadlo])==1)
							return 99;
						}
					}

void cti_cislo(struct TreAdres* L)
{

				if(scanf("%d",&(L->indetifikator->hodnota.inger))==EOF)
					return 9;

}
void cti_db(struct TreAdres* L)
{

				if(scanf("%lg",&(L->indetifikator->hodnota.dvouger))==EOF)
					return 9;
			break;

			case I_READS:
				c=getchar();
				while(c != '\n' && c != EOF)
					{
					if(strAddChar(&(L->indetifikator->hodnota.stringer),c)==1)
						return 99;
					c=getchar();
					}
}



int Gen (struct TreAdres L) {
    L -> Act = L-> First;
    L = L -> Act;
     int pocitadlo;
     char c;

        while (L->operat!=EOF)
            {


        switch (L->operat)
        {

		case plus:   /* int, real, 3, boolean  (id : typ ;)*/
                                plus(L);
			break;
		case minus :
                                minus(L);

			break;
		case nasob:
                                nasob(L);
			break;
		case del:
                                del(L);
			break;
		case vetsi:             vetsi(L);

			break;
		case mensi:             mensi(L);

			break;
		case vetsi_rovno:       vetsi_rovno(L);
			break;
		case mensi_rovno:       mensi_rovno(L);

			break;
        case rovno:             rovno(L);

			break;
        case nerovno:           nerovno(L);

			break;
        case prirad:            prirad(L);

			break;
        case cti_cislo:         cti_cislo(L);

			break;
        case cti_radek:         cti_radek(L);

			break;
        case cti_db:            cti_db(L);

			break;
        case zapis:             zapis(L);

			break;
        case skok:              skok(L);

			break;
        case skok_kdyz:         skok_kdyz(L);

			break;

		default:
			GlobalErr ("Internal error: Invalid instruction\n");

	}
	if (L -> Act != NULL)
	L -> act = L-> Act -> ptr;

	if (L->Act == NULL )
    {
      return 9;
    }
    else return &(L);
	}
  return 0;
}

int main(){
Gen ();
}

/* ------------------Název-projektu------------------
 * Implementace interptetu imperativního jazyka IFJ14
 * ----------------------Autoøi----------------------
 * xkonde03  Konderla Tomasz  -----------------------
 * xneuzi05  Neu¾il Antonín  ------------------------
 * xsabel01  Sabela David  --------------------------
 * xkrbec02  Krbec Jakub  ---------------------------
 * xmrkva00  Mrkva Marek  ---------------------------
 * --------------------------------------------------
 */
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdbool.h>
#include "mystring.h"
#include "ial.h"
#include "interpret.h"
#include "paser.h"
#include "lexana.h"
#include "predik.h"

 tListVar var;
	tListOp opp;

struct htab_listitem *prediktiv(struct htab_listitem *t)
{

	int nanic;
  struct htab_listitem *tmp,*vysledek;
  bool lZavorka = false, pZavorka = false;
  initList(&var);
  initListp(&opp);


	new_token();
	if(token==K_end || token==strednik)
	{
		neww=2;
		return t;
	}

	else
	{
		 pushVar(&var, t);
		 pushOp(&opp,token);
      
	new_token();
	
		while (token != K_end && token != K_then && token != K_do && token != strednik)
		{
			switch(token)
			{
				case id:
				{
				//printf("%s",str_g.data);
				if((tmp=over(str_g.data,lokal,&nanic))==NULL)
					{
						if((tmp=gover(str_g.data,&nanic))==NULL) error(3);
					}
					
					strFree(&str_g);
					strInit(&str_g);
					pushVar(&var, tmp);
					break;
				}
				case cislo_integer:
				{
					
						tmp = zapisint();
					pushVar(&var, tmp);
					break;
				}
				case hodnota_string:
				{
				tmp = zapisstring();
					pushVar(&var, tmp);
					break;
				}
				case cislo_real:
				{
				tmp = zapisreal();
					pushVar(&var, tmp);
					break;
				}
				case zavorkaP:
				{
				pushOp(&opp, token);
					lZavorka =true;
					break;
				}
				case K_true:
				{
				tmp = zapisboll();
					pushVar(&var, tmp);
					break;
				}
				case K_false:
				{
				tmp = zapisboll();
					pushVar(&var, tmp);
					break;
				}
				default:
				{
					//printf("s");
				error(2);
				}
			}
			new_token();
        

			if (token == K_end || token == K_then || token == K_do || token == strednik)
			{
				
				break;
			}

			switch (token)
			{
				case plus:
				{
				while ((opp.Last->data == plus || opp.Last->data == minus || opp.Last->data == krat || opp.Last->data == deleno) && isEmptyp(&opp) == false)
				{
					
					redukuj();
				}
				pushOp(&opp,token);
				break;
				}
				case minus:
				{
				while ((opp.Last->data == plus || opp.Last->data == minus || opp.Last->data == krat || opp.Last->data == deleno) && isEmptyp(&opp) == false)
				{
					redukuj();
				}
				pushOp(&opp,token);
				break;
				}
				case krat:
				{
				while ((opp.Last->data == krat || opp.Last->data == deleno) && isEmptyp(&opp) == false)
				{
					redukuj();
				}
				pushOp(&opp,token);
				break;
				}
				case deleno:
				{
					while ((opp.Last->data == krat || opp.Last->data == deleno) && isEmptyp(&opp) == false)
				{
					redukuj();
				}
				pushOp(&opp,token);
				break;
				}
				case mensi:
				{
				while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
				{
					redukuj();
				}
				pushOp(&opp,token);
				break;
				}
				case vetsi:
				{
				while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
				{
					redukuj();
				}
				pushOp(&opp,token);
				break;
				}
				case mensi_rovnase:
				{
				while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
				{
					redukuj();
				}
				pushOp(&opp,token);
				break;
				}
				case vetsi_rovnase:
				{
				while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
				{
					redukuj();
				}
				pushOp(&opp,token);
				break;
				}
				case nerovna:
				{
				while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
				{
					redukuj();
				}
				pushOp(&opp,token);
				break;
				}
				case rovnase:
				{
				while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
				{
					redukuj();
				}
				pushOp(&opp,token);
				break;
				}
			default:
			{
			error(2);
			}

			}
			new_token();
		}
	}
	printf("ss");
	vysledek=(&var);
	neww=2;
	return vysledek;
}
 /* pushVar(&var, t);

  new_token();
  pushOp(&opp,rovnase);
  opperator = poppOp(&opp);
	printf("%d",opperator);
  new_token();
 t=zapisint();
   pushVar(&var, t);
	tmp= popp(&var);
 printf(" %s ",tmp->key);
	tmp= popp(&var);
 printf(" %s ",tmp->key);
	}*/
  /*
  //potreba pocatecni init !!
  while (token != K_end && token != K_then && token != K_do && token != strednik)
  {
    if (!pZavorka)
	{
	  switch(token)
	  {
	    case id:
		{
		  if((tmp=over(str_g.data,lokal))==NULL)
          {
		    (tmp=gover(str_g.data))==NULL)error(3);
		  }
          pushVar(&var, tmp);
          break;
		}
		case cislo_integer:
		{
		  tmp = zapisint();
          pushVar(&var, tmp);
          break;
		}
		case hodnota_string:
		{
		  tmp = zapisstring();
          pushVar(&var, tmp);
          break;
		}
		case cislo_real:
		{
		  tmp = zapisreal();
          pushVar(&var, tmp);
          break;
		}
		case zavorkaP:
		{
		  pushOp(&opp, token);
          lZavorka =true;
          break;
		}
		case K_true:
		{
		  tmp = zapisboll();
          pushVar(&var, tmp);
          break;
		}
		case K_fasle:
		{
		  tmp = zapisboll();
          pushVar(&var, tmp);
          break;
		}
	  }
	  new_token();
	}
	pZavorka == false;
	if (!lZavorka)
	{
	  if (token == K_end && token == K_then && token == K_do && token == strednik)
	  {
	    break;
	  }
	  switch (token)
	  {
	    case plus:
		{
		  while ((opp.Last->data == plus || opp.Last->data == minus || opp.Last->data == krat || opp.Last->data == deleno) && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  pushOp(plus);
		  break;
		}
		case minus:
		{
		  while ((opp.Last->data == plus || opp.Last->data == minus || opp.Last->data == krat || opp.Last->data == deleno) && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  pushOp(minus);
		  break;
		}
		case krat:
		{
		  while ((opp.Last->data == krat || opp.Last->data == deleno) && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  pushOp(krat);
		  break;
		}
		case deleno:
		{
		   while ((opp.Last->data == krat || opp.Last->data == deleno) && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  pushOp(deleno);
		  break;
		}
		case mensi:
		{
		  while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  pushOp(mensi);
		  break;
		}
		case vetsi:
		{
		  while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  pushOp(vetsi);
		  break;
		}
		case mensi_rovnase:
		{
		  while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  pushOp(mensi_rovnase);
		  break;
		}
		case vetsi_rovnase:
		{
		  while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  pushOp(vetsi_rovnase);
		  break;
		}
		case nerovna:
		{
		  while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  pushOp(nerovna);
		  break;
		}
		case rovnase:
		{
		  while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  pushOp(rovnase);
		  break;
		}
		case zavorkaD:
		{
		  pZavorka = true;
		  while (opp.Last->data != zavorkaP && isEmptyp(&opp) == false)
		  {
		    redukuj();
		  }
		  if (isEmptyp(&opp))
		  {
		    error(2);
		  }
		  poppOp(&opp);
		}
		default:
		{
		  error(2);
		}
	  }
	  new_token();
	}
	lZavorka = false;
  }
  while (!isEmptyp(&opp))
  {
    redukuj();
  }
  if (isEmpty(&var))
  {
    error();
  }
  vysledek = poppVar(&var);
  if (!isEmpty(&var))
  {
    error(2);
  }
  disposeListp(&opp);
  disposeList(&var);
  return vysledek;*/


void redukuj ()
{					// nemela by byt * u "a" a "b" ?? nevím ?
  struct htab_listitem *a, *b,*pom;
  int opperator, typ;
  opperator = popOp(&opp);
  b = pop(&var);
  a = pop(&var);
  if (opperator != plus && opperator != minus && opperator != krat && opperator != deleno)
  {
    typ = 4;
  }
  else if (a->typ == 2 || b->typ == 2 || opperator == deleno)
  {
    typ = 2;
  }
  else if (a->typ == 3 || b->typ == 3)
  {
    typ =3;
  }
  else
  {
    typ = 1;
  }
  pom=universal(typ);
  switch (opperator)
  {
    case plus:
	{
	  if (a->typ == 4 || b->typ == 4)
	  {
	    error(4);
	  }
	  if ((a->typ == 3 && b->typ != 3) || (a->typ != 3 && b->typ == 3))
	  {
	    error(4);
	  }
	  //synAddInst(&itemFunction->Inst, INST_PLUS, pom->key, a.id->key, b.id->key, NULL);
      break;
	}
	case minus:
	{
	  if (a->typ == 4 || b->typ == 4)
	  {
	    error(4);
	  }
	  if ((a->typ == 3 && b->typ != 3) || (a->typ != 3 && b->typ == 3))
	  {
	    error(4);
	  }
	  //synAddInst(&itemFunction->Inst, INST_MINUS, pom->key, a.id->key, b.id->key, NULL);
      break;
	}
	case krat:
	{
	  if (a->typ == 4 || b->typ == 4)
	  {
	    error(4);
	  }
	  if (a->typ == 3 || b->typ == 3)
	  {
	    error(4);
	  }
	  //synAddInst(&itemFunction->Inst, INST_KRAT, pom->key, a.id->key, b.id->key, NULL);
      break;
	}
	case deleno:
	{
	  if (a->typ == 4 || b->typ == 4)
	  {
	    error(4);//kouknout
	  }
	  if (a->typ == 3 || b->typ == 3)
	  {
	    error(4);//koknout
	  }
	 // synAddInst(&itemFunction->Inst, INST_KRAT, pom->key, a.id->key, b.id->key, NULL);
      break;
	}
	case mensi:
    {
      if (a->typ != b->typ)
	  {
    	error(4);
	  }
      //synAddInst(&itemFunction->Inst, INST_mensi, pom->key, a.id->key, b.id->key, NULL);
      break;
    }
	case vetsi:
    {
      if (a->typ != b->typ)
	  {
    	error(4);
	  }
     // synAddInst(&itemFunction->Inst, INST_vetsi, pom->key, a.id->key, b.id->key, NULL);
      break;
    }
	case mensi_rovnase:
    {
      if (a->typ != b->typ)
	  {
    	error(4);
	  }
      //synAddInst(&itemFunction->Inst, INST_mensi_rovnase, pom->key, a.id->key, b.id->key, NULL);
      break;
    }
	case vetsi_rovnase:
    {
      if (a->typ != b->typ)
	  {
    	error(4);
	  }
      //synAddInst(&itemFunction->Inst, INST_vetsi_rovnase, pom->key, a.id->key, b.id->key, NULL);
      break;
    }
	case nerovna:
    {
      if (a->typ != b->typ)
	  {
    	error(4);
	  }
      //synAddInst(&itemFunction->Inst, INST_nerovna, pom->key, a.id->key, b.id->key, NULL);
      break;
    }
	case rovnase:
    {
      if (a->typ != b->typ)
	  {
    	error(4);
	  }
      //synAddInst(&itemFunction->Inst, INST_rovnase, pom->key, a.id->key, b.id->key, NULL);
      break;
    }
  }
  // ??? !!! co s timhle? !!! ??? protoze pom je zakomentovany nahore ?? !!
  		// **
  pushVar(&var,pom);	// **
  //	*** *** * * **  * * **

}

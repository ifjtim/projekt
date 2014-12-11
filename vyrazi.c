// udelej psuhgram pushvar pogram popvar emtygram emtyvar



// prediktivna analyza
struct htab_listitem prediktivna()
{
     struct htab_listitem *tmp,*vysledek;
	 tListVar var;
	 tListOp op;
     // pomocne pre zatvorky
     bool L_PAREN = false;
     bool R_PAREN = false;
     initList(&var);
     new_token();
    //potreba pocatecni init !!

     // cyklime kym nie je jeden z tychto tokenov
     // bud je to koniec priradenia, zaciatok vetvy if alebo while
     // na inom mieste sa vyraz spracovavat nemoze
     while (token != strednik && token != K_then && token != K_do && token != K_end)
     {
     	 // ak sme dostali pravu zatvorku tak tuto cast musime preskocit
     	 if (R_PAREN == false)
     	 {
     	 	// tu spracovavame literaly, ID a lavu zatvorku
            switch (token)
            {
            	case id:
            	{
            	  if((tmp=over(str_g.data,lokal))==NULL)
					  {
						 (tmp=gover(str_g.data))==NULL)error(3);
					  }


                    pushVar(, tmp);
            		break;
            	}
            	case cislo_integer:// nutno prepsat case podle enum
            	{
            	    tmp = zapisint();
                    pushVar(&var, tmp);
                    break;
            	}
            	case cislo_real:
            	{
		    tmp = zapisreal();
                    pushVar(&var, tmp);
                    break;
            	}
            	case hodnota_string:
            	{
		    tmp = zapisstring();
                    pushVar(&var, tmp);
                    break;
            	}
            /*	case K_true:
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
            	}*/
            	case zavorkaP:
            	{

            	    pushOp(&op, token);
            	    L_PAREN =true;
            	    break;
            	}
            	default:
            	   error(2);
            }
            new_token();
         }
         R_PAREN = false;

         // ak sme spracovali lavu zatvorku toto musime preskocit
         if(L_PAREN == false)
         {
            // ak sme dostali token po ktorom vieme, ze musime skoncit
            if (!(token != strednik && token != K_then && token != K_do && token != K_end))
            	break;
            // spracovavame prichadzajuce operatory a podla ich priority volame redukciu
            // pozerame sa na vrchol zasobniku
            switch (token)
            {
            	case plus: //jinak pojmenovane
            	{		// potreba doplnit nazvy isEmpty funkce pro OP
            		while (!isEmpty(&op) && (op.Last->data == plus || op.Last->data == minus || op.Last->data == krat || op.Last->data == deleno))//uprav
            			  reduc(itemFunction);

            	    pushOp(plus);
            		break;
            	}
            	case minus:
            	{
            		while (!isEmpty(&op) && (op.Last->data == plus || op.Last->data == minus || op.Last->data == krat || op.Last->data == deleno))
            			  reduc(itemFunction);
            	    pushOp(minus);
            		break;
            	}
            	case krat:
            	{
            		while (!isEmpty(&op) && (op.Last->data == krat || op.Last->data == deleno))
            			  reduc(itemFunction);
		      pushOp(krat);
            		break;
            	}
            	case deleno:
            	{
            		while (!isEmpty(&op) && (op.Last->data == krat || op.Last->data == deleno))
            			  reduc(itemFunction);
			pushOp(deleno);
            		break;
            	}
            	case rovnase:
            	{
            		while (!isEmpty(&op) && op.Last->data != zavorkaP)
            			  reduc(itemFunction);
			pushOp(rovnase);
            		break;
            	}
            	case mensi:
            	{
            		while (!isEmpty(&op) && op.Last->data != zavorkaP)
            			  reduc(itemFunction);
			pushOp(mensi);
            		break;
            	}
            	case vetsi:
            	{
            		while (!isEmpty(&op) && op.Last->data != zavorkaP)
            			  reduc(itemFunction);
			pushOp(vetsi);
            		break;
            	}
            	case mensi_rovnase:
            	{
            		while (!isEmpty(&op) && op.Last->data != zavorkaP)
            			  reduc(itemFunction);
			pushOp(mensi_rovnase);
            		break;
            	}
            	case nerovna:
            	{
            		while (!isEmpty(&op) && op.Last->data != zavorkaP)
            			  reduc(itemFunction);
			pushOp(nerovna);
            		break;
            	}
            	case vetsi_rovnase:
            	{
            		while (!isEmpty(&op) && op.Last->data != zavorkaP)
            			  reduc(itemFunction);
			pushOp(vetsi_rovnase);
            		break;
            	}
            	case zavorkaD:
            	{
            		while (!isEmpty(&op) && op.Last->data != zavorkaP)
            			  reduc(itemFunction);

            	    if (isEmpty(&op))
            	    	error();	// !!! doplnit error cisla !!!
            	    popOp(&op);
                   R_PAREN = true;
            		break;
            	}
            	default:
            	    error();
            }
            new_token();
         }
         L_PAREN = false;
      } // koniec cyklu

  // sme na konci tak redukujeme kym nie je prazdny zasobnik
  while(!isEmpty(&op))
  	   reduc(itemFunction);
  // na zasobniku premennych musi byt aspon jedna premena
  if(isEmpty(&var))
  	error();
  // vysledok analyzy
  vysledek = popVar(&var);
  // na zasobniku premennych uz nesmie byt ziadna premenna
  if(!isEmpty(&var))
  	error();
  // vraciame vysledok
  return vysledek;
}

void reduc(dataFunction *itemFunction)
{
	// POP-neme operator, aby sme vedeli ako redukovat
	int opi = popOp(&op);
    // a co mame redukovat
    // prdPop uz kotroluje ci nie je zasobik prazny a pripadne
    // ukonci program
	struct htab_listitem b = popVar(&var);
	struct htab_listitem a = popVar(&var);

	int type = tInt;
    // urcime vysledny typ pomocne premenej

    // ak je to booleovska operacia
    if (op != plus && op != minus && op != krat && op != deleno)
       type = tBool;
    // ak to bude string
	else if (a->typ == tString || b->typ == tString)
	   type = tString;		//  !!! prepsat podle enum? "tString".. !!!
	// ak to bude real
	else if (op == deleno || a->typ == 3 || b.->typ == tReal)
	   type = tReal;

    // vytvorime si ju
	/*  char c[100];
    generate(itemFunction->symbolTab, c);
    tvalue val;
    val.s = NULL;
    dataSymbol *pom;
    syntStabContAdd(itemFunction->symbolTab, c, type, false, val, &pom);
    *///udleam funkci
    // podla uskutocnujeme redukciu
    switch (op)
    {
    	case plus:
    	{
    	   if ((a->typ == tBool || b->typ == tBool) ||
    	   	   (a->typ == tString && b->typ != tString) ||
             (b->typ == tString && a->typ != tString))
    	   	  error();

           synAddInst(&itemFunction->Inst, INST_PLUS, pom->key, a.id->key, b.id->key, NULL);
           break;
    	}
    	case minus:
    	{
    	   if ((a->typ == tBool || b->typ == tBool) ||
    	   	   (a->typ == tString && b->typ != tString) ||
             (b->typ == tString && a->typ != tString))
    	   	  error();

           synAddInst(&itemFunction->Inst, INST_minus, pom->key, a.id->key, b.id->key, NULL);
           break;
    	}
    	case krat:
    	{
    	   if (a->typ == tBool || b->typ == tBool || a->typ == tString || b->typ == tString)
    	   	  error();

           synAddInst(&itemFunction->Inst, INST_MUL, pom->key, a.id->key, b.id->key, NULL);
           break;
    	}
    	case deleno:
    	{
    	   if (a->typ == tBool || b->typ == tBool || a->typ == tString || b->typ == tString)
    	   	  error();

           synAddInst(&itemFunction->Inst, INST_DIV, pom->key, a.id->key, b.id->key, NULL);
           break;
    	}
       case rovnase:
       {
           if (a->typ != b->typ)
    	   	  error();

           synAddInst(&itemFunction->Inst, INST_rovnase, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
       case mensi:
       {
           if (a->typ != b->typ)
    	   	  error();

           synAddInst(&itemFunction->Inst, INST_mensi, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
        case vetsi:
       {
           if (a->typ != b->typ)
    	   	  error();

           synAddInst(&itemFunction->Inst, INST_vetsi, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
        case mensi_rovnase:
       {
           if (a->typ != b->typ)
    	   	  error();

           synAddInst(&itemFunction->Inst, INST_mensi_rovnase, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
        case nerovna:
       {
           if (a->typ != b->typ)
    	   	  error();

           synAddInst(&itemFunction->Inst, INST_nerovna, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
        case vetsi_rovnase:
       {
           if (a->typ != b->typ)
    	   	  error();

           synAddInst(&itemFunction->Inst, INST_vetsi_rovnase, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
    }
    // ??? !!! co s timhle? !!! ???
    a.id = pom;		// **
    prdPush(pom);	// **
    //	*** *** * * **  * * **
}

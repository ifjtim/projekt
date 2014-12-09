// udelej psuhgram pushvar pogram popvar emtygram emtyvar



// prediktivna analyza
struct htab_listitem prediktivna()
{
     struct htab_listitem *tmp,*vysedek;
     // pomocne pre zatvorky 
     bool L_PAREN = false; 
     bool R_PAREN = false;   
     
    new_token();
    //potreba pocatecni init
	 
     // cyklime kym nie je jeden z tychto tokenov 
     // bud je to koniec priradenia, zaciatok vetvy if alebo while
     // na inom mieste sa vyraz spracovavat nemoze
     while (token != SEMICOLON && token != THEN && token != DO && token != END)
     {
     	 // ak sme dostali pravu zatvorku tak tuto cast musime preskocit 
     	 if (R_PAREN == false)
     	 {	
     	 	// tu spracovavame literaly, ID a lavu zatvorku
            switch (token)
            {
            	case ID:
            	{
            	  if((tmp=over(str_g.data,lokal))==NULL)
					  {
						 (tmp=gover(str_g.data))==NULL)error(3);
					  }

             	    
                   pushvar(tmp);
            		break;
            	}
            	case NUM_INT:// nutno prepsat case podle enum
            	{
            	    tmp=zapisint();
                     pushvar(tmp);
                    break;
            	}
            	case NUM_DOUBLE:
            	{
            		char b[100];
                    generate(itemFunction->symbolTab, b);
                       
                    tvalue val;
                    val.d = lexDouble;
                    dataSymbol *pom;
                    syntStabContAdd(itemFunction->symbolTab, b, tReal, true, val, &pom);       

                    a.id = pom;
                    prdPush(&prdVar, a);
                    break;
            	}
            	case QUOTE:
            	{
            		char b[100];

                    char *c;
                    c = malloc(dymString.Length + 1);

                    if (c == NULL)
                       syntFatalError(INTER_ERR, ERRORS[ERR_MSG_MALLOC]);

                    strcpy(c, GetString(&dymString));    

                    generate(itemFunction->symbolTab, b);
                     
                    tvalue val;
                    val.s = c;

                
      	            dataSymbol *pom;
                    syntStabContAdd(itemFunction->symbolTab, b, tString, true, val, &pom);       

                    a.id = pom;
                    prdPush(&prdVar, a);
                    break;
            	}
            /*	case TRUE_:
            	{
            		char b[100];
                    generate(itemFunction->symbolTab, b);
                       
                    tvalue val;
                    val.b = true;
                    dataSymbol *pom;
                    syntStabContAdd(itemFunction->symbolTab, b, tBool, true, val, &pom);       

                    a.id = pom;
                    prdPush(&prdVar, a);
                    break;
            	}
            	case FALSE_:
            	{
            		char b[100];
                    generate(itemFunction->symbolTab, b);
                       
                    tvalue val;
                    val.b = false;
                    dataSymbol *pom;
                    syntStabContAdd(itemFunction->symbolTab, b, tBool, true, val, &pom);       

                    a.id = pom;
                    prdPush(&prdVar, a);
                    break;
            	}*/
            	case L_PARENTHESES:
            	{
            		
            	    pushgarm(token);
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
            if (!(token != SEMICOLON && token != THEN && token != DO && token != END))
            	break;
            // spracovavame prichadzajuce operatory a podla ich priority volame redukciu 
            // pozerame sa na vrchol zasobniku
            switch (token)
            {
            	case PLUS: //jinak pojmenovane
            	{
            		while (!isEmpty(&prdGram) && (prdGram.last->value.i == PLUS || prdGram.last->value.i == MINUS 
            			                         || prdGram.last->value.i == MULTIPLY || prdGram.last->value.i == DIVISION))//uprav
            			  reduc(itemFunction);
            	
            	    PushGram(plus);
            		break;
            	}
            	case MINUS:
            	{
            		while (!isEmpty(&prdGram) && (prdGram.last->value.i == PLUS || prdGram.last->value.i == MINUS 
            			                         || prdGram.last->value.i == MULTIPLY || prdGram.last->value.i == DIVISION))
            			  reduc(itemFunction);
            		a.i = MINUS;
            	    prdPush(&prdGram, a);
            		break;
            	}
            	case MULTIPLY:
            	{
            		while (!isEmpty(&prdGram) && (prdGram.last->value.i == MULTIPLY || prdGram.last->value.i == DIVISION))
            			  reduc(itemFunction);
            		a.i = MULTIPLY;
            	    prdPush(&prdGram, a);
            		break;
            	}
            	case DIVISION:
            	{
            		while (!isEmpty(&prdGram) && (prdGram.last->value.i == MULTIPLY || prdGram.last->value.i == DIVISION))
            			  reduc(itemFunction);
            		a.i = DIVISION;
            	    prdPush(&prdGram, a);
            		break;
            	}
            	case EQUALS:
            	{
            		while (!isEmpty(&prdGram) && prdGram.last->value.i != L_PARENTHESES)
            			  reduc(itemFunction);
            		a.i = EQUALS;
            	    prdPush(&prdGram, a);
            		break;
            	}
            	case LESS:
            	{
            		while (!isEmpty(&prdGram) && prdGram.last->value.i != L_PARENTHESES)
            			  reduc(itemFunction);
            		a.i = LESS;
            	    prdPush(&prdGram, a);
            		break;
            	}
            	case GREATER:
            	{
            		while (!isEmpty(&prdGram) && prdGram.last->value.i != L_PARENTHESES)
            			  reduc(itemFunction);
            		a.i = GREATER;
            	    prdPush(&prdGram, a);
            		break;
            	}
            	case LESS_EQUA:
            	{
            		while (!isEmpty(&prdGram) && prdGram.last->value.i != L_PARENTHESES)
            			  reduc(itemFunction);
            		a.i = LESS_EQUA;
            	    prdPush(&prdGram, a);
            		break;
            	}
            	case NOT_EQUAL:
            	{
            		while (!isEmpty(&prdGram) && prdGram.last->value.i != L_PARENTHESES)
            			  reduc(itemFunction);
            		a.i = NOT_EQUAL;
            	    prdPush(&prdGram, a);
            		break;
            	}
            	case GREATER_EQUA:
            	{
            		while (!isEmpty(&prdGram) && prdGram.last->value.i != L_PARENTHESES)
            			  reduc(itemFunction);
            		a.i = GREATER_EQUA;
            	    prdPush(&prdGram, a);
            		break;
            	}
            	case R_PARENTHESES:
            	{
            		while (!isEmpty(&prdGram) && prdGram.last->value.i != L_PARENTHESES)
            			  reduc(itemFunction);       

            	    if (isEmpty(&prdGram))
            	    	syntFatalError(SYNT_ERR, ERRORS[ERR_MSG_PREDANAl]);
            	    pop(&prdGram);
                   R_PAREN = true;
            		break;
            	}
            	default:
            	    syntFatalError(SEM_ERR, ERRORS[ERR_MSG_TOKEN]);
            }
            get_Token();
         }
         L_PAREN = false;       
      } // koniec cyklu 
  
  // sme na konci tak redukujeme kym nie je prazdny zasobnik  
  while(!isEmpty(&prdGram))
  	   reduc(itemFunction);
  // na zasobniku premennych musi byt aspon jedna premena
  if(isEmpty(&prdVar))
  	syntFatalError(SYNT_ERR, ERRORS[ERR_MSG_PREDANAl]);
  // vysledok analyzy
  vysedek = pop(&prdVar).id;
  // na zasobniku premennych uz nesmie byt ziadna premenna
  if(!isEmpty(&prdVar))
  	syntFatalError(SYNT_ERR, ERRORS[ERR_MSG_PREDANAl]);
  // vraciame vysledok
  return ret;
}

void reduc(dataFunction *itemFunction)
{
	// POP-neme operator, aby sme vedeli ako redukovat
	int op = pop(&prdGram).i;
    // a co mame redukovat
    // prdPop uz kotroluje ci nie je zasobik prazny a pripadne
    // ukonci program 
	struct htab_listitem b = prdPop(&prdVar);
	struct htab_listitem a = prdPop(&prdVar);
	
	int type = tInt;
    // urcime vysledny typ pomocne premenej 
 
    // ak je to booleovska operacia
    if (op != PLUS && op != MINUS && op != MULTIPLY && op != DIVISION)
       type = tBool;
    // ak to bude string
	else if (a.id->varType == tString || b.id->varType == tString)
	   type = tString;
	// ak to bude real
	else if (op == DIVISION || a->type == 3 || b.id->varType == tReal)
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
    	case PLUS:
    	{  
    	   if ((a.id->varType == tBool || b.id->varType == tBool) || 
    	   	   (a.id->varType == tString && b.id->varType != tString) ||
             (b.id->varType == tString && a.id->varType != tString))
    	   	  syntFatalError(SEM_OTHERS_ERR, ERRORS[ERR_MSG_OPTYPE]);

           synAddInst(&itemFunction->Inst, INST_PLUS, pom->key, a.id->key, b.id->key, NULL);
           break;
    	}
    	case MINUS:
    	{
    	   if (a.id->varType == tBool || b.id->varType == tBool || a.id->varType == tString || b.id->varType == tString)
    	   	  syntFatalError(SEM_OTHERS_ERR, ERRORS[ERR_MSG_OPTYPE]);

           synAddInst(&itemFunction->Inst, INST_MINUS, pom->key, a.id->key, b.id->key, NULL);
           break;
    	}
    	case MULTIPLY:
    	{
    	   if (a.id->varType == tBool || b.id->varType == tBool || a.id->varType == tString || b.id->varType == tString)
    	   	  syntFatalError(SEM_OTHERS_ERR, ERRORS[ERR_MSG_OPTYPE]);

           synAddInst(&itemFunction->Inst, INST_MUL, pom->key, a.id->key, b.id->key, NULL);
           break;
    	}
    	case DIVISION:
    	{
    	   if (a.id->varType == tBool || b.id->varType == tBool || a.id->varType == tString || b.id->varType == tString)
    	   	  syntFatalError(SEM_OTHERS_ERR, ERRORS[ERR_MSG_OPTYPE]);

           synAddInst(&itemFunction->Inst, INST_DIV, pom->key, a.id->key, b.id->key, NULL);
           break;
    	} 
       case EQUALS:
       {
           if (a.id->varType != b.id->varType)
    	   	  syntFatalError(SEM_OTHERS_ERR, ERRORS[ERR_MSG_OPTYPE]);

           synAddInst(&itemFunction->Inst, INST_EQUALS, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
       case LESS:
       {
           if (a.id->varType != b.id->varType)
    	   	  syntFatalError(SEM_OTHERS_ERR, ERRORS[ERR_MSG_OPTYPE]);

           synAddInst(&itemFunction->Inst, INST_LESS, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
        case GREATER:
       {
           if (a.id->varType != b.id->varType)
    	   	  syntFatalError(SEM_OTHERS_ERR, ERRORS[ERR_MSG_OPTYPE]);

           synAddInst(&itemFunction->Inst, INST_GREATER, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
        case LESS_EQUA:
       {
           if (a.id->varType != b.id->varType)
    	   	  syntFatalError(SEM_OTHERS_ERR, ERRORS[ERR_MSG_OPTYPE]);

           synAddInst(&itemFunction->Inst, INST_LESS_EQUA, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
        case NOT_EQUAL:
       {
           if (a.id->varType != b.id->varType)
    	   	  syntFatalError(SEM_OTHERS_ERR, ERRORS[ERR_MSG_OPTYPE]);

           synAddInst(&itemFunction->Inst, INST_NOT_EQUAL, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
        case GREATER_EQUA:
       {
           if (a.id->varType != b.id->varType)
    	   	  syntFatalError(SEM_OTHERS_ERR, ERRORS[ERR_MSG_OPTYPE]);

           synAddInst(&itemFunction->Inst, INST_GREATER_EQUA, pom->key, a.id->key, b.id->key, NULL);
           break;
       }
    }
   
    a.id = pom;
    prdPush(pom); 
}
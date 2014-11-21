#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lex_ana.h"

#define INVALID_SRCFILE 1
#define VALID_SRCFILE 0
FILE* srcfile;
token_type token;
//otevirani souboru
int opensrcfile(char *filename)
{
    srcfile = fopen(filename,"r");
    if (srcfile == NULL)
    {
        printf("\nSoubor %s neexistuje \n",filename);
        return INVALID_SRCFILE;
    }
    return VALID_SRCFILE;
}
void closesrcfile (){
        fclose(srcfile);
        return;
}


//deklarace jednotlivych znaku ktery mohou prijit
character_type get_char_type(char ch) {
    if ((ch == ' ') || (ch == '\n') || (ch == EOF)) {
        return white_space;
    } else if ((ch >= '0') && (ch <='9')) {
        return cislo;
    } else if ((ch == 'e') || (ch =='E')) {
        return pismeno_e;
    } else if ((ch == '_') || ((ch >= 'A')&& (ch<='Z')) || ((ch >= 'a') && (ch <='z'))) {
        return pismeno;
    } else if (ch == ';') {
        return strednik;
    } else if (ch == '+'){
        return plus_znak;
    } else if (ch == '-') {
        return minus_znak;
    } else if (ch == '*') {
        return krat_znak;
    } else if (ch == '/') {
        return lomeno_znak;
    } else if (ch == '>') {
        return vetsi_znak;
    } else if (ch == '<') {
        return mensi_znak;
    } else if (ch == '=') {
        return rovno_znak;
    } else if (ch == '’') {
        return apostrof;
    } else if (ch == '(') {
        return ls_zavorka;
    } else if (ch == ')') {
        return ps_zavorka;
    } else if (ch == '#') {
        return escape;
    } else if (ch == '.') {
        return tecka;
    } else if (ch == ':') {
        return dvoj_tecka;
    } else if (ch == '{') {
        return ls_zavorka_kom;
    } else if (ch == '}') {
        return ps_zavorka_kom;
    } else if (ch == ',') {
        return carka;
    } else {
        return ostatni_znaky;
    }

}

identifikator_type identifikator_compare (char *str){
    #define begin_str "begin"
    #define boolean_str "boolean"
    #define do_str "do"
    #define else_str "else"
    #define end_str "end"
    #define false_str "false"
    #define find_str "find"
    #define forward_str "forward"
    #define function_str "function"
    #define if_str "if"
    #define integer_str "integer"
    #define readln_str "readln"
    #define real_str "real"
    #define sort_str "sort"
    #define string_str "string"
    #define then_str "then"
    #define true_str "true"
    #define var_str "var"
    #define while_str "while"
    #define write_str "write"

    if (strcmp(str, begin_str) == 0){
        return begin_id;
    }else if (strcmp(str, boolean_str) == 0){
        return boolean_id;
    }else if (strcmp(str, do_str) == 0){
        return do_id;
    }else if (strcmp(str, else_str) == 0){
        return else_id;
    }else if (strcmp(str, end_str) == 0){
        return end_id;
    }else if (strcmp(str, false_str) == 0){
        return false_id;
    }else if (strcmp(str, find_str) == 0){
        return find_id;
    }else if (strcmp(str, forward_str) == 0){
        return forward_id;
    }else if (strcmp(str, function_str) == 0){
        return function_id;
    }else if (strcmp(str, if_str) == 0){
        return if_id;
    }else if (strcmp(str, integer_str) == 0){
        return integer_id;
    }else if (strcmp(str, readln_str) == 0){
        return readln_id;
    }else if (strcmp(str, real_str) == 0){
        return real_id;
    }else if (strcmp(str, sort_str) == 0){
        return sort_id;
    }else if (strcmp(str, string_str) == 0){
        return string_id;
    }else if (strcmp(str, then_str) == 0){
        return then_id;
    }else if (strcmp(str, true_str) == 0){
        return true_id;
    }else if (strcmp(str, var_str) == 0){
        return var_id;
    }else if (strcmp(str, while_str) == 0){
        return while_id;
    }else if (strcmp(str, write_str) == 0){
        return write_id;
    }
}
//funkce prida dalsi znak do retezce
void add_char(char *str, char ch, int *index) {
    str[*index] = ch;
    (*index)++;
    str[*index] = 0;
    return;
}
void remove_last_char(char *str, int *index) {
    (*index)--;
    str[*index] = 0;
    return;
}
void id_add_char (char **str, char ch, int *index, int *pocet_1) {
    (*str)[*index] = ch;
    (*index)++;
    (*str)[*index] = 0;
    if ((*index) == ((*pocet_1)-2)){
        *pocet_1 = (*pocet_1) + 10;
        (*str) = realloc((*str), *pocet_1);
    }

}
// navratova hodnota = NULL pokud je nacten cely soubor, jinak vraci ukazal na token globalni promennou
//deklarace jednotlivych stavu v konecnem automatu

// globalni promenna
char *token_str = NULL;


int get_token(){
    stav_type stav = start;
    char ch;
    int token_index = 0;
    int pocet = 12;
    double number;
    //extern char id_str [12];
    if (token_str == NULL) {
      token_str = (char *)malloc(pocet);
    }

    do {
        if ((ch = getc(srcfile)) == EOF) {
            // jestlize se jedna o prvni cteni, tj. neni rozecten zadny token, vrati se NULL= konec zdrojoveho souboru
            if (stav == start) {
                return 0;
            } else {
                ungetc(ch, srcfile); // vrat eof do cteneho suboru aby se priste ukoncilo korektne nacitani zdrojoveho souboru
            }

        }
        switch (stav) {
        case start:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = cele_cislo;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case pismeno:
                    stav = identifikator;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case pismeno_e:
                    stav = identifikator;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case strednik:
                    return 3;
                    break;
                case plus_znak:
                    return 4;
                    break;
                case minus_znak:
                    return 5;
                    break;
                case krat_znak:
                    return 6;
                    break;
                case lomeno_znak:
                    return 7;
                    break;
                case rovno_znak:
                    return 12;
                    break;
                case vetsi_znak:
                    stav = vetsi_stav;
                    break;
                case dvoj_tecka:
                    stav = dvoj_tecka_stav;
                    break;
                case apostrof:
                    return 13;
                    break;
                case ls_zavorka:
                    return 14;
                    break;
                case ps_zavorka:
                    return 15;
                    break;
                case escape:
                    stav = escape_stav;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case ls_zavorka_kom:
                    stav = komentar;
                    break;
                case white_space:
                    stav = start;
                    break;
                default:
                    return EOF;
                    break;
                }
            break;
        case dvoj_tecka_stav:
                switch (get_char_type(ch)) {
                case rovno_znak:
                    return 40;
                    break;
                default:
                    ungetc(ch, srcfile);
                    return 18;
                    break;
                }
        case vetsi_stav:
                switch (get_char_type(ch)) {
                case rovno_znak:
                    return 10;
                    break;
                default:
                    ungetc(ch, srcfile);
                    return 8;
                    break;
                }
        case mensi_stav:
                switch (get_char_type(ch)) {
                case rovno_znak:
                    return 11;
                    break;
                case vetsi_znak:
                    return 41;
                    break;
                default:
                    ungetc(ch, srcfile);
                    return 9;
                    break;
                }
        case cele_cislo:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = cele_cislo;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case tecka:
                    stav = realne_cislo;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case pismeno_e:
                    stav = cislo_e;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case plus_znak:
                    stav = cislo_operator;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                default:
                    ungetc(ch, srcfile);
                    //sscanf(token_str,"%d", &(token.value.intval));
                    return 2;
                }
        case realne_cislo:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = realne_cislo;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case pismeno_e:
                    stav = cislo_e;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case plus_znak:
                    stav = cislo_operator;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case minus_znak:
                    stav = cislo_operator;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                default:
                    ungetc(ch, srcfile);
                    //sscanf(token_str,"%d", &(token.value.intval));
                    return 2;
                }
        case escape_stav:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = escape_stav;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                default:
                    ungetc(ch, srcfile);
                    //sscanf(token_str,"%d", &(token.value.intval));
                    return 16;
                }
        case cislo_e:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = cislo_e;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                default:
                    ungetc(ch, srcfile);
                    //sscanf(token_str,"%d", &(token.value.intval));
                    return 2;
                }
        case cislo_operator:
                switch (get_char_type(ch)) {
                case pismeno_e:
                    stav = cislo_e;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                default:
                    ungetc(ch, srcfile);
                    ungetc(ch, srcfile);
                    remove_last_char(token_str, &token_index);
                    //sscanf(token_str,"%d", &(token.value.intval));
                    return 2;
                }
        case identifikator:
                switch (get_char_type(ch)){
                case pismeno:
                    stav = identifikator;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                case pismeno_e:
                    stav = identifikator;
                    id_add_char(token_str, ch, &token_index, &pocet);
                    break;
                default:
                    switch (identifikator_compare (token_str)){
                    case begin_id:
                        ungetc(ch, srcfile);
                        return 20;
                    case boolean_id:
                        ungetc(ch, srcfile);
                        return 21;
                    case do_id:
                        ungetc(ch, srcfile);
                        return 22;
                    case else_id:
                        ungetc(ch, srcfile);
                        return 23;
                    case end_id:
                        ungetc(ch, srcfile);
                        return 24;
                    case false_id:
                        ungetc(ch, srcfile);
                        return 25;
                    case find_id:
                        ungetc(ch, srcfile);
                        return 26;
                    case forward_id:
                        ungetc(ch, srcfile);
                        return 27;
                    case function_id:
                        ungetc(ch, srcfile);
                        return 28;
                    case if_id:
                        ungetc(ch, srcfile);
                        return 29;
                    case integer_id:
                        ungetc(ch, srcfile);
                        return 30;
                    case readln_id:
                        ungetc(ch, srcfile);
                        return 31;
                    case real_id:
                        ungetc(ch, srcfile);
                        return 32;
                    case sort_id:
                        ungetc(ch, srcfile);
                        return 33;
                    case string_id:
                        ungetc(ch, srcfile);
                        return 34;
                    case then_id:
                        ungetc(ch, srcfile);
                        return 35;
                    case true_id:
                        ungetc(ch, srcfile);
                        return 36;
                    case var_id:
                        ungetc(ch, srcfile);
                        return 37;
                    case while_id:
                        ungetc(ch, srcfile);
                        return 38;
                    case write_id:
                        ungetc(ch, srcfile);
                        return 39;
                    default:
                        ungetc(ch, srcfile);
                        return 1;
                    }
                    token.type = id;
                    break;
                }
        case komentar:
                switch (get_char_type(ch)) {
                case ps_zavorka_kom:
                    stav = start;
                    break;
                default:
                    stav = komentar;
                    break;
                }
        }

    } while (stav != konec);
}
/*
int main (int argc, char* argv[]) {
    token_type *mytoken;
    if (argc > 1) {
        if (opensrcfile(argv[1]) == VALID_SRCFILE) {
            while ((mytoken = get_token()) != NULL) {
                switch (mytoken->type) {
                case id:
                    printf ("id: %s", mytoken->value.id);
                    break;
                case operator:
                    printf ("operator: %i", mytoken->value.oper);
                    break;
                }

            }
            closesrcfile();
        }
     } else {
        printf("\nChybne parametry\n");
        return 0;
    }

}
*/

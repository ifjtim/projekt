#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//definice jednotlivych typu tokenu
typedef enum {
id, int_lit, real_lit, str_lit, bool_lit, key_word, data_type, operator, kom_lit,
} tokentype_type;
//definice operatoru
typedef enum {
prirazeni, plus, minus, krat, deleno, mensi, vetsi, mensi_rovno, vetsi_rovno, rovno, nerovno
} operator_type;
//definice jednotlivych velikosti pro
typedef union {
    char id[256];
    int intval;
    double realval;
    char strval[256];
    int boolval;
    char keyword[15];
    char datatype[15];
    operator_type oper;
    char kom[256];
} token_value_type;
//struktura funkce token
typedef struct {
    tokentype_type type;
    token_value_type value;
} token_type;

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

typedef enum{
    white_space, cislo, pismeno, strednik, apostrof, ls_zavorka, ps_zavorka, escape, tecka, dvoj_tecka, ls_zavorka_kom, ps_zavorka_kom, carka, ostatni_znaky,
    plus_znak, minus_znak, krat_znak, lomeno_znak, vetsi_znak, mensi_znak, rovno_znak,
} character_type;
//deklarace jednotlivych znaku ktery mohou prijit
character_type get_char_type(char ch) {
    if ((ch == ' ') || (ch == '\n') || (ch == EOF)) {
        return white_space;
    } else if ((ch >= '0') && (ch <='9')) {
        return cislo;
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
typedef enum{
begin_id, boolean_id, do_id, else_id, end_id, false_id, find_id, forward_id, function_id, if_id, integer_id, readln_id, real_id, sort_id, string_id, then_id, true_id, var_id, while_id, write_id,
} identifikator_type;

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

    if (strcmp(*str, begin_str) == 0){
        return begin_id;
    }else if (strcmp(*str, boolean_str) == 0){
        return boolean_id;
    }else if (strcmp(*str, do_str) == 0){
        return do_id;
    }else if (strcmp(*str, else_str) == 0){
        return else_id;
    }else if (strcmp(*str, end_str) == 0){
        return end_id;
    }else if (strcmp(*str, false_str) == 0){
        return false_id;
    }else if (strcmp(*str, find_str) == 0){
        return find_id;
    }else if (strcmp(*str, forward_str) == 0){
        return forward_id;
    }else if (strcmp(*str, function_str) == 0){
        return function_id;
    }else if (strcmp(*str, if_str) == 0){
        return if_id;
    }else if (strcmp(*str, integer_str) == 0){
        return integer_id;
    }else if (strcmp(*str, readln_str) == 0){
        return readln_id;
    }else if (strcmp(*str, real_str) == 0){
        return real_id;
    }else if (strcmp(*str, sort_str) == 0){
        return sort_id;
    }else if (strcmp(*str, string_str) == 0){
        return string_id;
    }else if (strcmp(*str, then_str) == 0){
        return then_id;
    }else if (strcmp(*str, true_str) == 0){
        return true_id;
    }else if (strcmp(*str, var_str) == 0){
        return var_id;
    }else if (strcmp(*str, while_str) == 0){
        return while_id;
    }else if (strcmp(*str, write_str) == 0){
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
// navratov hodnota = NULL pokud je nacten cely soubor, jinak vraci ukazal na token globalni promennou
//deklarace jednotlivych stavu v konecnem automatu
typedef enum{
    start,
    cele_cislo, realne_cislo, realne_cislo_e, realne_cislo_exponent,
    identifikator, operator_symbol, apostrof_stav,
    dvoj_tecka_stav, komentar, vetsi_stav, mensi_stav,
    konec
} stav_type;


token_type *get_token(){
    stav_type stav = start;
    char ch;
    char token_str[256] = "";
    int token_index = 0;

    do {
        if ((ch = getc(srcfile)) == EOF) {
            // jestlize se jedna o prvni cteni, tj. neni rozecten zadny token, vrati se NULL= konec zdrojoveho souboru
            if (stav == start) {
                return NULL;
            } else {
                ungetc(ch, srcfile); // vrat eof do cteneho suboru aby se priste ukoncilo korektne nacitani zdrojoveho souboru
            }

        }
        switch (stav) {
        case start:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = cele_cislo;
                    add_char(token_str, ch, &token_index);
                    break;
                case pismeno:
                    stav = identifikator;
                    add_char(token_str, ch, &token_index);
                    break;
                case strednik:
                    token.type = key_word;
                    token.value.keyword[0] = ';';
                    token.value.keyword[1] = 0;
                    return &token;
                    break;
                case plus_znak:
                    return;
                    break;
                case minus_znak:
                    return;
                    break;
                case krat_znak:
                    return;
                    break;
                case lomeno_znak:
                    return;
                    break;
                case rovno_znak:
                    return;
                    break;
                case vetsi_znak:
                    stav = vetsi_stav;
                    break;
                case apostrof:
                    stav = apostrof_stav;
                    add_char(token_str, ch, &token_index);
                    break;
                case ls_zavorka:
                    token.type = key_word;
                    token.value.keyword[0] = '(';
                    token.value.keyword[1] = 0;
                    return &token;
                    break;
                case ps_zavorka:
                    token.type = key_word;
                    token.value.keyword[0] = ')';
                    token.value.keyword[1] = 0;
                    return &token;
                    break;
                case escape:
                    token.type = key_word;
                    token.value.keyword[0] = '#';
                    token.value.keyword[1] = 0;
                    break;
                case dvoj_tecka:
                    stav = dvoj_tecka_stav;
                    add_char(token_str, ch, &token_index);
                    break;
                case ls_zavorka_kom:
                    stav = komentar;
                    add_char(token_str, ch, &token_index);
                    break;
                case white_space:
                    stav = start;
                    add_char(token_str, ch, &token_index);
                    break;
                }
            break;
        case vetsi_stav:
                switch (get_char_type(ch)) {
                case rovno_znak:
                    return;
                    break;
                default:
                    ungetc(ch, srcfile);
                    return;
                    break;
                }
        case mensi_stav:
                switch (get_char_type(ch)) {
                case rovno_znak:
                    return;
                    break;
                case vetsi_znak:
                    return;
                    break;
                default:
                    ungetc(ch, srcfile);
                    return;
                    break;
                }
        case cele_cislo:
                switch (get_char_type(ch)) {
                case cislo:
                    stav = cele_cislo;
                    add_char(token_str, ch, &token_index);
                    break;
                case white_space:

                default:
                    ungetc(ch, srcfile);
                    token.type = int_lit;
                    sscanf(token_str,"%d", &(token.value.intval));
                    return &token;
                }
        case identifikator:
                switch (get_char_type(ch)){
                case pismeno:
                    stav = identifikator;
                    add_char(token_str, ch, &token_index);
                    break;
                default:
                    switch (identifikator_compare (token_str)){
                    case begin_id:
                        ungetc(ch, srcfile);
                        return;
                    case boolean_id:
                        ungetc(ch, srcfile);
                        return;
                    case do_id:
                        ungetc(ch, srcfile);
                        return;
                    case else_id:
                        ungetc(ch, srcfile);
                        return;
                    case end_id:
                        ungetc(ch, srcfile);
                        return;
                    case false_id:
                        ungetc(ch, srcfile);
                        return;
                    case find_id:
                        ungetc(ch, srcfile);
                        return;
                    case forward_id:
                        ungetc(ch, srcfile);
                        return;
                    case function_id:
                        ungetc(ch, srcfile);
                        return;
                    case if_id:
                        ungetc(ch, srcfile);
                        return;
                    case integer_id:
                        ungetc(ch, srcfile);
                        return;
                    case readln_id:
                        ungetc(ch, srcfile);
                        return;
                    case real_id:
                        ungetc(ch, srcfile);
                        return;
                    case sort_id:
                        ungetc(ch, srcfile);
                        return;
                    case string_id:
                        ungetc(ch, srcfile);
                        return;
                    case then_id:
                        ungetc(ch, srcfile);
                        return;
                    case true_id:
                        ungetc(ch, srcfile);
                        return;
                    case var_id:
                        ungetc(ch, srcfile);
                        return;
                    case while_id:
                        ungetc(ch, srcfile);
                        return;
                    case write_id:
                        ungetc(ch, srcfile);
                        return;
                    default:
                        ungetc(ch, srcfile);
                        return;
                    }
                    token.type = id;
                    break;
                }
        case komentar:
                switch (get_char_type(ch)) {
                case ps_zavorka_kom:
                    stav = start;
                    token.type = kom_lit;
                    sscanf(token_str,"%s", &(token.value.kom));
                    return &token;
                default:
                    stav = komentar;
                }
        case apostrof_stav:
                switch (get_char_type(ch)) {
                case apostrof:
                    stav = start;
                    token.type = kom_lit;
                    sscanf(token_str,"%s", &(token.value.kom));
                    return &token;
                default:
                    stav = apostrof_stav;
                }
        }

    } while (stav != konec);
}
//TO DO!
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

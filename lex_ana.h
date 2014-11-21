
#ifndef LEX_ANA_H
  #define LEX_ANA_H

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

typedef enum{
    white_space, cislo, pismeno, strednik, apostrof, ls_zavorka, ps_zavorka, escape, tecka, dvoj_tecka, ls_zavorka_kom, ps_zavorka_kom, carka, ostatni_znaky,
    plus_znak, minus_znak, krat_znak, lomeno_znak, vetsi_znak, mensi_znak, rovno_znak, pismeno_e
} character_type;

typedef enum{
begin_id, boolean_id, do_id, else_id, end_id, false_id, find_id, forward_id, function_id, if_id, integer_id, readln_id, real_id, sort_id, string_id, then_id, true_id, var_id, while_id, write_id,
} identifikator_type;

typedef enum{
    start,
    cele_cislo, realne_cislo, cislo_e, cislo_operator,
    identifikator, escape_stav,
    dvoj_tecka_stav, komentar, vetsi_stav, mensi_stav,
    konec
} stav_type;


int get_token();
// globalni promenna
extern char *token_str;

#endif // LEX_ANA_H

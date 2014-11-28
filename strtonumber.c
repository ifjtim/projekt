#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* DEKLARACE*/
int strtoint (char * S1);
float strtofloat(char *S1);

/* STRING TO INT*/
int strtoint (char * S1)
{
    int c=0;
    int x=0;
    int v=0;

    for (x=0;x<strlen(S1);x++){
        c=S1[x]-'0';//aktualní char na int
        v=v*10; //dekadicky posun
        v=v+c;
            }
    return v;
}


/*STRING TO FLOAT*/
float strtofloat(char *S1)

{

    char *stopstring;
    float b;

    b = strtof(S1,&stopstring);

    return b;
}




/*MAIN*/
int main()
{
    char s1[]=  "785";
    int a=strtoint(s1);

        printf("final res:%d\n",a); //volani me funkce

    char s2[]=  "7.85";
    float c=strtofloat(s2);//volani me funkce

        printf("final res:%f\n",c);

    return 0;
}



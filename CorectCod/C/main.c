#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "func.h"

char rule[30] = "func(myFunction)"; // sirul care contine regula
char code[N];                       // sirul care se introduce de la tastatura sau se genereaza

int main()
{
    printf("Alege o optiune:\n");              // am creat un meniu din care utilizatorul poate
    printf("1. Genereaza un sir aleatoriu\n");             // alege daca vrea ca sirul sa se genereze automat
    printf("2. Introdu un sir de la tastatura\n");    // sau daca vrea sa il introduca de la tastatura
    int raspuns;
    scanf("%d", &raspuns);

    if(raspuns == 1)
    {
        printf("Introdu lungimea sirului:\n");
        scanf("%lld", &length);

        srand(time(0));
        genereazaSir(code);
    }
    else if (raspuns == 2)
    {
        printf("Introdu lungimea sirului:\n");
        scanf("%lld", &length);
        int c;
        while ((c = getchar()) != '\n' && c != EOF) {}
        fgets(code, length, stdin);
        code[strlen(code) - 1] = '\0';
    }
    else
    {
        printf("Optiunea aleasa nu exista!");
        return 0;
    }

    printf("Inainte de corectare: \n%s\n\n", code);
    clock_t begin = clock();
    int distanta = calculeazaDistanta(rule, code);
    clock_t end = clock();
    double timp_executie = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Distanta dintre cele doua siruri este de %d\n\n", distanta);
    printf("Dupa corectare: \n%s\n\n", code);
    printf("Timp de executie : %llf secunde", timp_executie);

    return 0;
}

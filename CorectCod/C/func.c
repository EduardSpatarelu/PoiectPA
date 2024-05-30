#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "func.h"

// Functia findCharacter cauta un caracter in lista si, daca il gaseste, il returneaza

Character* findCharacter(char caracter)
{
    Character* nodCurent = charArr.head;  // Pointerul nodCurent primeste pozitia primului nod al listei
    while(nodCurent != NULL)              // Cat timp nodCurent este diferit de NULL
    {
        if(nodCurent->ch == caracter)     // Daca caracterul retinut de obiect este acelasi ca cel cautat
        {
            return nodCurent;             // Se returneaza un pointer catre obiectul respectiv
        }
        nodCurent = nodCurent->next;      // nodCurent trece la urmatorul nod din lista
    }
    return NULL;                          // Daca nu se gaseste caracterul cautat se returneaza NULL
}

// Functia elibereazaPointeri elibereaza pointerii

void elibereazaPointeri()
{
    Character* nodCurent = charArr.head;      // Pointerul nodCurent primeste pozitia primului nod al listei
    while(nodCurent != NULL)                  // Cat timp nodCurent este diferit de NULL
    {
        Character* urmatorulNod = nodCurent->next; // Pointerul urmatorulNod primeste nodul de dupa nodul curent
        free(nodCurent);                      // Se elibereaza pointerul curent
        nodCurent = urmatorulNod;             // nodCurent trece la nodul salvat in urmatorulNod
    }
}

// Functia adaugaInLista adauga caractere intr-o lista

void adaugaInLista(Character* element)
{
    if(charArr.head == NULL)          // Daca capul listei este NULL inseamna ca lista inca nu a fost creata
    {
        charArr.head = element;       // Capul listei primeste elementul pe care dorim sa il adaugam in lista
        charArr.tail = element;       // Pentru ca in acest caz avem doar primul nod, si tail primeste tot acel element
        charArr.head->next = NULL;    // head->next primeste NULL deoarece acolo se termina lista
    }
    else                              // In cazul in care lista a fost deja creata
    {
        charArr.tail->next = element; // tail->next primeste elementul pe care vrem sa il adaugam
        charArr.tail = element;       // Apoi il mutam pe tail la elementul nou adaugat
        element->next = NULL;         // Pentru ca element este ultimul, element->next este NULL
    }
}

// Functia creazaVectorFrecventa creaza o lista ce are rolul unui vector de aparitii
// creste numarul de aparitii al fiecarui caracter ce apare in sirul regula, dupa care scade numarul
// de aparitii pentru caracterele ce apar in sirul cod. Se urmareste ca valorile sa ajunga la 0,
// ceea ce inseamna ca acele caractere apar de acelasi numar de ori in ambele siruri

void creazaVectorFrecventa(char* regula, char* cod)
{
    charArr.head = NULL;
    charArr.tail = NULL;

    for(long long i = 0; i < strlen(regula); i++)     // Se parcurge sirul regula
    {
        Character* element = findCharacter(regula[i]);     // Se cauta caracterul de la pozitia i din regula
        if(element != NULL)                         // Daca s-a mai gasit la o alta pozitie anterioara
        {
            element->cnt++;                         // Se creste numarul de aparitii al caracterului
        }
        else
        {
            element = (Character*)malloc(sizeof(Character)); // In cazul in care nu a mai fost gasit anterior
            element->ch = regula[i];                         // Caracterul curent va fi egal cu caracterul de la pozitia
            element->cnt = 1;                                // i din sirul regula si se va contoriza in cnt
            element->next = NULL;                            // Campul urmator al noului nod va fi NULL
            adaugaInLista(element);                          // Apelezi functia de adaugare in lista a noului element
        }
    }

    for(long long i = 0; i < strlen(cod); i++)     // Se parcurge sirul cod
    {
        Character* element = findCharacter(cod[i]);     // Se cauta caracterul de la pozitia i din cod
        if(element != NULL)                         // Daca caracterul s-a mai gasit anterior se scade contorizarea lui
        {
            element->cnt--;
        }
    }
}

// Functia genereazaSir genereaza un sir aleatoriu de lungime length

void genereazaSir(char* sir)
{
    for(long long i = 0; i < length; i++)
    {
        int max = 255;
        int min = 0;
        int r = rand() % (max - min) + min;
        char ch = (char)r;
        if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
        {
            sir[i] = ch;
        }
        else
        {
            i--;
        }
    }
}

// Functia calculeazaDistanta calculeaza distanta dintre sirul regula si cod, timp in care corecteaza sirul cod
// Distanta reprezinta numarul de operatii de adaugare, stergere sau interschimbare intre doua caractere
// care se aplica pe sirul cod pentru a ajunge identic cu sirul regula

int calculeazaDistanta(char* regula, char* cod)
{
    creazaVectorFrecventa(regula, cod);

    long long distanta = 0; // Variabila in care se va contoriza distanta dintre siruri

    long long i = 0;
    while(i < strlen(regula) || i < strlen(cod))                 // Se parcurge pana la finalul celui mai lung sir
    {
        if(cod[i] != regula[i])                       // Daca caracterul de la pozitia i difera in cele doua siruri
        {
            Character* element1 = findCharacter(regula[i]);           // Cautam caracterul de la pozitia i din sirul regula
            Character* element2 = findCharacter(cod[i]);           // Cautam caracterul de la pozitia i din sirul cod
            if(element1 != NULL && element1->cnt > 0)          // Daca caracterul de la poz i din sirul regula exista in lista de aparitii
            {
                for(long long j = strlen(cod); j >= i; j--)   // Si cnt este pozitiv, adica se afla de mai multe ori in regula decat in cod
                {
                    cod[j + 1] = cod[j];                     // Se muta toate elementele de la dreapta elementului
                }                                              // La dreapta cu o pozitie pentru face loc sa se insereze caracterul potrivit
                element1->cnt--;                               // Atunci se scade contorul caracterului
                cod[i] = regula[i];                            // Se copiaza caracterul
                distanta++;                                    // Si creste distanta
            }
            else if(element2 == NULL)                          // Daca un caracter din cod nu se afla in lista de aparitii
            {
                for(long long j = i; j < strlen(cod); j++)    // Se muta toate caracterele de dupa acesta
                {
                    cod[j] = cod[j + 1];                     // Cu o pozitie la stanga astfel stergandu-l
                }
                distanta++;                                    // Distanta creste
            }
            else if(element2->cnt < 0)                         // Daca avem nevoie de acel caracter dar este de prea
            {
                for(long long j = i; j < strlen(cod) - 1; j++)   // Multe ori
                {
                    cod[j] = cod[j + 1];                     // Atunci se muta toate elementele de la acea pozitie
                }                                              // La stanga cu o pozitie
                cod[strlen(cod) - 1] = '\0';                 // Se adauga la sfarsitul sirului NULL
                element2->cnt++;                               // Se creste valoare contorului aferent caracterului
                distanta++;                                    // Creste distanta
            }
            else                            // Daca caracterul gasit in cod nu trebuie sters sau adaugat creste i-ul
            {
                i++;
            }
        }
        else
        {
            i++;                           // Daca caracterele de la pozitia i din regula si cod sunt egale creste i-ul
        }
    }

    i = 0;
    while(i < strlen(cod))       // In acest while se face interschimbarea a doua caractere daca nu sunt pe pozitia
    {
        if(cod[i] != regula[i])    // Corecta desi ele apar in cod de cate ori trebuie
        {
            long long j = i + 1;
            while(j < strlen(cod))   // Se cauta caracterul cu care trebuie interschimbat
            {
                if(regula[i] == cod[j] && cod[j] != regula[j])
                {
                    char aux;
                    aux = cod[i];
                    cod[i] = cod[j];
                    cod[j] = aux;
                }
                j++;
            }
            distanta++;         // Distanta creste
        }
        else
        {
            i++;                // Creste i-ul ca sa mearga mai departe in cod
        }
    }

    elibereazaPointeri();             // Eliberez pointerii pe care i-am folosit

    return distanta;            // Returnez distanta
}

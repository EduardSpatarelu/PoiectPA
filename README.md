# PoiectPA

# Descriere
Aceasta este o aplicație care corectează un șir de caractere generat aleatoriu sau introdus de utilizator pentru a se potrivi cu o regulă dată.

# Structura proiectului
main.c: Conține funcția principală care rulează aplicația.
func.c: Conține implementarea funcțiilor necesare pentru manipularea și corectarea șirurilor.
func.h: Header-ul care declară funcțiile și structurile de date utilizate.
README.md: Acest fișier, care conține instrucțiuni de compilare și utilizare.

# Cerințe
Pentru a compila și rula acest proiect, veți avea nevoie de:

Un compilator C (de exemplu, GCC)

# Instrucțiuni de compilare
Compilați func.c și main.c într-un fișier obiect:

gcc -c func.c -o func.o gcc -c main.c -o main.o

Linkuiți fișierele obiect pentru a crea executabilul:

gcc func.o main.o -o my_program

# Utilizare
După compilare, puteți rula programul executabil my_program:

./my_program

Programul vă va cere să alegeți una dintre cele două opțiuni:

Generarea unui șir aleatoriu Introducerea unui șir de la tastatură

Urmați instrucțiunile afișate pentru a introduce lungimea șirului sau șirul dorit.

# Exemplu
Alege o optiune:
1. Genereaza un sir aleatoriu
2. Introdu un sir de la tastatura
1
Introdu lungimea sirului:
5
Inainte de corectare:
qBGHn

Distanta dintre cele 2 siruri este de 19

Dupa corectare:
func(myFunction)

Timp de executie: 0.000000 secunde

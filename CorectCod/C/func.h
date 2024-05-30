#ifndef FUNC_H_INCLUDED
#define FUNC_H_INCLUDED

#define N 100000000
long long length;

typedef struct
{
    char ch;
    long long cnt;
    struct Character* next;
} Character;

typedef struct
{
    Character* head, *tail;
} CharacterArray;


CharacterArray charArr;

Character* findChar(char c);
void createFrequencyArray(char* rule, char* code);
void freePointers();
void addToList(Character* element);
void generateString(char* string);
int getDistance(char* rule, char* code);

#endif // FUNC_H_INCLUDED

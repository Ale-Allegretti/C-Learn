#include "list_Allegretti_Alessandro_0000974745.h"

#define BOOLEAN int
#define FALSE 0
#define TRUE 1

Set leggiUnSet(FILE* fp);
list leggiTuttiSet(char* fileName);

Complex leggiUnComplex(FILE* fp);
Complex trovaComplex(char* fileName, int target);

void swap(int* a, int* b);
int compare(int e1, int e2);
void quickSortR(int* v, int iniz, int fine);
void ordina(int* v, int dim);

int check(list elenco, int target, Set* theSet);
int disp(list elenco, int target, char* fileName);
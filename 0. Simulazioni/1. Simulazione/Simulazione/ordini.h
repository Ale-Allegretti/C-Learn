#include "pizza.h"

Pizza leggiPizza(FILE* fp);
Pizza* leggiOrdini(char* fileName, int* tot_lette);

int compare(Pizza e1, Pizza e2);
void swap(Pizza* e1, Pizza* e2);
void assign(Pizza* lvalue, Pizza rvalue);
void naiveSort(Pizza* a, int dim);


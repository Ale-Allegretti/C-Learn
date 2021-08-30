#pragma once

#ifndef BARH
#define BARH
#include "list.h"

Ingrediente* leggiIng(char* fileName, int* dim);

void stampa(Ingrediente* elenco, int dim);

Ingrediente trova(Ingrediente* elenco, int dim, char* nome);

void assign(Ingrediente* lvalue, Ingrediente rvalue);
void swap(Ingrediente* a, Ingrediente* b);
float compare(Ingrediente e1, Ingrediente e2);
void ordina(Ingrediente* v, int dim);

list leggiPanini(char* fileName, Ingrediente* elenco, int dim);

list eliminaDup(list panini);


#endif
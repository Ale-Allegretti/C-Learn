#pragma once

#ifndef BARH
#define BARH
#include "list.h"

int readField(char buffer[], int dim_buffer, char sep, FILE* f);
list leggiPaste(char* fileName);

Ordine* leggiOrdini(char* fileName, int* dim);

void assign(Ordine* lvalue, Ordine rvalue);
void swap(Ordine* a, Ordine* b);
int compare(Ordine e1, Ordine e2);
void bubbleSort(Ordine* v, int size_v);
void ordina(Ordine* v, int dim);

int soddisfacibile(list paste, Ordine unOrdine);

list eseguiOrdine(list paste, Ordine unOrdine);


#endif
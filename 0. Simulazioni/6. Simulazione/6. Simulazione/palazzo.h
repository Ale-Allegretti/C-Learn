#pragma once

#ifndef PALAZZOH
#define PALAZZOH
#include "list.h"

Appartamento leggiUnAppartamento(FILE* fp);
list leggiTuttiAppartamenti(char* fileName);

void assign(Appartamento* lvalue, Appartamento rvalue);
void swap(Appartamento* a, Appartamento* b);
int compare(Appartamento e1, Appartamento e2);
void bubbleSort(Appartamento* v, int size_v);

Appartamento* trovaAppartamento(list appartamenti, int pianoMin, float mqMin, int* dim);

Offerta leggiUnOfferta(FILE* fp);

int registraOfferta(int idAppartamento, char* cliente, float importo);

#endif
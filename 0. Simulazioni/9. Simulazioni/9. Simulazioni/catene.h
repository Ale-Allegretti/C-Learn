#pragma once

#ifndef CATENEH
#define CATENEH
#include "list.h"

Catena leggiUno(FILE* fp);

Catena* leggiTutte(char* fileName, int* dim);

void stampa(Catena* v, int dim);

void assign(Catena* lvalue, Catena rvalue);
void swap(Catena* e1, Catena* e2);
int compare(Catena e1, Catena e2);
void ordina(Catena* v, int dim);

list conta(Catena* v, int dim);

int compatibili(int diametro, int larghezza, Catena c1);
list filtra(int diametro, int larg, list disponibili);

#endif
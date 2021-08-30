#include "list.h"

#ifndef METROH
#define METROH

Evento leggiUno(FILE* fp);

void printEvento(Evento e);

int readField1(char buffer[], int dim_buffer, char sep, FILE* f);
int readField2(char buffer[], int dim_buffer, FILE* f);

Tariffa* leggiTariffe(char* fileName, int* dim);

list leggiTutti(char* fileName);

void ordina(Tariffa* v, int dim);

float ricerca(Tariffa* v, int dim, char* ingresso, char* uscita);

#endif
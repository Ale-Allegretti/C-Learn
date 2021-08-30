#pragma once

#ifndef NOLEGGIOH
#define NOLEGGIOH
#include "list.h"

Veicolo leggiVeicolo(FILE* fp);

Veicolo* leggiTuttiVeicoli(char* fileName, int* dim);

list leggiMovimenti(char* fileName);

int disponibile(list movimenti, int idveicolo);

void posizione(list movimenti, Veicolo veicolo, float* lat, float* lon);

void assign(Veicolo* lvalue, Veicolo rvalue);
void swap(Veicolo* e1, Veicolo* e2);
int compare(Veicolo e1, Veicolo e2, float lat, float lon);
void naiveSort(Veicolo* a, int dim, float lat, float lon);

void ordina(Veicolo* veicoli, int dim, float lat, float lon);

Veicolo cerca(Veicolo* veicoli, int dim, list movimenti, float lat, float lon);


#endif
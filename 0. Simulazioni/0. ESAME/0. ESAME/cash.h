// Allegretti Alessandro - Matricola: 0000974745 - MODULO 2

#pragma once

#ifndef _CASH_H
#define _CAHS_H
#include "list.h"

//ESERCIZIO 1
Operazione * leggiTutteOperazioni(char* fileName, int* dim);

list leggiNegozi(char* fileName);

void stampaOperazioni(Operazione* v, int dim);

//ESERCIZIO 2
void assign(Operazione* lvalue, Operazione rvalue);
void swap(Operazione* e1, Operazione* e2);
float compare(Operazione e1, Operazione e2);
void ordina(Operazione* v, int dim);


int negozioFisico(char* nomeNegozio, list negozi);

Operazione* filtra(Operazione* v, int dim, list negozi, int* dimLog);

//ESERCIZIO 3

float spesaCliente(int idCliente, Operazione* v, int dim);



#endif
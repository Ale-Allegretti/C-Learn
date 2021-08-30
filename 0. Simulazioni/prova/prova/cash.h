/*
* Mantovani Federico 0000977019 Prova 1A
*
*/
#pragma once
#ifndef CASH_H
#define CASH_H
#include "element.h"
#include "list.h"
// ES 1
operazione* leggiTutteOperazioni(char* fileName, int* dim);
list leggiNegozi(char* fileName);
void stampaOperazioni(operazione* v, int dim);

// ES 2
void ordina(operazione* v, int dim);
void bubbleSort(operazione* arr, int size);
void swap(operazione* op1, operazione* op2);
int negozioFisico(char* nomeNegozio, list negozi);
operazione* filtra(operazione* v, 
	int dim, list negozi, int* dimLog);

// ES 3
float spesaCliente(int idCliente, operazione* v, int dim);

// ES 4
// restituisce un array di int contenente i singoli Id non ripetuti
int* getAllIDs(operazione* v, int dim, int* dimLog, list negozi);
// ritorna 1 se l'id è nell'array, 0 altrimenti
int compareIDs(int id, int* arrayIDs, int dim);
#endif
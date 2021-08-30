/*
* Mantovani Federico 0000977019 Prova 1A
*
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#ifndef ELEMENT_H
#define ELEMENT_H
#define LENGTH_NEGOZIO 1024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct element {
	int id;
	float importo;
	char nomeNegozio[LENGTH_NEGOZIO];
}operazione;

typedef struct element2 {
	char nome[LENGTH_NEGOZIO];
	char tipo;
}negozio;

typedef int boolean; // non c'entra ma è utile

boolean isEqual(operazione e1, operazione e2);
int compare(operazione e1, operazione e2);
operazione getElement();
void printElement(operazione el);
void printNegozio(negozio n);
int compareOp(operazione op1, operazione op2);
#endif

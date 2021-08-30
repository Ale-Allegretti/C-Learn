// Allegretti Alessandro - Matricola: 0000974745 - MODULO 2

#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef ELEMENTH
#define ELEMENTH
#define DIM 1024

typedef struct {
	int id;
	float importo;
	char negozio[DIM];
} Operazione;

typedef struct {
	char nome[DIM];
	char tipo;
} Negozio;




typedef Negozio Element;


#endif
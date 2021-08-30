#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef ELEMENTH
#define ELEMENTH
#define DIM 256
#define NCOMP 10

typedef struct {
	int diametro;
	int larghezza;
	float prezzo;
	char azienda[DIM];
} Catena;

typedef struct {
	Catena prod;
	int dim;
} Prodotto;


typedef Prodotto Element;


#endif
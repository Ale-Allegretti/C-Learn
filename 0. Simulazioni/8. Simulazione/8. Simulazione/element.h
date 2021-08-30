#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef ELEMENTH
#define ELEMENTH
#define DIM 64
#define NCOMP 10

typedef struct {
	char nome[DIM];
	int quant;
	float costo;
} Ingrediente;

typedef struct {
	char cliente[DIM];
	Ingrediente ing[3];
	int dim;
} Panino;

typedef Panino Element;


#endif
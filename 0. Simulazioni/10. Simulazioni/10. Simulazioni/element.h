// Allegretti Alessandro - 

#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef ELEMENTH
#define ELEMENTH
#define DIM 256
#define NTIPO 12

typedef struct {
	int id;
	char tipo[NTIPO];
	float km;
	float latit;
	float longit;
} Veicolo;

typedef struct {
	int id;
	char p_r;
	float latit;
	float longit;
	char cliente[DIM];
} Movimenti;


typedef Movimenti Element;


#endif
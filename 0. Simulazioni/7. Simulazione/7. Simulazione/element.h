#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef ELEMENTH
#define ELEMENTH
#define DIM 2048
#define NING 128

typedef struct {
	float costo;
	char tipo[DIM];
	int calorie;
} Pasta;

typedef struct {
	char ingrediente[NING];
	int num;
} Ordine;

typedef Pasta Element;


#endif
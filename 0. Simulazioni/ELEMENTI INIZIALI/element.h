#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef ELEMENTH
#define ELEMENTH
#define DIM 2048
#define NCOMP 10

typedef struct {
	int id;
	char cognome[DIM];
	char nome[DIM];
	float importo;
} Loan;


typedef Loan Element;


#endif
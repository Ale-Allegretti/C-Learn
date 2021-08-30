
#ifndef BANCAH
#define BANCAH

#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int readField(char buffer[], int dim_buffer, char sep, FILE* f);
Loan leggiUnLoan(FILE* fp);

Loan* leggiLoanAttivi(char* fileName, int* dim);

void assign(Loan* lvalue, Loan rvalue);
void swap(Loan* a, Loan* b);
int compare(Loan e1, Loan e2);
void insertSort(Loan* v, int size_v);
void insOrd(Loan* v, int pos);

void ordina(Loan* elenco, int dim);

list estrai(Loan* elenco, int dim, char* cognome, char* nome);

int stessoIndividuo(Loan l1, Loan l2);
void espo(Loan* elenco, int dim);



#endif
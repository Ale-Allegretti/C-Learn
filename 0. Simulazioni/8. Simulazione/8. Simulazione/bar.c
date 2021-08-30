#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bar.h"

Ingrediente* leggiIng(char* fileName, int* dim) {
	FILE* fp;
	Ingrediente* result = NULL;
	Ingrediente temp;
	int count;
	int lettura = 0;

	*dim = 0;

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		count = 0;
		do {
			lettura = fscanf(fp, "%s %d %f", temp.nome, &temp.quant, &temp.costo);
			if (lettura == 3);
			count++;
		} while (lettura == 3);
		if (count > 0) {
			result = (Ingrediente*)malloc(sizeof(Ingrediente) * count);
			rewind(fp);
			do {
				if (result != NULL) {
					lettura = fscanf(fp, "%s %d %f", temp.nome, &temp.quant, &temp.costo);
					if (lettura == 3) {
						result[*dim] = temp;
						(*dim)++;
					}
				}
			} while (lettura == 3);
		}
		fclose(fp);
	}
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
		result = NULL;
	}

	return result;
}

void stampa(Ingrediente* elenco, int dim) {
	if (dim == 0) {
		printf("%20s\t\t%d\t\t%.2f\n", elenco[dim].nome, elenco[dim].quant, elenco[dim].costo);
		printf("\nFine ingredienti.");
	} 
	else {
		printf("%20s\t\t%d\t\t%.2f\n", elenco[dim].nome, elenco[dim].quant, elenco[dim].costo);
		stampa(elenco, (--dim));
	}
}

Ingrediente trova(Ingrediente* elenco, int dim, char* nome) {
	Ingrediente res;
	int i;
	int trovato = 0;

	for (i = 0; i < dim && !trovato; i++) {
		if (strcmp(elenco[i].nome, nome) == 0) {
			trovato = 1;
			res = elenco[i];
		}
	}
	if (trovato)
		return res;
	else {
		strcpy(res.nome, "NULL");
		return res;
	}
}


void assign(Ingrediente* lvalue, Ingrediente rvalue)
{
	*lvalue = rvalue;
}
void swap(Ingrediente* a, Ingrediente* b)
{
	Ingrediente tmp = *a;
	*a = *b;
	*b = tmp;
}
int compare(Ingrediente e1, Ingrediente e2) {   
	int result;
	result = e1.quant - e2.quant;
	if (result == 0) {
		if (e1.costo > e2.costo)
			result = -1;
		else
			if (e1.costo < e2.costo)
				result = 1;
			else
				result = 0;
	}
	return result;
}

void bubbleSort(Ingrediente* v, int size_v) {
	int i, ordinato = 0;
	while (size_v > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < size_v - 1; i++)
			if (compare(v[i], v[i + 1]) > 0) {
				swap(&v[i], &v[i + 1]);
				ordinato = 0;
			}
		size_v--;
	}
}
void ordina(Ingrediente* v, int dim) {
	bubbleSort(v, dim);
}


list leggiPanini(char* fileName, Ingrediente* elenco, int dim) {
	list result;
	FILE* fp;
	Panino temp;
	char nome[DIM] = " ";

	result = emptyList();

	fp = fopen(fileName, "rt");

	if (fp == NULL)
		return result;
	else {
		while (fscanf(fp, "%s", temp.cliente) == 1) {
			temp.dim = 0;
			while (fscanf(fp, "%s", nome) == 1 && strcmp(nome, "fine") && temp.dim < 3) {
				temp.ing[temp.dim] = trova(elenco, dim, nome);
				temp.dim++;
			}
			result = cons(temp, result);
		}
		fclose(fp);
	}
	return result;
}

list eliminaDup(list panini) {
	list result;
	Panino temp;
	result = emptyList();
	while (!empty(panini)) {
		temp = head(panini);
		if (!member(temp, result))
			result = cons(temp, result);
		panini = tail(panini);
	}
	return result;
}





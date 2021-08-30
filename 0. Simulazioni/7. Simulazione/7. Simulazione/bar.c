#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bar.h"

int readField(char buffer[], int dim_buffer, char sep, FILE* f)
{
	int i = 0;
	char ch = fgetc(f);
	while (ch != sep && ch != '\n' && i < (dim_buffer - 1) && ch != EOF) {
		buffer[i] = ch;
		i++;
		ch = fgetc(f);
	}
	buffer[i] = '\0';

	return ch;
}
list leggiPaste(char* fileName) {
	FILE* fp;
	list result;
	Pasta temp;
	int lettura;
	char sep;

	result = emptyList();

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		do {
			lettura = fscanf(fp, "%f", &temp.costo);
			if (lettura == 1) {
				sep = readField(temp.tipo, DIM, ';', fp);
				if (sep == ';') {
					lettura = fscanf(fp, "%d", &temp.calorie);
					if (lettura == 1)
						result = cons(temp, result);
				}
			}
		} while (lettura == 1 && sep == ';');
		fclose(fp);
	} 
	
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
	}

	return result;
}

Ordine* leggiOrdini(char* fileName, int* dim) {
	FILE* fp;
	Ordine* result = NULL;
	Ordine temp;
	int count;
	int lettura = 0;

	*dim = 0;

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		count = 0;
		 do {
			lettura = fscanf(fp, "%s %d", temp.ingrediente, &temp.num);
			if (lettura == 2);
			  count++;
		 } while (lettura == 2);
		if (count > 0) {
			result = (Ordine*)malloc(sizeof(Ordine) * count);
			rewind(fp);
			 do {
				if (result != NULL) {
					lettura = fscanf(fp, "%s %d", temp.ingrediente, &temp.num);
					if (lettura == 2) {
						result[*dim] = temp;
						(*dim)++;
					}
				}
			 } while (lettura == 2);
		}
		fclose(fp);
	}
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
		result = NULL;
	}

	return result;
}

void assign(Ordine* lvalue, Ordine rvalue)
{
	*lvalue = rvalue;
}
void swap(Ordine* a, Ordine* b)
{
	Ordine tmp = *a;
	*a = *b;
	*b = tmp;
}
int compare(Ordine e1, Ordine e2) {   //descrescente
	int result;
	result = e2.num - e1.num;
	if (result == 0) {
		result = strcmp(e1.ingrediente, e2.ingrediente);
	}
	return result;
}

void bubbleSort(Ordine* v, int size_v) {
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

void ordina(Ordine* v, int dim) {
	bubbleSort(v, dim);
}

int soddisfacibile(list paste, Ordine unOrdine) {
	int res;
	Pasta temp;
	char* comp;
	int count;

	count = 0;
	do {
		temp = head(paste);
		comp = strstr(temp.tipo, unOrdine.ingrediente);
		if (comp != NULL) {
			count++;
		}
		paste = tail(paste);
	} while (!empty(paste) && unOrdine.num != 0);

	if (count >= unOrdine.num)
		res = 1;
	else res = 0;

	return res;
}

list eseguiOrdine(list paste, Ordine unOrdine) {
	list res;
	Pasta temp;
	int esito;
	int count;

	res = emptyList();

	esito = soddisfacibile(paste, unOrdine);
	if (esito == 1) {
		count = unOrdine.num;
		do {
			temp = head(paste);
			if (strstr(temp.tipo, unOrdine.ingrediente) == NULL)
				res = cons(temp, res);
			else 
				count--;
			paste = tail(paste);
		} while (!empty(paste) && count > 0);
	}
	while (!empty(paste)) {					//aggiunge gli articoli non "eliminati" dalla lista di partenza
		res = cons(head(paste), res);
		paste = tail(paste);
	}

	return res;
}


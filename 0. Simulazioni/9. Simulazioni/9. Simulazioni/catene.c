#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "catene.h"


Catena leggiUno(FILE* fp) {
	Catena res;
	int lettura = 0;
	int i;

	lettura = fscanf(fp, "%d %d %f", &res.diametro, &res.larghezza, &res.prezzo);
	if (lettura == 3) {
		i = 0;
		char ch = fgetc(fp);
		while (ch != '\n' && i < (DIM - 1) && ch != EOF) {
			res.azienda[i] = ch;
			i++;
			ch = fgetc(fp);
		}
		res.azienda[i] = '\0';
		lettura++;
	}

	if (lettura != 4) {
		res.diametro = 0;
		res.larghezza = 0;
		res.prezzo = 0;
		strcpy(res.azienda, "\0");
	}

	return res;
}

Catena* leggiTutte(char* fileName, int* dim) {
	FILE* fp;
	Catena* result = NULL;
	Catena temp;
	int count;
	int lettura = 0;

	*dim = 0;

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		count = 0;
		do {
			temp = leggiUno(fp);
			if (temp.diametro != 0);
			count++;
		} while (temp.diametro != 0);
		if (count > 0) {
			result = (Catena*)malloc(sizeof(Catena) * count);
			rewind(fp);
			do {
				if (result != NULL) {
					temp = leggiUno(fp);
					if (temp.diametro != 0) {
						result[*dim] = temp;
						(*dim)++;
					}
				}
			} while (temp.diametro != 0);
		}
		fclose(fp);
	}
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
		result = NULL;
	}
	return result;
}

void stampa(Catena* v, int dim) {
	if (dim <= 0)
		return;
	else {
		printf("%d %d %.2f %s\n", v[dim - 1].diametro, v[dim - 1].larghezza, v[dim - 1].prezzo, v[dim - 1].azienda);
		stampa(v, dim - 1);
	}
}


void assign(Catena* lvalue, Catena rvalue)
{
	*lvalue = rvalue;
}
void swap(Catena* e1, Catena* e2)
{
	Catena tmp;
	assign(&tmp, *e1);
	assign(e1, *e2);
	assign(e2, tmp);
}
int compare(Catena e1, Catena e2) {
	int result;
	result = e2.diametro - e1.diametro;
	if (result == 0) {
		result = e2.larghezza - e1.larghezza;
		if (result == 0) {
			if (e2.prezzo < e1.prezzo) result = -1;
			else
				if (e2.prezzo > e1.prezzo) result = 1;
				else result = 0;
			if (result == 0)
				result = strcmp(e1.azienda, e2.azienda);
		}
	}
	return result;
}

void naiveSort(Catena* a, int dim) {
	int j, i, posmin;
	Catena min;

	for (j = 0; j < dim; j++) {
		posmin = j;
		for (assign(&min, a[j]), i = j + 1; i < dim; i++) {
			if (compare(a[i], min) > 0) {
				posmin = i;
				assign(&min, a[i]);
			}
		}
		if (posmin != j)
			swap(&a[j], &a[posmin]);
	}
}
void ordina(Catena* v, int dim) {
	naiveSort(v, dim);
}

list conta(Catena* v, int dim) {
	list result = emptyList();
	int i = 0;

	Prodotto temp;

	ordina(v, dim);

	if (dim > 0) {
		temp.prod = v[i];
		temp.dim = 1;
		for (i = 1; i < dim; i++) {
			if (compare(v[i], temp.prod) == 0)
				temp.dim = temp.dim + 1;
			else {
				result = cons(temp, result);
				temp.prod = v[i];
				temp.dim = 1;
			}
		}
		result = cons(temp, result);
	}
	return result;
}

int compatibili(int diametro, int larghezza, Catena c1) {
	if (diametro >= c1.diametro
		&& diametro <= c1.diametro * 1.1
		&& larghezza >= c1.larghezza
		&& larghezza <= c1.larghezza * 1.1)
		return 1;
	else
		return 0;
}
list filtra(int diametro, int larg, list disponibili) {
	list res1;
	Prodotto temp;

	res1 = emptyList();

	if (!empty(disponibili)) {
		while (!empty(disponibili)) {
			temp = head(disponibili);
			if (compatibili(diametro, larg, temp.prod)) {
				res1 = insord(temp, res1);
			}
			disponibili = tail(disponibili);
		}
	}
	return res1;

}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "noleggio.h"


Veicolo leggiVeicolo(FILE* fp) {
	Veicolo res;
	int lettura = 0;

	lettura = fscanf(fp, "%d %s %f %f %f", &res.id, res.tipo, &res.km, &res.latit, &res.longit);

	if (lettura != 5)
		res.id = -1;

	return res;

}

Veicolo* leggiTuttiVeicoli(char* fileName, int* dim) {
	FILE* fp;
	Veicolo* result = NULL;
	Veicolo temp;
	int count;
	int lettura = 0;

	*dim = 0;

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		count = 0;
		do {
			temp = leggiVeicolo(fp);
			if (temp.id > -1);
			count++;
		} while (temp.id > -1);
		if (count > 0) {
			result = (Veicolo*)malloc(sizeof(Veicolo) * count);
			rewind(fp);
			do {
				if (result != NULL) {
					temp = leggiVeicolo(fp);
					if (temp.id > -1) {
						result[*dim] = temp;
						(*dim)++;
					}
				}
			} while (temp.id > -1);
		}
		fclose(fp);
	}
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
		result = NULL;
	}
	return result;

}

list leggiMovimenti(char* fileName) {
	list result;
	FILE* fp;
	Movimenti temp;
	int lettura = 0;
	int i;
	char ch;

	result = emptyList();

	fp = fopen(fileName, "rt");

	if (fp == NULL)
		return result;
	else {
		do {
			lettura = fscanf(fp, "%d;%c;%f;%f", &temp.id, &temp.p_r, &temp.latit, &temp.longit);
			if (lettura == 4) {
				ch = fgetc(fp);
				i = 0;
				ch = fgetc(fp);
				while (ch != '\n' && i < (DIM - 1) && ch != EOF) {
					temp.cliente[i] = ch;
					i++;
					ch = fgetc(fp);
				}
				temp.cliente[i] = '\0';
				lettura++;
				result = cons(temp, result);
			}
		} while (lettura == 5);
		fclose(fp);
	}

	return result;
}

int disponibile(list movimenti, int idveicolo) {
	int trovato = 0;
	Movimenti temp;

	if (!empty(movimenti)) {
		while (!empty(movimenti)) {
			temp = head(movimenti);
			if (temp.id == idveicolo) {
				if (temp.p_r != 'P')
					trovato = 1;
				else trovato = 0;
			}
			movimenti = tail(movimenti);
		}
	}
	else
		trovato = 0;

	return trovato;
}

void posizione(list movimenti, Veicolo veicolo, float* lat, float* lon) {
	Movimenti temp;
	int disp = 0;
	int match = 0;

	disp = disponibile(movimenti, veicolo.id);
	if (!empty(movimenti) && disp) {
		while (!empty(movimenti) && !match) {
			temp = head(movimenti);
			if (temp.id == veicolo.id) {
				*lat = temp.latit;
				*lon = temp.longit;
				match = 1;
			}
			else
				movimenti = tail(movimenti);
		}
	}
	else {
		*lat = veicolo.latit;
		*lon = veicolo.longit;
	}
	return;
}



void assign(Veicolo* lvalue, Veicolo rvalue)
{
	*lvalue = rvalue;
}
void swap(Veicolo* e1, Veicolo* e2)
{
	Veicolo tmp;
	assign(&tmp, *e1);
	assign(e1, *e2);
	assign(e2, tmp);
}
int compare(Veicolo e1, Veicolo e2, float lat, float lon) {
	int result;
	double dist1, dist2;
	dist1 = pow((double) e1.latit - lat, 2) + pow((double)e1.longit - lon, 2);
	dist2 = pow((double) e2.latit - lat, 2) + pow((double)e2.longit - lon, 2);

	if (dist1 > dist2)
		result = 1;
	else if (dist1 < dist2)
		result = -1;
	else result = 0;

	return result;
}

void naiveSort(Veicolo* a, int dim, float lat, float lon) {
	int j, i, posmin;
	Veicolo min;

	for (j = 0; j < dim; j++) {
		posmin = j;
		for (assign(&min, a[j]), i = j + 1; i < dim; i++) {
			if (compare(a[i], min, lat, lon) > 0) {
				posmin = i;
				assign(&min, a[i]);
			}
		}
		if (posmin != j)
			swap(&a[j], &a[posmin]);
	}
}

void ordina(Veicolo* veicoli, int dim, float lat, float lon) {
	naiveSort(veicoli, dim, lat, lon);
}

Veicolo cerca(Veicolo* veicoli, int dim, list movimenti, float lat, float lon) {
	Veicolo res;
	int i;
	double dist;
	int trovato = 0;

	ordina(veicoli, dim, lat, lon);

	res.id = -1;

	for (i = 0; i < dim && !trovato; i++) {
		trovato = disponibile(movimenti, veicoli[i].id);
		if (trovato) {
			dist = pow((double)veicoli[i].latit - lat, 2) + pow((double)veicoli[i].longit - lon, 2);
			if (dist <= 0)
				res = veicoli[i];
		}
	}

	if (!trovato)
		res.id = -1;

	return res;
}

Veicolo cerca(Veicolo* veicoli, int dim, list movimenti, float lat, float lon) { //versione del prof
	Veicolo v;
	ordina(veicoli, dim, lat, lon);
	for (int i = 0; i < dim; i++) {
		if (disponibile(movimenti, veicoli[i].id))
			return veicoli[i];
	}
	v.id = -1;
	return v;
}



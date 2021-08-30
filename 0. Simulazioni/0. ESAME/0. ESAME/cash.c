// Allegretti Alessandro - Matricola: 0000974745 - MODULO 2

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cash.h"

//ESERCIZIO 1
Operazione* leggiTutteOperazioni(char* fileName, int* dim) {
	FILE* fp;
	Operazione* result = NULL;
	Operazione temp;
	int count;


	*dim = 0;

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		count = 0;
		while (fscanf(fp, "%d %f %s", &temp.id, &temp.importo, temp.negozio) == 3) {
			count++;
		}
		if (count > 0) {
			result = (Operazione*)malloc(sizeof(Operazione) * count);
			rewind(fp);
			if (result != NULL) {
				while (fscanf(fp, "%d %f %s", &temp.id, &temp.importo, temp.negozio) == 3) {
					result[*dim] = temp;
					(*dim)++;
				}
			}
		}
		fclose(fp);
	}

	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
		result = NULL;
		*dim = 0;
	}
	return result;

}

list leggiNegozi(char* fileName) {
	FILE* fp;
	list result = emptyList();
	Negozio temp;

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		while (fscanf(fp, "%s %c", temp.nome, &temp.tipo) == 2) {
			result = cons(temp, result);
		}
		fclose(fp);
	}

	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
		result = emptyList();
	}
	return result;

}

void stampaOperazioni(Operazione* v, int dim) {
	if (dim <= 0)
		return;
	else {
		printf("ID: %d \tImporto: %.2f \tNome: %s\n", v[dim - 1].id, v[dim - 1].importo, v[dim - 1].negozio);
		stampaOperazioni(v, dim - 1);
	}
}


//ESERCIZIO 2
void assign(Operazione* lvalue, Operazione rvalue)
{
	*lvalue = rvalue;
}
void swap(Operazione* e1, Operazione* e2)
{
	Operazione tmp;
	assign(&tmp, *e1);
	assign(e1, *e2);
	assign(e2, tmp);
}
float compare(Operazione e1, Operazione e2) {
	float result;
	result = (float) e2.id - e1.id;
	if (result == 0) {
		result = e2.importo - e1.importo;
		if (e2.importo < e1.importo) 
			result = -1;
		else if (e2.importo > e1.importo)
			result = 1;	
		else result = 0;
	}
	return result;
}

void naiveSort(Operazione* a, int dim) {
	int j, i, posmin;
	Operazione min;

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
void ordina(Operazione* v, int dim) {
	naiveSort(v, dim);
}


int negozioFisico(char* nomeNegozio, list negozi) {
	Negozio temp;
	int comp;
	int trovato = 0;

	while (!empty(negozi) && !trovato) {
		temp = head(negozi);
		comp = strcmp(temp.nome, nomeNegozio);
		if (comp == 0 && temp.tipo == 'F')
			trovato = 1;
		else trovato = 0;
		negozi = tail(negozi);
	}
	return trovato;
}

Operazione* filtra(Operazione* v, int dim, list negozi, int* dimLog) {
	Operazione* result;
	int comp, i;
	list temp;
	
	temp = negozi;
	*dimLog = 0;

	if (dim > 0) {
		result = (Operazione*)malloc(sizeof(Operazione) * dim);
		for (i = 0; i < dim; i++) {
			comp = negozioFisico(v[i].negozio, temp);
			if (comp && result != NULL) {
				result[*dimLog] = v[i];
				(*dimLog)++;
			}
		}
	}
	else result = NULL;

	return result;
}



//ESERCIZIO 3
float spesaCliente(int idCliente, Operazione* v, int dim) {
	float res;
	int i;

	res = 0.0;
	for (i = 0; i < dim; i++) {
		if (v[i].id == idCliente)
			res = res + v[i].importo;
	}

	return res;
}










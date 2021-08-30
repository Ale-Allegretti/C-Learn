#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "palazzo.h"

Appartamento leggiUnAppartamento(FILE* fp) {
	Appartamento result;
	int lettura1, lettura2;
	float temp;
	int i = 0;

	lettura1 = fscanf(fp, "%d %c %f %d %d", &result.id, &result.tipo, &result.mq, &result.piano, &result.vani);
	if (lettura1 == 5) {
		do {
			lettura2 = fscanf(fp, "%f ", &temp);
			if (lettura2 == 1) {
				result.calp[i] = temp;
				i++;
			}
			else result.id = -1;
		} while (i < result.vani && result.id != -1);
	}
	else result.id = -1;
	
	return result;
}

list leggiTuttiAppartamenti(char* fileName) {
	FILE* fp;
	list result;
	Appartamento temp;

	result = emptyList();

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		do { 
			temp = leggiUnAppartamento(fp);
			if (temp.id >= 0) 
				result = cons(temp, result);
		} while (temp.id >= 0);
		fclose(fp);
	}
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
	}

	return result;
}

void assign(Appartamento* lvalue, Appartamento rvalue)
{
	*lvalue = rvalue;
}
void swap(Appartamento* a, Appartamento* b)
{
	Appartamento tmp = *a;
	*a = *b;
	*b = tmp;
}
int compare(Appartamento e1, Appartamento e2) {   //descrescente
	int result;
	result = e2.piano - e1.piano;
	if (result == 0) {
		if (e1.mq > e2.mq)
			result = -1;
		else
			if (e1.mq < e2.mq)
				result = 1;
			else result = 0;
	}
	return result;
}

void bubbleSort(Appartamento* v, int size_v) {
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

Appartamento* trovaAppartamento(list appartamenti, int pianoMin, float mqMin, int* dim) {
	Appartamento* res;
	Appartamento temp;
	int count = 0;
	list tempApp = appartamenti;
	
	while (!empty(tempApp)) {
		temp = head(tempApp);
		if (temp.piano >= pianoMin && temp.mq >= mqMin)
			count++;
		tempApp = tail(tempApp);
	}
	if (count > 0) {
		res = (Appartamento*)malloc(sizeof(Appartamento) * count);
		*dim = 0;
		while (!empty(appartamenti)) {
			temp = head(appartamenti);
			if (temp.piano >= pianoMin && temp.mq >= mqMin) {
				res[*dim] = temp;
				(*dim)++;
			}
			appartamenti = tail(appartamenti);
		}
	}
	else {
		res = NULL;
		*dim = 0;
	}

	return res;
}

int readField(char buffer[], int dim_buffer, char sep, FILE* f)
{
	int i = 0;
	char ch = fgetc(f);
	do {                         //ciclo che scarta caratteri fino al sep
		ch = fgetc(f);
	} while (ch != '"');
	if (ch == sep) {
		ch = fgetc(f);
		while (ch != sep && ch != '\n' && i < (dim_buffer - 1) && ch != EOF) {
			buffer[i] = ch;
			i++;
			ch = fgetc(f);
		}
	}
	buffer[i] = '\0';

	return ch;
}
Offerta leggiUnOfferta(FILE* fp) {
	Offerta result;
	int lettura1, lettura2;
	char sep;

	lettura1 = fscanf(fp, "%d", &result.id);			
	if (lettura1 == 1) {
		sep = readField(result.nom_cog, DIM, '"', fp);
		if (sep == '"') {
			lettura2 = fscanf(fp, "%f", &result.offerta);
			if (lettura2 != 1)
				result.id = -1;
		}
		else result.id = -1;
	}
	else result.id = -1;

	return result;
}

int registraOfferta(int idAppartamento, char* cliente, float importo) {
	FILE* fp;
	Offerta prev;
	int stessoCliente = 0;
	int offertaPiuAlta = 0;
	int result = 0;

	if ((fp = fopen("offerte", "rt")) != NULL) {
		prev = leggiUnOfferta(fp);
		while (!stessoCliente && prev.id != -1) {
			// caso 1
			if (strcmp(cliente, prev.nom_cog) == 0 && idAppartamento == prev.id) {
				stessoCliente = 1;
			}
			// caso 2
			if (prev.id == idAppartamento && prev.offerta >= importo) {
				offertaPiuAlta = 1;
			}
			if (!stessoCliente)
				prev = leggiUnOfferta(fp);
		}
		fclose(fp);
		// caso 1:
		if (stessoCliente) {
			printf("ERRORE: %s ha gia' fatto un'offerta per l'app %d.\n", cliente, idAppartamento);
			result = -3;
		}
		// caso 2:
		if (!stessoCliente && offertaPiuAlta) {
			printf("Esiste almeno un'offerta piu' alta...\n");
			result = -5;
		}
		// caso 3:
		if (!stessoCliente && !offertaPiuAlta) {
			if ((fp = fopen("offerte", "wt")) != NULL) {
				fprintf(fp, "%d \"%s\" %f\n", idAppartamento, cliente, importo);
				fclose(fp);
			}
			result = 0;
		}
	}
	return result;
}






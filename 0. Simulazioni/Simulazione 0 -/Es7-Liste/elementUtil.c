#define _CRT_SECURE_NO_WARNINGS
#include "elementUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printElement(Element el) {
	int i;
	printf("Matricola\tNome\tCognome\tN.ro Esami\tVoti\n");
	printf("%s\t%s\t%s\t%d\t", el.matricola, el.nome, el.cognome, el.nro_voti);
	for (i = 0; i < el.nro_voti; i++) {
		printf("%d\t", el.voti[i]);
		if (i < el.nro_voti - 1)
			printf(" ");
	}
}
void showList2(list l) {
	/* VERSIONE ITERATIVA: */
	while (!empty(l)) {
		printElement(head(l));
		printf("\n");
		l = tail(l);
	}
}


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
int readElementFromFile(FILE* fp, Element* dest) {
	int result = OK;
	int i;
	char sepRead;
	int lettura1, lettura2;

	sepRead = readField(dest->matricola, 15, ';', fp);
	if (sepRead == ';' && result == OK)
		sepRead = readField(dest->cognome, 64, ';', fp);
	else result = OK;
	if (sepRead == ';' && result == OK)
		sepRead = readField(dest->nome, 64, ';', fp);
	else result = ERROR;
	if (sepRead == ';' && result == OK) {
		lettura1 = fscanf(fp, "%d", &(dest->nro_voti));
		dest->voti = (int*)malloc(sizeof(int) * dest->nro_voti);
		if (dest->voti != NULL) {
			for (i = 0; i < dest->nro_voti && result == OK; i++) {
				lettura2 = fscanf(fp, "%d", &((dest->voti)[i]));
				if (lettura2 != 1)
					result = ERROR;
			}
		}
		if (result == OK)
			fgetc(fp);
	}
	else result = ERROR;

	return result;
}


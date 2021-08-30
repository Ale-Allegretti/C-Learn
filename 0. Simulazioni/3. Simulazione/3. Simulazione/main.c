#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "metro.h"

int main() {
	Evento e;
	Tariffa* t;
	FILE* fp;
	list l;
	int i, size;

	fp = fopen("eventi.txt", "rt");
	if (fp == NULL) {
		printf("Errore di apertura del file");
		exit(-1);
	}
	
	e = leggiUno(fp);
	printEvento(e);

	printf("\n \n");

	l = leggiTutti("eventi.txt");

	
	
	t = leggiTariffe("tariffe.txt", &size);

	for (i = 0; i < size; i++) {
		printf("%s\t%s\t%.2f\n", t[i].s_ing, t[i].s_usc, t[i].costo);
	}
	printf("\n\n");

	ordina(t, size);

	for (i = 0; i < size; i++) {
		printf("%s\t%s\t%.2f\n", t[i].s_ing, t[i].s_usc, t[i].costo);
	}

	return 0;
}
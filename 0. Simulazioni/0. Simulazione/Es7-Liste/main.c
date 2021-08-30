#define _CRT_SECURE_NO_WARNINGS

#include "elementUtil.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	FILE* fp;
	list elenco = emptyList();
	list elenco_ord = emptyList();
	list temp;
	Element dest;
	int lettura = OK;

	fp = fopen("elenco.txt", "r");
	if (fp == NULL) {
		printf("Errore di apertura dei file");
		exit(-1);
	}
	do {
		lettura = readElementFromFile(fp, &dest);
		if (lettura == OK)
			elenco = cons(dest, elenco);
	} while (lettura == OK);

	showList2(elenco);
	fclose(fp);
	printf("\n \n");
	elenco_ord = eliminaRipetuti(elenco);
	showList2(elenco_ord);
	
	while (!empty(elenco_ord)) {
		temp = tail(elenco_ord);
		free(elenco_ord);
		elenco_ord = temp;
	}
	while (!empty(elenco)) {
		temp = tail(elenco);
		free(head(elenco).voti);
		free(elenco);
		elenco = temp;
	}

	return 0;
}
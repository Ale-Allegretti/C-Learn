#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "banca.h"


int main() {
	FILE* fp;
	Loan prest;
	Loan* eff;
	int size, i;
	list search = emptyList();
	
	fp = fopen("prestiti.txt", "rt");
	if (fp == NULL) {
		printf("Errore nell'apertura del file");
		exit(-1);
	}

	prest = leggiUnLoan(fp);
	printf("%d %s %s %.2f\n\n", prest.id, prest.cognome, prest.nome, prest.importo);

	eff = leggiLoanAttivi("prestiti.txt", &size);

	for (i = 0; i < size; i++) {
		printf("%d %s %s %.2f\n", eff[i].id, eff[i].cognome, eff[i].nome, eff[i].importo);
	}

	printf("\n\n");
	ordina(eff, size);

	for (i = 0; i < size; i++) {
		printf("%d %s %s %.2f\n", eff[i].id, eff[i].cognome, eff[i].nome, eff[i].importo);
	}

	printf("\n\n");

	search = estrai(eff, size, "Chesani Mazzanti", "Federico Domenico Maria");

	showList2(search);

	printf("\n\n");

	espo(eff, size);

	fclose(fp);
	freelist(search);
	free(eff);

	return 0;
}

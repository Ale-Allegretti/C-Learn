#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "element.h"
#include "palazzo.h"


int main() {
	FILE* fp,* fo;
	Appartamento app;
	Appartamento* res;
	Offerta off1;
	list listApp;
	int i, j, size;
	
	fp = fopen("palazzo.txt", "rt");
	if (fp == NULL) {
		printf("Errore nell'apertura del file");
		exit(-1);
	}
	app = leggiUnAppartamento(fp);

	printf("%d %c %.2f %d %d ", app.id, app.tipo, app.mq, app.piano, app.vani);
	for (i = 0; i < app.vani; i++)
		printf("%.2f ", app.calp[i]);
	printf("\n\n");

	fclose(fp);

	listApp = leggiTuttiAppartamenti("palazzo.txt");

	showList(listApp);

	printf("\n\n");

	res = trovaAppartamento(listApp, 3, 30.0, &size);

	bubbleSort(res, size);

	for (i = 0; i < size; i++) {
		printf("%d %c %.2f %d %d ", res[i].id, res[i].tipo, res[i].mq, res[i].piano, res[i].vani);
		for (j = 0; j < res[i].vani; j++)
			printf("%.2f ", res[i].calp[j]);
		printf("\n\n");
	}

	fo = fopen("offerte.txt", "rt");
	if (fo == NULL) {
		printf("Errore nell'apertura del file");
		exit(-1);
	}

	off1 = leggiUnOfferta(fo);

	printf("\n\n");
	printf("%d %s %.2f", off1.id, off1.nom_cog, off1.offerta);

	fclose(fo);




	printf("Specificare id, nome cliente (tra doppie virgolette) e valore dell'offerta:\n");
	scanf_s("%d", &idApp);
	do {
		ch = getchar();
	} while (ch != '"');
	i = 0;
	ch = getchar();
	while (ch != '"' && i < DIM_NOME - 1) {
		nomeCliente[i] = ch;
		i++;
		ch = getchar();
	}
	nomeCliente[i] = '\0';
	scanf_s("%f", &(valoreOfferta));
	registraOfferta("offerte.txt", idApp, nomeCliente, valoreOfferta);




										//Chiudere file
	freelist(listApp);					//Svuotare liste
	free(res);						//Liberare allocamenti memoria

	return 0;
}

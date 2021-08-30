#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "element.h"
#include "bar.h"


int main() {
	//FILE* fp;
	list past, pastAgg, temp;
	Ordine* ord;
	int i, size;
	int res;

	past = emptyList();
	pastAgg = emptyList();
	temp = emptyList();
	past = leggiPaste("paste.txt");

	showList(past);
	printf("\n\n");

	ord = leggiOrdini("ordini.txt", &size);

	for (i = 0; i < size; i++)
		printf("Ingredienti: %s\tNumero: %d\n", ord[i].ingrediente, ord[i].num);

	printf("\n\n");
	ordina(ord, size);
	for (i = 0; i < size; i++)
		printf("Ingredienti: %s\tNumero: %d\n", ord[i].ingrediente, ord[i].num);

	printf("\n\n");

	{ // Es. 3 && 4
		list banco;
		list bancoAggiornato;
		list temp;
		Ordine* gliOrdini;
		int dim;
		int i;
		gliOrdini = leggiOrdini("ordini.txt", &dim);
		ordina(gliOrdini, dim);
		banco = leggiPaste("paste.txt");
		bancoAggiornato = banco;
		printf("\n\n");
		for (i = 0; i < dim; i++) {
			if (soddisfacibile(bancoAggiornato, gliOrdini[i])) {
				printf("L'ordine (%s %d), e' soddisfacibile\n", gliOrdini[i].ingrediente, gliOrdini[i].num);
				temp = bancoAggiornato;
				bancoAggiornato = eseguiOrdine(bancoAggiornato, gliOrdini[i]);
				if (temp != banco)
					freelist(temp);
			}
			else
				printf("L'ordine (%s %d), NON e' soddisfacibile\n", gliOrdini[i].ingrediente, gliOrdini[i].num);
		}
		printf("\n\nDopo aver soddisfatto alcuni ordini, il banco ha le seguenti paste:\n");
		showList(bancoAggiornato);


		freelist(banco);
		freelist(bancoAggiornato);
		free(gliOrdini);
	}

	return 0;
}

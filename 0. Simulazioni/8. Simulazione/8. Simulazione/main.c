#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "element.h"
#include "bar.h"


int main() {
	{ //Esercizio 1
		Ingrediente* ingredienti;
		Ingrediente search;
		int i, size;

		ingredienti = leggiIng("ingredienti.txt", &size);

		for(i = 0; i < size; i++)
			printf("Nome:%20s\t\tQuantita': %d\t\tCosto: %.2f\n", ingredienti[i].nome, ingredienti[i].quant, ingredienti[i].costo);
		printf("\n\n");

		printf("Nome:\t\tQuantita':\t\tCosto:\n");
		stampa(ingredienti, size-1);

		printf("\n\n");

		search = trova(ingredienti, size, "speck");

		printf("%s %d %.2f", search.nome, search.quant, search.costo);

		printf("\n\n");
		//fclose(fp);					//Chiudere file
		//freelist();					//Svuotare liste
		free(ingredienti);						//Liberare allocamenti memoria
	}

	{ //Esercizio 2
		Ingrediente* ingredienti;
		list panini;
		int i, size;

		ingredienti = leggiIng("ingredienti.txt", &size);
		ordina(ingredienti, size);

		for (i = 0; i < size; i++)
			printf("Nome:%20s\t\tQuantita': %d\t\tCosto: %.2f\n", ingredienti[i].nome, ingredienti[i].quant, ingredienti[i].costo);
		printf("\n\n");

		panini = emptyList();
		printf("Ordine Panini: \n");
		panini = leggiPanini("panini.txt", ingredienti, size);
		
		showList(panini);
		printf("\n\n");

		freelist(panini);
		free(ingredienti);
	}

	{ // Es. 3 && 4
		Ingrediente* elenco;
		int dim;
		list panini;
		list paniniSenzaRip;

		elenco = leggiIng("ingredienti.txt", &dim);
		panini = leggiPanini("panini.txt", elenco, dim);

		paniniSenzaRip = eliminaDup(panini);
		showList(paniniSenzaRip);

		free(elenco);
		freelist(panini);
		freelist(paniniSenzaRip);
	}







	return 0;
}

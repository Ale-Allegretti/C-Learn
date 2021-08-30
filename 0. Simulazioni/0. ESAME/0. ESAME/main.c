// Allegretti Alessandro - Matricola: 0000974745 - MODULO 2

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "element.h"
#include "cash.h"


int main() {
	{	//Esercizio 1
		Operazione* operazioni;
		list negozi;
		int i, size;

		operazioni = leggiTutteOperazioni("operazioni.txt", &size);

		for(i = 0; i < size; i++)
			printf("%d %.2f %s\n", operazioni[i].id, operazioni[i].importo, operazioni[i].negozio);
	
		printf("\n\n");

		negozi = emptyList();

		negozi = leggiNegozi("negozi.txt");

		showList(negozi);

		printf("\n\n");

		stampaOperazioni(operazioni, size);

						
		freelist(negozi);					
		free(operazioni);
	}

	{	//Esercizio 2
		Operazione* operazioni;
		Operazione* filtrate;
		int i, size1, size2;
		list negozi = emptyList();

		negozi = leggiNegozi("negozi.txt");

		operazioni = leggiTutteOperazioni("operazioni.txt", &size1);
	
		ordina(operazioni, size1);

		printf("\n\n");
		for (i = 0; i < size1; i++)
			printf("%d %.2f %s\n", operazioni[i].id, operazioni[i].importo, operazioni[i].negozio);

		filtrate = filtra(operazioni, size1, negozi, &size2);

		printf("\n\n");

		for (i = 0; i < size2; i++)
			printf("%d %.2f %s\n", filtrate[i].id, filtrate[i].importo, filtrate[i].negozio);

							
		freelist(negozi);
		free(filtrate);
		free(operazioni);
	}

	{	//Esercizio 3
		Operazione* operazioni;
		int size;
		int id;
		float totale;

		operazioni = leggiTutteOperazioni("operazioni.txt", &size);

		printf("\n");
		printf("Inserire l'ID del cliente per conoscere la sua spesa totale: ");
		scanf_s("%d", &id);

		totale = spesaCliente(id, operazioni, size);
		printf("\n");
		printf("La spesa totale del cliente %d ammonta a: %.2f", id, totale);
		printf("\n\n");

		//fclose(fp);					
		//freelist();					
		free(operazioni);
	}

	{	//Esercizio 4
		Operazione* operazioni;
		Operazione* filtrate;
		int i, size1, size2;
		list negozi = emptyList();

		negozi = leggiNegozi("negozi.txt");

		operazioni = leggiTutteOperazioni("operazioni.txt", &size1);

		ordina(operazioni, size1);

		filtrate = filtra(operazioni, size1, negozi, &size2);

		printf("\n\n");
		printf("Lista di spese totali da negozi fisici: \n");
		for (i = 0; i < size2; i++) {
			while (filtrate[i].id == filtrate[i + 1].id)
				i++;
			printf("La spesa del cliente %d ammonta a %.2f\n", filtrate[i].id, spesaCliente(filtrate[i].id, filtrate, size2));
		}
		printf("\n");

		freelist(negozi);
		free(filtrate);
		free(operazioni);
	}
	
	
	return 0;
}

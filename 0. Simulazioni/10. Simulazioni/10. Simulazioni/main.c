#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "element.h"
#include "noleggio.h"


int main() {
	{	//Esercizio 1
		FILE* fp;
		Veicolo sing;
		Veicolo* multi;
		int i, size;



		fp = fopen("veicoli.txt", "rt");
		if (fp == NULL) {
			printf("Errore nell'apertura del file");
			exit(-1);
		}

		sing = leggiVeicolo(fp);
		printf("%d %s %.2f %.2f %.2f", sing.id, sing.tipo, sing.km, sing.latit, sing.longit);

		printf("\n\n");

		multi = leggiTuttiVeicoli("veicoli.txt", &size);

		for(i = 0; i < size; i++)
			printf("%d %s %.2f %.2f %.2f\n", multi[i].id, multi[i].tipo, multi[i].km, multi[i].latit, multi[i].longit);


		fclose(fp);					
		//freelist();					
		free(multi);
	}

	{	//Esercizio 2

		list movi;
		Veicolo* multi;
		int size;
		float lat, lon; 

		movi = emptyList();

		movi = leggiMovimenti("movimenti.txt");

		printf("\n\n");
		showList(movi);

		multi = leggiTuttiVeicoli("veicoli.txt", &size);

		posizione(movi, multi[3], &lat, &lon);

		printf("\n\n");
		printf("Il veicolo si trova alla latitudine %.2f e alla longitudine %.2f\n", lat, lon);
	

		//fclose(fp);					
		freelist(movi);					
		free(multi);
	}

	{	//Esercizio 3-4
		Veicolo* multi;
		Veicolo search;
		int i, size;
		float lat, lon;
		list movi;

		movi = emptyList();

		multi = leggiTuttiVeicoli("veicoli.txt", &size);
		printf("\n\n");
		for (i = 0; i < size; i++)
			printf("%d %s %.2f %.2f %.2f\n", multi[i].id, multi[i].tipo, multi[i].km, multi[i].latit, multi[i].longit);
	
		printf("\n\n");

		ordina(multi, size, 2000.0, 3500.0);

		for (i = 0; i < size; i++)
			printf("%d %s %.2f %.2f %.2f\n", multi[i].id, multi[i].tipo, multi[i].km, multi[i].latit, multi[i].longit);

		printf("\n\n");

		movi = leggiMovimenti("movimenti.txt");

		printf("Inserire longitudine e latitudine della propria posizione: ");
		scanf_s("%f %f", &lat, &lon);

		search = cerca(multi, size, movi, lat, lon);

		printf("\n\n");
		if (search.id == -1)
			printf("Nessun veicolo trovato in zona.");
		else {
			printf("Il veicolo più vicino e':\n");
			printf("%d %s %.2f %.2f %.2f", search.id, search.tipo, search.km, search.latit, search.longit);

		}

		//fclose(fp);					
		freelist(movi);
		free(multi);
	}
	
	
	return 0;
}

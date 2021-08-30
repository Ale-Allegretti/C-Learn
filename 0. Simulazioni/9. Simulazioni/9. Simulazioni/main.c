#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "element.h"
#include "catene.h"


int main() {
	{	//Esercizio 1
		FILE* fp;
		Catena cate1;
		Catena* catene;
		int i, size;

		fp = fopen("catene.txt", "rt");
		if (fp == NULL) {
			printf("Errore nell'apertura del file");
			exit(-1);
		}

		cate1 = leggiUno(fp);

		printf("%d %d %.2f %s", cate1.diametro, cate1.larghezza, cate1.prezzo, cate1.azienda);
		printf("\n\n");

		catene = leggiTutte("catene.txt", &size);

		for (i = 0; i < size; i++)
			printf("%d %d %.2f %s\n", catene[i].diametro, catene[i].larghezza, catene[i].prezzo, catene[i].azienda);

		//stampa(catene, size);



		fclose(fp);					
		//freelist();					
		free(catene);
	}

	{	//Esercizio 2
		Catena* catene;
		int i, size;

		catene = leggiTutte("catene.txt", &size);

		ordina(catene, size);

		printf("\n\n");
		for (i = 0; i < size; i++)
			printf("%d %d %.2f %s\n", catene[i].diametro, catene[i].larghezza, catene[i].prezzo, catene[i].azienda);
	

		//fclose(fp);					
		//freelist();					
		free(catene);
	}

	{	//Esercizio 3-4+

		Catena* catene;
		int size;
		list counter, ask;

		counter = emptyList();
		ask = emptyList();

		catene = leggiTutte("catene.txt", &size);
		ordina(catene, size);

		counter = conta(catene, size);

		printf("\n\n");
		showList(counter);
		
		printf("\n\n");

		ask = filtra(65, 160, counter);
		showList(ask);
		printf("\n\n");





		//fclose(fp);					
		freelist(counter);
		freelist(ask);
		free(catene);
	}
	
	
	return 0;
}

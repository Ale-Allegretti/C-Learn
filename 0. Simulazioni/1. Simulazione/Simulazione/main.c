#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "ordini.h"


int main(void) {
	list l;
	Pizza* p;
	int numPizze;
	int i;
	char* nome;
	double totale;

	l = leggiIngredienti("ingredienti.txt");
	l = aggiornaPrezzo(l, "salame_piccante", 2.00);
	scriviIngredienti("ingredienti.txt", l);

	p = leggiOrdini("ordini.bin", &numPizze);
	naiveSort(p, numPizze);

	for (i = 0; i < numPizze; )
	{
		totale = calcolaPrezzo(p[i], l);
		nome = p[i].nome;
		i++;
		while (strcmp(nome, p[i].nome) == 0)
		{
			totale = totale + calcolaPrezzo(p[i], l);
			i++;
		}
		printf("%s deve pagare %f euro\n", nome, totale);
	}
	
	return (0);
}
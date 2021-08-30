#include "ordini.h"

Pizza leggiPizza(FILE* fp) {
	Pizza result;
	if (!feof(fp))
	{
		fread(&result, sizeof(Pizza), 1, fp);
	}
	else {
		*(result.ing[0].nome) = 0;
		result.ing[0].prezzo = 0;
		*(result.nome) = 0;
		result.num = 0;
	}

	return result;
}

Pizza* leggiOrdini(char* fileName, int* tot_lette) {
	FILE* fp;
	Pizza* ordini;
	int temp;
	*tot_lette = 0;

	fp = fopen(fileName, "rb");
	if (fp == NULL) {
		printf("File ordini non trovato");
		exit(-1);
	}

	fread(&temp, sizeof(int), 1, fp);
	ordini = (Pizza*)malloc(sizeof(Pizza) * (*tot_lette));
	if ((sizeof(Pizza) * (*tot_lette)) != 0) {
		while (*tot_lette < temp) {
			ordini[*tot_lette] = leggiPizza(fp);
			(*tot_lette)++;
		}
	}
	fclose(fp);

	return ordini;
}


void assign(Pizza* lvalue, Pizza rvalue)
{
	*lvalue = rvalue;
}
void swap(Pizza* e1, Pizza* e2)
{
	Pizza tmp;
	assign(&tmp, *e1);
	assign(e1, *e2);
	assign(e2, tmp);
}
int compare(Pizza e1, Pizza e2)
{
	return strcmp(e1.nome, e2.nome);
}
void naiveSort(Pizza* a, int dim) {
	int j, i, posmin;
	Pizza min;

	for (j = 0; j < dim; j++) {
		posmin = j;
		for (assign(&min, a[j]), i = j + 1; i < dim; i++) {
			if (compare(a[i], min) < 0) {
				posmin = i;
				assign(&min, a[i]);
			}
		}
		if (posmin != j)
			swap(&a[j], &a[posmin]);
	}
}
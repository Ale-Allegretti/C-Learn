#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIM 3
#define NOME 21

typedef struct {
	char nome[NOME]; int neve;
} Stazione;

int compare(Stazione s1, Stazione s2) {
	if (s1.neve < s2.neve)
		return -1;
	else if (s1.neve == s2.neve)
		return 0;
	return 1;
}

void merge_S(Stazione v[], int i1, int i2, int fine, Stazione vout[]) {
	int i = i1, j = i2, k = i1;

	while (i <= i2 - 1 && j <= fine) {
		if (compare(v[i], v[j]) < 0)
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}
	while (i <= i2 - 1) { vout[k] = v[i++]; k++; }
	while (j <= fine) { vout[k] = v[j++]; k++; }
	for (i = i1; i <= fine; i++) v[i] = vout[i];
}
void mergeSort_S(Stazione v[], int first, int last, Stazione vout[]) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort_S(v, first, mid, vout);
		mergeSort_S(v, mid + 1, last, vout);
		merge_S(v, first, mid + 1, last, vout);
	}
}

int main(void) {
	Stazione stazione[MAX_DIM] = {' '};
	Stazione temp[MAX_DIM];
	
	int i;
	
	for (i = 0; i < MAX_DIM; i++) {
		printf("nome: ");
		scanf_s("%s", stazione[i].nome, NOME);
		printf("Neve: ");
		scanf_s("%d", &(stazione[i].neve));
	} 

	mergeSort_S(stazione, 0, (MAX_DIM - 1), temp);
	printf("\n");
	for (i = 0; i < MAX_DIM; i++)
		printf("%s: %d\n", stazione[i].nome, stazione[i].neve);

	return 0;
}
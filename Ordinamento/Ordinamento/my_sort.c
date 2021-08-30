
#include "my_sort.h"
#include <stdio.h>


void printArray(Array a, int dim)
{
	int i;
	printf("---VETTORE---\n");
	for (i = 0; i < dim; i++)
		printElement(a[i]);
	printf("-------------\n");
}

/*
void scambia(Element* a, Element* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int trovaPosMax(Array v, int size_v) {
	int i, posMax = 0;
	for (i = 1; i < size_v; i++)
		if (v[posMax] < v[i]) 
			posMax = i;
	return posMax;
}
*/

void naiveSort(Array a, int dim) {
	int j, i, posmin;
	Element min;

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



void bubbleSort(Array v, int size_v) {
	int i, ordinato = 0;
	while (size_v > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < size_v - 1; i++)
			if (compare(v[i], v[i + 1]) > 0) {
				swap(&v[i], &v[i + 1]);
				ordinato = 0;
			}
		size_v--;
	}
}


void insertSort(Array v, int size_v) {
	int k;
	for (k = 1; k < size_v; k++)
		insOrd(v, k);
}
void insOrd(Array v, int pos) {
	int i = pos - 1;
	Element x = v[pos];

	while (i >= 0 && compare(x, v[i]) < 0) {
		assign(&v[i + 1], v[i]); // crea lo spazio
		i--;
	}
	swap(&v[i + 1], &x); // inserisce l’elemento
}


void mergeSort(Array v, int first, int last, Array vout) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort(v, first, mid, vout);
		mergeSort(v, mid + 1, last, vout);
		merge(v, first, mid + 1, last, vout);
	}
}
void merge(Array v, int i1, int i2, int fine, Array vout) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (compare(v[i], v[j]) < 0)
			swap(&vout[k], &v[i++]);
		else
			swap(&vout[k], &v[j++]);
		k++;
	}
	while (i <= i2 - 1) { swap(&vout[k],&v[i++]); k++; }
	while (j <= fine) { swap(&vout[k], &v[j++]); k++; }
	for (i = i1; i <= fine; i++) assign(&v[i], vout[i]);
}


void quickSort(Array v, int dim)
{
	quickSortR(v, 0, dim - 1);
}
void quickSortR(Array v, int iniz, int fine)
{
	int i, j, iPivot;
	Element pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = v[iPivot];
		do // trova la posizione del pivot
		{
			while (i < j && compare(v[i], pivot) <= 0) i++;
			while (j > i && compare(v[j], pivot) >= 0) j--;
			if (i < j) swap(&v[i], &v[j]);
		} while (i < j);
		// determinati i due sottoinsiemi 
		// posiziona il pivot
		if (i != iPivot && v[i] != v[iPivot])
		{
			swap(&v[i], &v[iPivot]);
			iPivot = i;
		}
		// ricorsione sulle sottoparti, se necessario
		if (iniz < iPivot - 1)
			quickSortR(v, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortR(v, iPivot + 1, fine);
	}
} 
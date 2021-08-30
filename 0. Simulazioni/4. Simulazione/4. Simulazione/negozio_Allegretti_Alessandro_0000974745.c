#define _CRT_SECURE_NO_WARNINGS

#include "negozio_Allegretti_Alessandro_0000974745.h"

Set leggiUnSet(FILE* fp) {
	Set result;
	unsigned i;
	int lettura = 5;

    lettura = fscanf(fp, "%d %s %c %d %f", &result.id, result.contenuto, &result.tipo, &result.disp, &result.costo);

	if (lettura != 5)
		result.id = -1000;
	else {		
		for (i = 0; i < strlen(result.contenuto); i++) {
			if (result.contenuto[i] == '_')
				result.contenuto[i] = ' ';
		}
	}
	return result;
}
list leggiTuttiSet(char* fileName) {
	FILE* fp;
	list result;
	Set temp;

	result = emptyList();

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		temp = leggiUnSet(fp);
		while (temp.id >= 0) {
			result = cons(temp, result);
			temp = leggiUnSet(fp);
		}
		fclose(fp);
	}
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
	}

	return result;
}

Complex leggiUnComplex(FILE* fp) {
	Complex result;
	int lettura = 0;

	lettura = fscanf(fp, "%d ", &result.id);
	if (lettura == 1) {
		result.size = 0;
		while (lettura == 1 && result.semplici[result.size] >= 0) {
			lettura = fscanf(fp, "%d ", &(result.semplici[result.size]));
			result.size++;
		}
	}
	else {
		result.id = -1000;
	}
	return result;
}

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
int compare(int e1, int e2) {
	return e2 - e1;
}

void quickSortR(int* v, int iniz, int fine)
{
	int i, j, iPivot;
	int pivot;
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
		if (i != iPivot && compare(v[i], pivot))
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
void ordina(int* v, int dim) {
	quickSortR(v, 0, dim - 1);
}

Complex trovaComplex(char* fileName, int target) {
	FILE* fp;
	Complex result;


	fp = fopen(fileName, "rt");
	
	if (fp != NULL) {
		result = leggiUnComplex(fp);
		while (result.id != -1000 && result.id != target) {
			result = leggiUnComplex(fp);
		}
		if (result.id == target)
			ordina(result.semplici, result.size);
		fclose(fp);
	}
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
		result.id = -1000;
	}

	return result;
}

int check(list elenco, int target, Set* theSet) {
	BOOLEAN found = FALSE;
	
	while (!empty(elenco) && found == FALSE) {
		*theSet = head(elenco);
		if (head(elenco).id == target)
			found = TRUE;
		else
			elenco = tail(elenco);
	}
	if (found)
		*theSet = head(elenco);

	return found;
}

BOOLEAN disp(list elenco, int target, char* fileName) {
	Set temp;
	Complex comp;
	int i;
	int found = FALSE;
	int foundC = FALSE;

	found = check(elenco, target, &temp);
	if (found == TRUE) {
		if (temp.disp > 0)
			found = TRUE;
		if (temp.disp == 0 && temp.tipo == 'S')
			found = FALSE;
		if (temp.disp == 0 && temp.tipo == 'C') {
			comp = trovaComplex(fileName, target);
			if (comp.id != -1000) {
				for (i = 0; i < comp.size; i++) {
					foundC = check(elenco, comp.semplici[i], &temp);
				}
			}
			if (foundC == TRUE)
				found = TRUE;
		}
	}
	return found;
}




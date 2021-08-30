#define _CRT_SECURE_NO_WARNINGS

#include "metro.h"

void printEvento(Evento e) {
	printf("%d %s %s", e.id, e.s_ing, e.s_usc);
}

int readField1(char buffer[], int dim_buffer, char sep, FILE* f)
{
	int i = 0;
	char ch = fgetc(f);
	while (ch != sep && ch != '\n' && i < (dim_buffer - 1) && ch != EOF) {
		buffer[i] = ch;
		i++;
		ch = fgetc(f);
	}
	buffer[i] = '\0';

	return ch;
}
int readField2(char buffer[], int dim_buffer, FILE* f) {
	int i = 0;
	char ch = fgetc(f);
	while (ch != '\n' && i < (dim_buffer - 1) && ch != EOF) {
		buffer[i] = ch;
		i++;
		ch = fgetc(f);
	}
	buffer[i] = '\0';

	return ch;
}

Evento leggiUno(FILE* fp) {
	Evento e;
	char sepRead1 = ' ';
	char sepRead2 = ' ';
	int lettura1;

	lettura1 = fscanf(fp, "%d ", &e.id);
	if (lettura1 == 1) {
		sepRead1 = readField1(e.s_ing, DIM, '@', fp);
		if (sepRead1 == '@') {
			sepRead2 = readField2(e.s_usc, DIM, fp);
		}
		else e.id = -1;
	}
	else e.id = -1;

	return e;
}

list leggiTutti(char* fileName) {
	FILE* fp;
	list result;
	Evento temp;

	result = emptyList();

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		temp = leggiUno(fp);
		while (temp.id != -1) {
			if (temp.id != -1)
				result = cons(temp, result);
			temp = leggiUno(fp);
		}
		fclose(fp);
	}
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
	}

	return result;
	
	fclose(fp);
}

int leggiUnaTariffa(FILE* fp, Tariffa* dest) {
	int i;
	char ch;
	int success;
	
	i = 0;
	ch = fgetc(fp);
	while (ch != '@' && ch != '\n' && ch != EOF && i < DIM - 1) {
		dest->s_ing[i++] = ch;
		ch = fgetc(fp);
	}
	dest->s_ing[i] = '\0';

	i = 0;
	ch = fgetc(fp);
	while (ch != '@' && ch != '\n' && ch != EOF && i < DIM - 1) {
		dest->s_usc[i++] = ch;
		ch = fgetc(fp);
	}
	dest->s_usc[i] = '\0';
		
	success = (fscanf(fp, "%f", &(dest->costo)) == 1);
	fgetc(fp);
	return success;
}
Tariffa* leggiTariffe(char* fileName, int* dim) {
	FILE* fp;
	Tariffa* result = NULL;
	Tariffa temp;
	int count;
	*dim = 0;

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		count = 0;
		while (leggiUnaTariffa(fp, &temp)) 
			count++;
		result = (Tariffa*)malloc(sizeof(Tariffa) * count);
		rewind(fp);
		while (leggiUnaTariffa(fp, &temp)) {
			result[*dim] = temp;
			*dim = *dim + 1;
		}
		fclose(fp);
	}
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
	}
	
	return result;
}


void swap(Tariffa* a, Tariffa* b)
{
	Tariffa tmp = *a;
	*a = *b;
	*b = tmp;
}
int compare(Tariffa e1, Tariffa e2) {
	int result;
	result = strcmp(e1.s_ing, e2.s_ing);
	if (result == 0)
	result = strcmp(e1.s_usc, e2.s_usc);
	if (result == 0) {
		if (e1.costo < e2.costo)
			result = -1;
		else
			if (e1.costo > e2.costo)
				result = 1;
	}
	return result;
}

void quickSortR(Tariffa* v, int iniz, int fine)
{
	int i, j, iPivot;
	Tariffa pivot;
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

void ordina(Tariffa* v, int dim) {

	quickSortR(v, 0, dim - 1);

}


int compareBin(char* ingresso, char* uscita, Tariffa t) {
	int result;
	result = strcmp(ingresso, t.s_ing);
	if (result == 0) {
		result = strcmp(uscita, t.s_usc);
	}
	return result;
}
float ricerca(Tariffa* v, int dim, char* ingresso, char* uscita) {
	int first = 0;
	int last = dim - 1;
	int med = (first + last) / 2;
	int found = 0;
	float result = 0.0F;

	ordina(v, dim);

	while ((first <= last) && (found == 0)) {
		if (compareBin(ingresso, uscita, v[med]) == 0) {
			found = 1;
			result = v[med].costo;
		}
		else
			if (compareBin(ingresso, uscita, v[med]) < 0)
				last = med - 1;
			else
				first = med + 1;
		med = (first + last) / 2;
	}
	return result;
}

void totali(Tariffa* tariffe, int dim, list eventi) {
	list temp;
	list temp2;
	float total;
	Evento current;

	temp = eventi;

	while (!empty(temp)) {
		current = head(temp);
		if (!member(current, tail(temp))) {
			temp2 = eventi;
			total = 0;
			while (!empty(temp2)) {
				if (head(temp2).id == current.id)
					total = total + ricerca(tariffe, dim, head(temp2).s_ing, head(temp2).s_usc);
				temp2 = tail(temp2);
			}
			printf("Totale della Card %d: %6.2f\n", current.id, total);
		}
		temp = tail(temp);
	}
}


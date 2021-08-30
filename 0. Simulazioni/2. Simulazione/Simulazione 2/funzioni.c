#define _CRT_SECURE_NO_WARNINGS

#include "funzioni.h"
#define OK 1
#define ERROR 0

Time timeDifference(Time t1, Time t2) {
	Time result;
	int s1, s2, sResult;

	s1 = t1.hour * 3600 + t1.min * 60;
	s2 = t2.hour * 3600 + t2.min * 60;
	sResult = s1 - s2;
	result.hour = sResult / 3600;
	sResult = sResult % 3600;
	result.hour = sResult / 60;
	sResult = sResult % 60;
	result.hour = sResult;

	return result;
}

Time getTranslatedTime(Time t1, int min) {
	Time t2;

	t2.min = (t1.min + min) % 60;
	t2.hour = t1.hour + (t1.min + min) / 60;
	return t2;
}

int readField(char buffer[], int dim_buffer, char sep, FILE* f)
{
	int i = 0;
	char ch = fgetc(f);
	while (ch != sep && ch != '\n' && i < dim_buffer && ch != EOF) {
		buffer[i] = ch;
		i++;
		ch = fgetc(f);
	}
	buffer[i] = '\0';

	return ch;
}
list readWorkers(char* nomeFile) {
	FILE* fp;
	Worker temp1, temp2;
	list l1 = emptyList();
	list l2 = emptyList();
	list svuota;
	int result = OK;
	int i;
	char sepRead = ' ';
	int lettura1 = 0, lettura2 = 0;

	fp = fopen(nomeFile, "wt");

	if (fp == NULL) {
		printf("Errore di apertura dei file");
		exit(-1);
	}

	do {
		i = 0;
		lettura1 = fscanf(fp, "%d", &(temp1.cod));
		if (lettura1 == 1)
			sepRead = readField(temp1.nome, 20, ';', fp);
		else result = ERROR;
		if (sepRead == ';' && result == OK)
			while (lettura2 == 4 && i < DIM) {
				lettura2 = fscanf(fp, "%d:%d %d:%d;", &temp1.impegni[i].inizio.hour, &temp1.impegni[i].inizio.min,
					&temp1.impegni[i].fine.hour, &temp1.impegni[i].fine.min);
				i++;
			}
		else result = ERROR;

		l1 = cons(temp1, l1);
	} while (result == OK);

	while (!empty(l1)) {				// necessario invertire ordine lista (LIFO)
		temp2 = head(l1);
		l2 = cons(temp2, l2);
		l1 = tail(l1);
	}

	while (!empty(l1)) {
		svuota = l1;
		l1 = tail(l1);
		free(svuota);
	}

	return l2;
}

Request* readRequests(char* nomeFile) {
	FILE* fp;
	Request temp;
	Request* result, * resTemp;
	char get;
	int lettura1, lettura2;

	fp = fopen(nomeFile, "rb");
	if (fp == NULL) {
		printf("Errore nell'apertura in lettura del file %s.\n", nomeFile);
		get = getchar();
		exit(-3);
	}

	lettura1 = fread(&(temp.tot), sizeof(int), 1, fp);
	if (lettura1 && temp.tot > 0)
		result = (Request*)malloc(sizeof(Request) * temp.tot);
	else result = (Request*)malloc(sizeof(Request));

	if (result != NULL) {
		result->tot = temp.tot;
		resTemp = result;
	}
	else resTemp = NULL;

	do {
		lettura1 = fread(&(temp.cod), sizeof(int), 1, fp);
		lettura2 = fread(&(temp.min), sizeof(int), 1, fp);
		if (resTemp != NULL) {
			(*resTemp) = temp;
			resTemp++;
		}
	} while (lettura1 && lettura2);

	fclose(fp);
	return result;
}

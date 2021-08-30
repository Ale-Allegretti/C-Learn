#include "ingredienti.h"

list leggiIngredienti(char *fileName) {
	FILE* fp;
	char nome[MAX] = "";
	float prezzo;
	Element temp;
	list result = emptyList();

	if ((fp = fopen(fileName, "r")) == NULL)
		return result;
	while (fscanf(fp, "%s %f", nome, &prezzo) == 2)
	{
		strcpy(temp.nome, nome);
		temp.prezzo = prezzo;
		result = cons(temp, result);
	}

	fclose(fp);
	return result;
}

int scriviIngredienti(char* fileName, list l1) {
	FILE* fp;

	if ((fp = fopen(fileName, "w")) == NULL)
	{
		return -1;
	}
	while (!empty(l1))
	{
		fprintf(fp, "%s %f\n", head(l1).nome, head(l1).prezzo);
		l1 = tail(l1);
	}
	fclose(fp);
	return 0;
}

double trovaPrezzo(char* nomeIng, list l1) {
	Element temp;
	double result = 0.0F;

	while (!empty(l1)) {
		temp = head(l1);
		if (strcmp(nomeIng, temp.nome))
			result = temp.prezzo;
		else
			l1 = tail(l1);
	}
	return result;
}

list aggiornaPrezzo(list l1, char* nomeIng, double newP) {
	list temp = l1;
	int trovato = 0;

	while (!empty(temp) && !trovato) {
		if (strcmp(head(temp).nome, nomeIng) == 0)
		{
			trovato = 1;
			temp->value.prezzo = newP;
		}
		else
		{
			temp = tail(temp);
		}
	}
	return l1;
}
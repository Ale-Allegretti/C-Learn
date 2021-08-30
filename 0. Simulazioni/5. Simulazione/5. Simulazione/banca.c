#define _CRT_SECURE_NO_WARNINGS

#include "banca.h"
/*
Loan leggiUnLoan(FILE* fp) {
	int i, lettura;
	char ch;
	Loan res;

	lettura = fscanf(fp, "%d ", &res.id);
	if (lettura != 1)
		res.id = 0;

	i = 0;
	ch = fgetc(fp);
	while (ch != ';' && ch != '\n' && ch != EOF && i < DIM - 1) {
		res.cognome[i++] = ch;
		ch = fgetc(fp);
	}
	res.cognome[i] = '\0';

	i = 0;
	ch = fgetc(fp);
	while (ch != ';' && ch != '\n' && ch != EOF && i < DIM - 1) {
		res.nome[i++] = ch;
		ch = fgetc(fp);
	}
	res.nome[i] = '\0';

	lettura = fscanf(fp, "%f ", &res.importo);
	fgetc(fp);

	return res;
}
*/

int readField(char buffer[], int dim_buffer, char sep, FILE* f)
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

Loan leggiUnLoan(FILE* fp) {
	int lettura;
	char Sep;
	Loan res;

	lettura = fscanf(fp, "%d ", &res.id);
	if (lettura == 1) {
		Sep = readField(res.cognome, DIM, ';', fp);
		if (Sep == ';') {
			Sep = readField(res.nome, DIM, ';', fp);
			if (Sep == ';') {
				lettura = fscanf(fp, "%f ", &res.importo);
				if (lettura != 1)
					res.id = 0;
			} else res.id = 0;
		} else res.id = 0;
	} else res.id = 0;
	
	return res;
}

Loan* leggiLoanAttivi(char* fileName, int* dim) {
	FILE* fp;
	Loan* result = NULL;
	Loan temp;
	int count;

	*dim = 0;

	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		count = 0;
		do {
			temp = leggiUnLoan(fp);
			if (temp.id != 0 && strstr(temp.cognome, "ESTINTO") == NULL)
				count++;
		} while (temp.id != 0);
		if (count > 0) {
		result = (Loan*)malloc(sizeof(Loan) * count);
		rewind(fp);
		do {
			temp = leggiUnLoan(fp);
			if (temp.id != 0 && strstr(temp.cognome, "ESTINTO") == NULL) {
				result[*dim] = temp;
				(*dim)++;
			}
		} while (temp.id != 0);
		}
		fclose(fp);
	}
	else {
		printf("Errore nell'apertura del file: %s\n", fileName);
		result = NULL;
	}

	return result;
}

void assign(Loan* lvalue, Loan rvalue)
{
	*lvalue = rvalue;
}
void swap(Loan* a, Loan* b)
{
	Loan tmp = *a;
	*a = *b;
	*b = tmp;
}
int compare(Loan e1, Loan e2) {
	int result;
	result = strcmp(e1.cognome, e2.cognome);
	if (result == 0)
		result = strcmp(e1.nome, e2.nome);
	if (result == 0) {
		if (e1.importo > e2.importo)
			result = -1;
		else
			if (e1.importo < e2.importo)
				result = 1;
	}
	return result;
}
void insertSort(Loan* v, int size_v) {
	int k;
	for (k = 1; k < size_v; k++)
		insOrd(v, k);
}
void insOrd(Loan* v, int pos) {
	int i = pos - 1;
	Element x = v[pos];

	while (i >= 0 && compare(x, v[i]) < 0) {
		assign(&v[i + 1], v[i]); // crea lo spazio
		i--;
	}
	swap(&v[i + 1], &x); // inserisce l’elemento
}
void ordina(Loan* elenco, int dim) {
	insertSort(elenco, dim);
}

list estrai(Loan* elenco, int dim, char* cognome, char* nome) {
	list res;
	Loan temp;
	int i;

	res = emptyList();
	for (i = 0; i < dim; i++) {
		if (strcmp(elenco[i].cognome, cognome) == 0 && strcmp(elenco[i].nome, nome) == 0) {
			temp = elenco[i];
			res = cons(temp, res);
		}
	}
	
	return res;
}

int stessoIndividuo(Loan l1, Loan l2) {
	return strcmp(l1.cognome, l2.cognome) == 0 && strcmp(l1.nome, l2.nome) == 0;
}
void espo(Loan* elenco, int dim) {
	int i;
	list temp1, temp2;
	float amount;

	ordina(elenco, dim);

	for (i = 0; i < dim; i++) {
		if (i == 0 || !stessoIndividuo(elenco[i], elenco[i - 1])) {
			temp1 = estrai(elenco, dim, elenco[i].cognome, elenco[i].nome);
			temp2 = temp1;
			amount = 0;

			while (!empty(temp2)) {
				amount = amount + head(temp2).importo;
				temp2 = tail(temp2);
			}
			freelist(temp1);
			printf("Sig. %s %s: %.2f\n", elenco[i].cognome, elenco[i].nome, amount);
		}
	}
}
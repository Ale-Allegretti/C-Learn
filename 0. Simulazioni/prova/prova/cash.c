/*
* Mantovani Federico 0000977019 Prova 1A
*
*/
#include "cash.h"
operazione* leggiTutteOperazioni(char* fileName, int* dim) {
	FILE* fp;
	int count = 0, i = 0;
	operazione tmp;
	operazione* opArray = NULL;
	fp = fopen(fileName, "rt");
	if (fp != NULL) {
		if (fscanf(fp, "%d %f %s", &tmp.id, &tmp.importo,
			tmp.nomeNegozio) == 3) {
			count++;
			while (fscanf(fp, "%d %f %s", &tmp.id, &tmp.importo,
				tmp.nomeNegozio) == 3) {
				count++;
			}
			rewind(fp); // riavvolgo testina per lettura file
			opArray = (operazione*)malloc(sizeof(operazione) * count);
			while (fscanf(fp, "%d %f %s", &opArray[i].id,
				&opArray[i].importo, opArray[i].nomeNegozio) == 3) {
				i++;
			}
			(*dim) = count;
			fclose(fp);
		}
	} else {
		(*dim) = 0;
		perror("Errore:");
	}

	return opArray;
}

list leggiNegozi(char* fileName) {
	negozio tmp;
	list l = emptyList();
	FILE* fp;
	fp = fopen(fileName, "rt");

	if (fp != NULL) {
		if (fscanf(fp, "%s %c", tmp.nome, &tmp.tipo) == 2) {
			l = addToHead(tmp, l);
			while (fscanf(fp, "%s %c", tmp.nome, &tmp.tipo) == 2) {
				l = addToHead(tmp, l);
			}
		}
		fclose(fp);

	} else {
		perror("Errore");
	}

	return l;
}

void stampaOperazioni(operazione* v, int dim) {
	if (dim == 0) {
		return;
	}
	else {
		printElement(v[dim - 1]);
		stampaOperazioni(v, dim - 1);
	}
}

void ordina(operazione* v, int dim) {
	bubbleSort(v, dim);
}

void bubbleSort(operazione* arr, int size) {
	int i, ordinato = 0;
	while (size > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < size - 1; i++)
			if (compareOp(arr[i], arr[i + 1]) > 0) {
				swap(&arr[i], &arr[i + 1]);
				ordinato = 0;
			}
		size--;
	}
}

void swap(operazione* op1, operazione* op2) {
	operazione tmp;
	tmp = *op1;
	*op1 = *op2;
	*op2 = tmp;
}

int negozioFisico(char* nomeNegozio, list negozi) {
	int trovato = 0;
	negozio tmp;

	while (!isEmpty(negozi) && trovato != 1) {
		strcpy(tmp.nome, head(negozi).nome);
		tmp.tipo = head(negozi).tipo;
		if (strcmp(nomeNegozio, tmp.nome) == 0 &&
			tmp.tipo == 'F') {
			trovato = 1;
		}
		negozi = tail(negozi);
	}

	return trovato;
}

operazione* filtra(operazione* v, int dim, list negozi, int* dimLog) {
	int i = 0, j = 0, trovato = 0, count = 0;
	negozio tmp;
	list listCopy;
	listCopy = copy(negozi);
	operazione* newArray = NULL;

	for (i = 0; i < dim; i++) {
		trovato = 0;
		negozi = listCopy;
		while(!isEmpty(negozi) && trovato != 1) {
			strcpy(tmp.nome, head(negozi).nome);
			tmp.tipo = head(negozi).tipo;
			if (strcmp(tmp.nome, v[i].nomeNegozio) == 0 &&
				tmp.tipo == 'F') {
				trovato = 1;
				count++;
			}
			negozi = tail(negozi);
		}
	}

	newArray = (operazione*)malloc(sizeof(operazione) * count);
	for (i = 0; i < dim; i++) {
		trovato = 0;
		negozi = listCopy;
		while (!isEmpty(negozi) && trovato != 1) {
			strcpy(tmp.nome, head(negozi).nome);
			tmp.tipo = head(negozi).tipo;
			if (strcmp(tmp.nome, v[i].nomeNegozio) == 0 &&
				tmp.tipo == 'F') {
				trovato = 1;
				newArray[j] = v[i];
				j++;
			}
			negozi = tail(negozi);
		}
	}

	(*dimLog) = count;

	return newArray;
}

float spesaCliente(int idCliente, operazione* v, int dim) {
	float spesa = 0.0;
	int i = 0;

	for (i = 0; i < dim; i++) {
		if (idCliente == v[i].id) spesa += v[i].importo;
	}

	return spesa;
}

int* getAllIDs(operazione* v, int dim, int* dimLog, list negozi) {
	int* array = NULL;
	int* tmp;
	int i = 0, count = 0, dimFisico = 0;
	operazione* opFisiche;
	opFisiche = filtra(v, dim, negozi, &dimFisico);
	tmp = (int*)malloc(sizeof(int) * dimFisico);

	for (i = 0; i < dimFisico; i++) {
		if (compareIDs(opFisiche[i].id, tmp, dimFisico) == 0) {
			tmp[count] = opFisiche[i].id;
			count++;
		}
	}
	array = (int*)malloc(sizeof(int) * count);

	for (i = 0; i < count; i++) {
		array[i] = tmp[i];
	}

	*dimLog = count;

	return array;
}

int compareIDs(int id, int* arrayIDs, int dim) {
	int i = 0, presente = 0;

	for (i = 0; i < dim; i++) {
		if (id == arrayIDs[i]) presente = 1;
	}

	return presente;
}
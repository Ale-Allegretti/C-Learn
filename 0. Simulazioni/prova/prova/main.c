/*
* Mantovani Federico 0000977019 Prova 1A
*
*/
#include "list.h"
#include "cash.h"
int main() {
	// ES 1
	{
		operazione* op;
		list negozi;
		int dim = 0, i = 0;
		op = leggiTutteOperazioni("operazioni.txt", &dim);
		stampaOperazioni(op, dim);

		negozi = leggiNegozi("negozi.txt");
		showList(negozi);
		freelist(negozi);
	}

	// ES 2
	{
		operazione* op;
		operazione* newOp;
		list negozi;
		int dim = 0, ris, dimLog = 0;
		op = leggiTutteOperazioni("operazioni.txt", &dim);
		printf("\nArray non ordinato:\n");
		stampaOperazioni(op, dim);

		printf("Array ordinato:\n");
		ordina(op, dim);
		stampaOperazioni(op, dim);

		negozi = leggiNegozi("negozi.txt");
		ris = negozioFisico("FruttaVerduraSNC", negozi);
		if (ris == 1) printf("\nPresente\n");
		else printf("\nAssente\n");

		newOp = filtra(op, dim, negozi, &dimLog);
		stampaOperazioni(newOp, dimLog);
		freelist(negozi);
	}

	// ES 3
	{
		operazione* op;
		int dim = 0, idCliente = 44;
		float spesa = 0.0;
		op = leggiTutteOperazioni("operazioni.txt", &dim);
		spesa = spesaCliente(idCliente, op, dim);
		printf("\nIl cliente ID %d ha speso %f euro\n", idCliente, spesa);
	}

	// ES 4
	{
		operazione* op;
		int dim = 0, dimLog = 0, i = 0;
		int* arrayIDs;
		list negozi;
		negozi = leggiNegozi("negozi.txt");
		op = leggiTutteOperazioni("operazioni.txt", &dim);
		arrayIDs = getAllIDs(op, dim, &dimLog, negozi);

		for (i = 0; i < dimLog; i++) {
			printf("\nLa spesa per ID %d: %f euro\n", arrayIDs[i],
				spesaCliente(arrayIDs[i], op, dim));
		}
	}

	system("PAUSE");

	return 0;
}
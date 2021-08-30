/*
* Mantovani Federico 0000977019 Prova 1A
*
*/
#include "element.h"

boolean isEqual(operazione e1, operazione e2) {
	//return e1 == e2 ? 1 : 0;
	return 1;
}

operazione getElement() {
	operazione el;
	scanf("%d", &el.id);
	scanf("%f", &el.importo);
	scanf("%s", el.nomeNegozio);
	return el;
}

void printElement(operazione el) {
	printf("\nID: %d", el.id);
	printf("\nImporto: %f", el.importo);
	printf("\nNome negozio: %s", el.nomeNegozio);
	printf("\n---\n");
}

int compare(operazione e1, operazione e2) {
	//return e1 == e2 ? 1 : 0;
	return 1;
}

void printNegozio(negozio n) {
	printf("\nNome: %s", n.nome);
	printf("\nTipo: %c", n.tipo);
	printf("\n---\n");
}

int compareOp(operazione op1, operazione op2) {
	int res = op1.id - op2.id;

	if (res > 0) return res;
	if (res == 0) {
		if (op1.importo - op2.importo > 0) {
			return -1;
		}
		return 0;
	}

}
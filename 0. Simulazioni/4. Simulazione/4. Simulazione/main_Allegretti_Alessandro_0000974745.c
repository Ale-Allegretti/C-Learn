#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "negozio_Allegretti_Alessandro_0000974745.h"

int main() {
	{ // Es. 1
		list elenco;
		elenco = leggiTuttiSet("negozio.txt");
		showList(elenco);
		freelist(elenco);
	}
	{ // Es. 2
		Complex temp;
		int i;
		temp = trovaComplex("complessi.txt", 67914);
		printf("\n\n");
		if (temp.id >= 0) {
			printf("Set complesso %d:\n", 67914);
			for (i = 0; i < temp.size; i++) {
				printf("\t%d\n", temp.semplici[i]);
			}
		}
		else {
			printf("Non ho trovato il set %d\n", 67914);
		}
		printf("\n\n");
	}
	{ // Es. 3
		list elenco;
		int target;
		int trovato;
		elenco = leggiTuttiSet("negozio.txt");
		printf("A quale Set si e' interessati? ");
		scanf_s("%d", &target);
		trovato = disp(elenco, target, "complessi.txt");
		if (!trovato) {
			printf("Spiacenti, il Set %d non e' disponibile\n", target);
		}
		else {
			printf("Il Set %d e' disponiible\n", target);
		}
		freelist(elenco);
	}
	return 0;
}
#include <stdio.h>

#include "myMath.h"
#include <stdio.h>

int main() {
	int N_livelli, n, k;

	printf("Inserire il livello max di Tartaglia: ");
	scanf_s("%d", &N_livelli);
	
	for (n = 0; n < N_livelli; n++) {
		for (k = 0; k <= n; k++)
			printf("%d ", fact_bin(n, k));
		printf("\n");
	}
	return 0;
}
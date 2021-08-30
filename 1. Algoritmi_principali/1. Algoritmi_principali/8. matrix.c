

/*1) Inizializzazione matrice con prodotto*/ void prodottoMatrici(int X[][N], int Y[][N], int Z[][N]) {
	int Somma, i, j, k;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			Somma = 0;
			for (k = 0; k < N; k++)
				Somma = Somma + X[i][k] * Y[k][j];
			Z[i][j] = Somma;
		}
}
int main(void) {
	int i, j;
	Matrici A, B, C;

	for (i = 0; i < N; i++) { /* inizializ. di A e B */
		for (j = 0; j < N; j++) {
			printf("Elemento a%d%d della prima matrice: ", i, j);
			scanf_s("%d", &A[i][j]);
		}
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			printf("Elemento a%d%d della seconda matrice: ", i, j);
			scanf_s("%d", &B[i][j]);
		}
	}

	prodottoMatrici(A, B, C); //in C verrà caricato il risultato del prodotto

	printf("\nMatrice prodotto: \n");
	for (i = 0; i < N; i++) {		/* stampa */
		for (j = 0; j < N; j++)
			printf("%d\t", C[i][j]);
		printf("\n");
	}
	return (0);
}


/*2) Inizializzazione matrice random con operazioni*/
void initMatrice(int* m, int size_r, int size_c) {
	int i, j;
	for (i = 0; i < size_r; i++) {
		for (j = 0; j < size_c; j++) {
			m[i * size_c + j] = rand() %46 - 5;  /* %46 - 5 per far inserire al compilatore numeri casuali da -5°C a +40°C */
		}
	}
}
void printMatrice(int* m, int sizer, int sizec) {
	int i, j;
	for (i = 0; i < sizer; i++) {
		for (j = 0; j < sizec; j++) {
			printf("%4d ", m[i * sizec + j]);
		}
		printf("\n");
	}
}
float temp_media(int m[][ORE], int size_gg) {
	int i, j;
	int result = 0;
	float media;

	for (i = 0; i < size_gg; i++) {
		for (j = 0; j < ORE; j++) {
			result = result + m[i][j];
		}
	}
	media = (float) result / (ORE * size_gg);
	return media;
}
float temp_diurna(int m[][ORE], int size_gg) {
	int result = 0;
	float media;
	int i, j;

	for (i = 0; i < size_gg; i++) {
		for (j = 7; j <= 19; j++) {
			result = result + m[i][j];
		}
	}
	media = (float)result / ((ORE / 2) * size_gg);
	return media;
}
float temp_notturna(int m[][ORE], int size_gg) {
	int result = 0;
	float media;
	int i, j;

	for (i = 0; i < size_gg; i++) {
		for (j = 0; j < ORE; j++) {
			if (j < 7 || j >= 19)
				result = result + m[i][j];
		}
	}
	media = (float) result / ((ORE / 2) * size_gg);
	return media;
}
int main() {
	int temp[GG][ORE];

	initMatrice(&temp[0][0], GG, ORE);
	printMatrice(&temp[0][0], GG, ORE);

	printf("Temperatura media mensile: %f\n", temp_media(temp, 31));
	
	printf("Temp. media diurna: %f\n", temp_diurna(temp, 31));
	printf("Temp. media notturna: %f\n", temp_notturna(temp, 31));

}
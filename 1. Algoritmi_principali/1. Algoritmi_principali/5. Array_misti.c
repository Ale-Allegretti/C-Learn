
/*1)sommatoria e media*/ int main() {
	int k, v[N];
	int s = 0;
	float media;

	printf("Inserire al più dieci temperature: ");
	for (k = 0; k < N; k++)
		scanf_s("%d", &v[k]);
	for (k = 0; k < N; k++) {
		s += v[k];
		media = (float)s / k;
	}

	printf("Media delle temperature: %.2f", media);

	return 0;
}

/*2)print el. ripetuti*/int main(void) {
	int k, size, num;    // importante distinguere la dimensione fisica da quella logica, usando una variabile size
	int v[N];

	size = 0;
	do
	{
		printf("Inserire l'elemento: ");
		scanf_s("%d", &num);
		if (num != 0 && size < N) {
			v[size] = num;
			size++;
		}
	} while (num != 0 && size < N);		// && perchè deve rispettare entrambe le condizioni

	printf("Gli elementi sono: \n");

	for (k = 0; k < size - 1; k++)		//size - 1 perchè non devo uscire dall'array (che va da 0 a 9 => dim 10)
		if (v[k] == v[k + 1])			//stampa solo i numeri che si sono ripetuti nella scanf
			printf("%d ", v[k]);

	return (0);
}

/*3)print v. inverso*/int main(void) {
	int i, size, num;
	int drit[N], inv[N];
	int j = 0;

	size = 0;
	do
	{
		printf("Inserire un valore positivo: ");
		scanf_s("%d", &num);
		if (num > 0 && size < N) {
			drit[size] = num;
			size++;
		}
	} while (num != 0 && size < N);

	j = 0;
	for (i = size - 1; i >= 0; i--) {
		drit[i] = inv[j];
		j++;
		printf("%d ", inv[j]);
	}

	return (0);
}

/*4)search el. pari a ind. pari*/int main(void) {
#include <stdlib.h>
	int i, size, num;
	int numeri[LIMIT];

	size = 0;
	do {
		printf("Inserire un numero: ");
		scanf_s("%d", &num);
		if (num > 0 && size < LIMIT) {
			numeri[size] = num;
			size++;
		}
		else if (size >= LIMIT) {
			printf("Spazio esaurito...\n");
		}
	} while (num != 0);

	for (i = 0; i < size; i++)
		if ((i % 2) == 0 && (numeri[i] % 2) == 0)
			printf("Numero all'indice %d: %d\n", i, numeri[i]);

	return (0);
}

/*5)media ind. progressivo*/int main() {
	float num;
	int i, size;
	float v[N], med[N];

	size = 0;
	do
	{
		printf("Inserire un valore: ");
		scanf_s("%f", &num);
		if (num > 0 && size < N) {
			v[size] = num;
			size++;
		}
	} while (num != 0 && size < N);

	for (i = 0; i < size - 1; i++) {
		med[i] = (v[i] + v[i + 1]) / 2;
	}

	printf("Gli elementi sono: \n");

	for (i = 0; i < size - 1; i++)
		printf("%f ", med[i]);

	return (0);
}

/*6)combinazione el. ind. pari e disp*/ int main() {
	int i;
	int v1[N], v2[N], v3[2 * N];

	for (i = 0; i < N; i++) {
		printf("Inserire il valore %d del primo vettore: ", i);
		scanf_s("%d", &(v1[N]));
	}
	for (i = 0; i < N; i++) {
		printf("Inserire il valore %d del secondo vettore: ", i);
		scanf_s("%d", &(v2[N]));
	}
	for (i = 0; i < N; i++) {
		v3[2 * i] = v1[i];
		v3[2 * i + 1] = v2[i];
	}

	for (i = 0; i < 2 * N; i++)
		printf("%d ", v3[i]);

	return (0);
}

/*7)separazione el. pari e disp.*/int main() {
	int num[N], par[N], disp[N];
	int i, ivp = 0, ivd = 0;  // iv = indice vettore (pari o dispari)

	for (i = 0; i < N; i++) {
		do {
			printf("Inserire un valore intero positivo: ");
			scanf_s("%d", &(num[i]));
		} while (num[i] < 0);
	}

	for (i = 0; i < N; i++) {
		if (pari(num[i])) {
			par[ivp] = num[i];
			ivp++;
		}
		else {
			disp[ivd] = num[i];
			ivp++;
		}
	}

	for (i = 0; i < ivp; i++)
		printf("%d ", par[i]);
	printf("\n");
	for (i = 0; i < ivd; i++)
		printf("%d ", disp[i]);

	return (0);
}

/*8)media con soglia nel print e inserimento el. int. crescente*/int main(void) {
	int num, size, i, prec;
	int values[DIM];
	float soglia;
	float ratio[DIM];

	do {
		printf("Quanti numeri vuoi inserire ? (MAX 10) ");
		s_scanf("%d", &size);
	} while (size < 0 || size > DIM);

	prec = -1;
	for (i = 0; i < size; ) {
		printf("Inserisci un numero:");
		s_scanf("%d", &num);
		if (num > prec) {
			values[i] = num;
			prec = num;
			i++;
		}
	}

	for (i = 0; i < size - 1; i++)
		ratio[i] = ((values[i + 1] - values[i]) / ((float)values[i])) * 100;
	printf("Inserire soglia: ");
	scanf_s("%f", &soglia);

	for (i = 0; i < size - 1; i++)
		if (ratio[i] > soglia)
			printf("%d %d\n", values[i], values[i + 1]);

	return (0);
}

/*9)inserimento condizionato e print con soglia = media*/ int main(void) {
	int cod_loc, size, i, tot;
	int loc[DIM], neve[DIM];
	float media;

	size = 0;
	do {
		printf("Inserisci codice localita': ");
		scanf_s("%d", &cod_loc);
		if (cod_loc != 0 && size < DIM) {
			loc[size] = cod_loc;
			printf("Manto nevoso (cm.): ");
			scanf_s("%d", &(neve[size]));
			size++;
		}
	} while (cod_loc != 0 && size < DIM);

	tot = 0;
	for (i = 0; i < size; i++)
		tot = tot + neve[i];
	media = tot / ((float)size);

	for (i = 0; i < size; i++)
		if (neve[i] < media)
			printf("localita' con poca neve: %d\n", loc[i]);

	return (0);
}

/*10)search e paragone con riempimento di un 3° v.*/int main() {
	int v1[DIM], v2[DIM], v3[DIM];
	int size1, size2, size3;
	int i, j, trovato;

	size1 = ins_values(v1, DIM);
	size2 = ins_values(v2, DIM);
	size3 = 0;

	for (i = 0; i < size1; i++) {
		trovato = 0;
		for (j = 0; j < size2 && !trovato; j++)
			if (v1[i] == v2[j])
				trovato = 1;
		if (trovato) {
			v3[size3] = v1[i];
			size3++;
		}
	}

	printf("Valori del terzo vettore \n");
	for (i = 0; i < size3; i++) {
		printf("%d ", v3[i]);
	}

	return 0;
}

/*11)search con dichiarazione posizione*/ int main() {
	int vett[DIM];
	int el, pos, size, cerca;

	size = ins_values(vett, DIM);

	printf("Inserire il valore da cercare: ");
	scanf_s("%d", &el);

	cerca = search2(vett, size, el, &pos);
	if (cerca) {
		printf("Il valore si trova nella posizione %d", pos);
	}
	else printf("Il valore non e' stato trovato");
}

/*12)search el. e riempimento v. di el. non ripetuti*/ int main(void) {
	int size_v, size_s, i;
	int vett[DIM], single[DIM];

	size_v = ins_values(vett, DIM);

	size_s = eliminaRipetuti(vett, size_v, single, DIM);

	for (i = 0; i < size_s; i++)
		printf("%d ", single[i]);

	return 0;
}

/*13)search e print di el. ripetuti*/ int main(void) {
	int size1, i;
	int vett[DIM];

	size1 = ins_values(vett, DIM);

	for (i = 0; i < size1; i++) {
		if (search3(&(vett[i + 1]), size1 - i - 1, vett[i]) >= 0) {
			if (search3(vett, i, vett[i]))
				printf("%d ", vett[i]);
		}
	}

	return 0;
}

/*14)search e print di el. non ripetuti*/ int main(void) {
	int size1, size2, i;
	int v1[DIM], v2[DIM];

	size1 = ins_values(v1, DIM);
	size2 = ins_values(v2, DIM);

	for (i = 0; i < size1; i++) {
		if (search3(v2, size2, v1[i]) < 0) {
			printf("%d ", v1[i]);
		}
	}

	return 0;
}

/*15)riempimento 3° v. di el. in ordine crescente*/ int main(void) {
	int size1, size2, i, j, k = 0;
	int v1[DIM], v2[DIM];

	size1 = ins_values(v1, 1, DIM); printf("\n");
	size2 = ins_values(v2, 2, DIM);

	i = 0;
	j = 0;
	while (i < size1 && j < size2) {
		if (v1[i] < v2[j]) {
			printf("%d ", v1[i]);
			i++;
		}
		else {
			printf("%d ", v2[j]);;
			j++;
		}
	}
	while (i < size1) {
		printf("%d ", v1[i]);
		i++;
	}
	while (j < size2) {
		printf("%d ", v2[j]);
		j++;
	}


	return 0;
}

/*16)search e print di el. ripetuti 2 volte*/ int main(void) {
	int size, i, count, temp_dim, temp_pos, offset;
	int v1[DIM];

	size = ins_values(v1, 1, DIM); printf("\n");

	for (i = 0; i < size; i++) {
		count = 0;
		temp_dim = size;
		offset = 0;
		do {
			temp_pos = search3(&v1[offset], temp_dim, v1[i]);
			if (temp_pos >= 0) {
				count++;
				temp_dim = temp_dim - temp_pos - 1;
				offset = offset + temp_pos + 1;
			}
		} while (temp_pos >= 0);
		if (count == 2)
			if (search3(v1, i, v1[i]) < 0)
				printf("L'elemento %d compare 2 volte\n", v1[i]);
	}
	return (0);
}

/*17)restringimento di un v. con nuovi estremi*/ int main() {
	int v1[DIM];
	int size1, size2;
	int* v2;
	int first, last, i;

	size1 = ins_values(v1, 1, DIM); printf("\n");

	printf("Inserire i nuovi estremi: ");
	scanf_s("%d%d", &first, &last);
	v2 = first_last(v1, size1, first, last, &size2);

	printf("\nNuovo vettore: \n");
	for (i = 0; i < size2; i++)
		("%d ", v2[i]);

	return 0;
}

/*18)print el. = somma dei due successivi*/int main(void) {
	int size1;
	int v1[DIM];

	size1 = ins_values(v1, 1, DIM);

	printf("Valori pari alla somma dei due seguenti: ");
	somme2(v1, size1);

	return 0;
}

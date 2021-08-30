
/* cicli while / do-while */

/*ciclo MCM*/ int main() {

	int x, MCM;

	printf("Inserire il primo valore: ");
	scanf_s("%d", &MCM);

	do {
		printf("\nInserire un altro valore: ");
		scanf_s("%d", &x);
		MCM = mcm(MCM, x);
		printf("\nIl minimo comune multiplo e': %d", MCM);
	} while (MCM <= 100);

	return 0;
}

/*ciclo log*/ do {
	printf("Inserire la base del logaritmo: "); scanf_s("%d", &b);
} while (b < 0 && printf("Inserire una base positiva\n\n"));

/*ciclo media*/ int main()
{
	int som, num, nValori;
	float media;
	som = 0;
	nValori = 0;

	do {
		printf("Inserire valore positivo o negativo: "); scanf_s("%d", &num);
		if (num > 0) {
			som = som + num;
			nValori = nValori + 1;
		}
	} while (num != 0);

	media = (float)som / nValori;

	printf("Media dei positivi: %f\n", media);

	return 0;
}

/*ciclo sommatoria di potenze*/ int main()
{
	double base, espMax;
	double somI, somF;

	printf("Inserire la base della potenza: "); scanf_s("%lf", &base);
	printf("Inserire l'esponente massimo: "); scanf_s("%lf", &espMax);

	somI = pow(base, espMax);
	espMax = espMax - 1;
	somF = somI + pow(base, espMax);

	do {
		espMax = espMax - 1;
		somF = somF + pow(base, espMax);
	} while (espMax != 0);

	printf("Sommatoria : %lf", somF);

	return 0;
}

/*ciclo contatore*/ int main(void)
{
	unsigned int counter;
	int voto;
	int total;
	float average;

	total = 0; //inizializzazione delle variabili 
	counter = 0;

	printf("Inserire un voto (-1 per terminare): ");
	scanf_s("%d", &voto);

	while (voto != -1) {
		total = total + voto;
		counter = counter + 1;
		printf("Inserire un altro voto (-1 per terminare): ");
		scanf_s("%d", &voto);
	}

	if (counter != 0) {
		average = (float)total / counter;
		printf("La media dei voti: %.2f\n", average);
	}

	else {
		puts("Nessun voto inserito");
	}

	return 0;
}


/*cicli for*/

/*Interessi annui*/ int main()
{
	double deposito = 1000.0;
	double rate = .05; //corrisponde al 5%

	printf("%4s%25s\n", "Anno", "Deposito con interessi");

	for (unsigned int anno = 1; anno <= 10; ++anno) {
		double amount = deposito * pow(1.0 + rate, anno);
		printf("%4u%21.2f\n", anno, amount);
	}
	return 0;
}

/*Sommatoria di sommatoria*/ int main() {

	int a, i, j;
	int somma;

	printf("Inserisci un numero: ");
	scanf_s("%d", &a);

	somma = 0; //elemento neutro della somma

	for (i = 1; i <= a; i++) {
		for (j = 1; j <= i; j++) {
			somma = somma + j;
		}
	}

	printf("La sommatoria di sommatoria vale: %d", somma);

	return 0;
	//sommatoria da i=1 ad a, di sommatoria da j=1 ad i, di j
}

/*ciclo con if*/ int main() {

	int num, i, result;
	printf("Inserisci un numero: ");
	scanf_s("%d", &num);

	if (num >= 1 && num <= 10) {
		result = 1;
		for (i = 1; i <= num; i++)
			result = result * num;
		printf("Valore calcolato: %d\n", result);
	}
	else
		if (num >= 11 && num <= 20) {
			result = 0;
			for (i = 1; i <= num; i++)
				result = result + i;
			printf("Valore calcolato: %d\n", result);
		}
		else printf("Errore!\n");
	return 0;
}

/*sommatoria di fattoriali*/ int main(void) {

	int limit, num;
	int i, j;
	int part, tot;

	printf("Quanti numeri vuoi inserire? ");
	scanf_s("%d", &limit);

	tot = 0;

	for (i = 0; i < limit; i++) {
		printf("Inserisci il numero %d:", i + 1);
		scanf_s("%d", &num);
		part = 1;
		for (j = num; j > 0; j--)
			part = part * j;
		tot = tot + part;
	}
	printf("Totale: %d\n", tot);
	return (0);
}


/*cicli misti*/

/*Interessi annui*/int main()
{
	double deposito = 1000.0;
	double rate, amount;
	unsigned int anno = 1;

	printf("%4s%25s%50s\n", "Anno", "Interesse %", "Deposito con interessi");

	while (anno <= 6) {
		for (rate = .05; rate <= .10; rate += .01) {
			amount = deposito * pow(1.0 + rate, anno);
			printf("%4u%21.1f%42.2f\n", anno, rate * 100, amount);
			anno++;
		}
	}
	return 0;
}
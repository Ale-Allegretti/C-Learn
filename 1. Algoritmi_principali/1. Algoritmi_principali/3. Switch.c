
/*contatore switch con while*/ 

int main()
{
	unsigned int aCount = 0;
	unsigned int bCount = 0;
	unsigned int cCount = 0;
	int voto;

	puts("Inserisci i voti (a, b o c),");
	puts("oppure inserisci EOF per terminare:");

	while ((voto = getchar()) != EOF) { //richiede l'inserimento finchè non si preme "Ctrl z" (EOF) seguito da invio

		switch (voto)
		{
		case 'A':
		case 'a':
			++aCount;
			break;

		case 'B':
		case 'b':
			++bCount;
			break;

		case 'C':
		case 'c':
			++cCount;
			break;

		case '\n': //ignora newline, tab e spazi terminando i casi solo con break
		case '\t':
		case ' ':
			break;

		default:
			printf("%s", "Lettera inserita non corretta.");
			puts("Inserire un nuovo voto.");
			break;
		}
	}

	puts("Numero totale dei voti corrispondenti:");
	printf("n. A: %u\n", aCount);
	printf("n. B: %u\n", bCount);
	printf("n. C: %u\n", cCount);

	return 0;
}

int main() {

	int numP, numV;
	float price;
	float tot1 = 0, tot2 = 0, tot3 = 0, tot4 = 0, tot5 = 0;


	do {
		printf("Inserire n.ro prodotto: ");
		scanf_s("%d", &numP);

		switch (numP) {

		case 1:
			printf("Inserire quantita' venduta: ");
			scanf_s("%d", &numV);
			price = 2.98F;
			tot1 = (float)price * numV;
			break;
		case 2:
			printf("Inserire quantita' venduta: ");
			scanf_s("%d", &numV);
			price = 4.50F;
			tot2 = (float)price * numV;
			break;
		case 3:
			printf("Inserire quantita' venduta: ");
			scanf_s("%d", &numV);
			price = 9.98F;
			tot3 = (float)price * numV;
			break;
		case 4:
			printf("Inserire quantita' venduta: ");
			scanf_s("%d", &numV);
			price = 4.49F;
			tot4 = (float)price * numV;
			break;
		case 5:
			printf("Inserire quantita' venduta: ");
			scanf_s("%d", &numV);
			price = 6.87F;
			tot5 = (float)price * numV;
			break;
		case -1:
			break;

		default:
			printf("%s", "N.ro prodotto inserito non corretto");
			puts("\nInserire un nuovo n.ro prodotto.\n");
			break;
		}
	} while (numP != -1);

	printf("\n%4s%21s\n", "N.ro Prodotto", "Guadagno totale");
	printf("%4s%21.2f\n", "1", tot1);
	printf("%4s%21.2f\n", "2", tot2);
	printf("%4s%21.2f\n", "3", tot3);
	printf("%4s%21.2f\n", "4", tot4);
	printf("%4s%21.2f\n", "5", tot5);
}
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*1) Scrittura semplice su file.txt*/ int main(void) {

	FILE* fp;
	char s[N] = "";
	if ((fp = fopen("prova.txt", "w")) == NULL) {
		printf("File 'prova.txt' non trovato.");
		exit(1);
	}
	do {
		if (scanf_s("%s", s, N) == 1) {
			if (strcmp("fine", s) != 0)
				fprintf(fp, "%s ", s);
		}
		else
			strcpy(s, "fine");
	} while (strcmp("fine", s) != 0);
	fclose(fp);
	return (0);
}

/*2) Scrittura sicura su file.txt*/ int main(void) {
	FILE* fp;
	int errore;
	char s[N] = " ";

	errore = fopen_s(&fp, "prova.txt", "w+");

	if (!errore) {
		printf("File 'prova.txt' trovato.\n");
		printf("Scrivere del testo oppure scrivere 'fine' per terminare: \n");
		do {
			if (scanf_s("%s", s, N) == 1) {
				if (strcmp("fine", s) != 0)
					if (fp)
						fprintf(fp, "%s ", s);
			}
			else
				strcpy_s(s, 5, "fine");
		} while (strcmp("fine", s) != 0);
	}
	else {
		printf("File 'prova.txt' non trovato.");
		exit(1);
	}
	if (fp) {
		fclose(fp);
		printf("Il file e' stato chiuso");
	}
	return (0);
}

/*3) Compilazione tabella con dati scruct in lettura/scrittura da più file.txt*/ void strut_tabella_files{
typedef struct {
	unsigned int matr;
	unsigned int CDL;
} Dati;

typedef struct {
	unsigned int matr;
	char nome[21];
	char cognome[31];
	char via[31];
	char citta[31];
	unsigned int CAP;
} Indirizzo;

typedef struct {
	unsigned int matr;
	char nome[21];
	char cognome[31];
	char via[31];
	char citta[31];
	unsigned int CAP;
	unsigned int CDL;
} Elemento;

typedef Elemento Tabella[10];

Elemento riempiel(Dati d, Indirizzo i) {
	Elemento e;
	e.matr = d.matr;
	e.CDL = d.CDL;
	strcpy(e.nome, i.nome);
	strcpy(e.cognome, i.cognome);
	strcpy(e.via, i.via);
	strcpy(e.citta, i.citta);
	e.CAP = i.CAP;
	return e;
}

int main() {
	Dati D;
	Indirizzo I;
	Elemento E;
	Tabella T;
	FILE* f1,* f2;

	int i, trovato, ins = 0, totC;
	unsigned int C;

	f1 = fopen("dati.txt", "r");
	if (f1 == NULL) {
		printf("File 'dati.txt' non trovato.");
		exit(1);
	}
	f2 = fopen("indirizzi.txt", "r");
	if (f2 == NULL) {
		printf("File 'indirizzi.txt' non trovato.");
		exit(1);
	}

	while (fscanf(f1, "%u%u", &D.matr, &D.CDL) == 2) {
		trovato = 0;
		rewind(f2);
		while (fscanf(f2, "%d %s %s %s %s %d", &I.matr, I.nome, I.cognome, I.via, I.citta, &I.CAP) == 6 && !trovato)
			if (I.matr == D.matr) {
				trovato = 1;
				E = riempiel(D, I);
				T[ins] = E;
				ins++;
			}
	}
	fclose(f1);
	fclose(f2);

	printf("Inserire il corso C: ");
	scanf_s("%u", &C);
	totC = 0;
	for (i = 0; i < ins; i++)
		if (T[i].CDL == C)
			totC++;

	printf("\n Iscritti al corso %u: %f %% \n", C, (float)totC * 100 / ins);

	printf("Inserire il corso C: ");
	scanf_s("%u", &C);
	totC = 0;
	for (i = 0; i < ins; i++)
		if (T[i].CDL == C)
			totC++;

	printf("\n Iscritti al corso %u: %f %% \n", C, (float)totC * 100 / ins);

	f1 = fopen("bologna.txt", "w");
	if (f1 == NULL) {
		printf("File 'prova.txt' non trovato.");
		exit(1);
	}
	for (i = 0; i < ins; i++)
		if (strcmp("bologna", T[i].citta) == 0)
			fprintf(f1, "%s %s %u\n", T[i].nome, T[i].cognome, T[i].matr);

	fclose(f1);
	return 0;
}

}

/*4) Compare tra due file.txt con struct*/void compare_files{
typedef struct {
	char titolo[31];
	float prezzo;
} film;

void load(FILE* f1, FILE* f2, film* y, int* num) {
	char titolo[31] = "";
	char sala1[21] = "";
	char sala2[21] = "";
	int orario;
	float p;
	*num = 0;

	while (fscanf(f1, "%s %s %d-%d-%d\n", titolo, sala1, &orario, &orario, &orario) == 5) {
		while ((fscanf(f2, "%s %f\n", sala2, &p) == 2) && (strcmp(sala1, sala2)));
		strcpy(y[*num].titolo, titolo);
		y[*num].prezzo = p;
		(*num)++;
		rewind(f2);
	}
}

int main() {
	FILE* f1,* f2;
	int N, i;
	float somma, media;
	film prezzi[DIM];

	if ((f1 = fopen("cineprogramma.txt", "r")) == NULL) {
		printf("Non sono riuscito ad aprire file1 in lettura!");
		exit(1);
	}
	if ((f2 = fopen("sale.txt", "r")) == NULL) {
		printf("Non sono riuscito ad aprire file2 in lettura!");
		exit(1);
	}

	load(f1, f2, prezzi, &N);
	fclose(f1);
	fclose(f2);

	somma = 0;
	for (i = 0; i < N; i++)
		somma = somma + prezzi[i].prezzo;
	media = somma / N;

	for (i = 0; i < N; i++)
		if (prezzi[i].prezzo < media)
			printf("Il costo del biglietto per il film %s e' %.2f \n", prezzi[i].titolo, prezzi[i].prezzo);

	return 0;
}
}

/*5) Compare file.txt con comando esterno */ void compare_ext{
typedef struct {
	char nome[31];
	float importo;
} Debito;

void load(FILE* f1, FILE* f2, Debito* y, int* num) {
	int codice1, codice2;
	char nome[31] = "";
	char citta[21] = "";
	char pagato;
	int num_fattura;
	float importo;

	*num = 0;

	while (fscanf(f1, "%d %s %s\n", &codice1, nome, citta) == 3) {
		while (fscanf(f2, "%d %d %f %c\n", &codice2, &num_fattura, &importo, &pagato) == 4)
			if ((codice1 == codice2) && (pagato == 'n')) {
				strcpy(y[*num].nome, nome);
				y[*num].importo = importo;
				(*num)++;
			}
		rewind(f2);
	}
}

int main() {
	FILE* f1,* f2;
	Debito debitori[DIM];
	int N, i, count, trovato;
	float somma;
	char nome[31] = "";

	if ((f1 = fopen("anagrafe.txt", "r")) == NULL) {
		printf("Non sono riuscito ad aprire file1 in lettura!");
		exit(1);
	}

	if ((f2 = fopen("fatture.txt", "r")) == NULL) {
		printf("Non sono riuscito ad aprire file2 in lettura!");
		exit(1);
	}

	load(f1, f2, debitori, &N);
	fclose(f1);
	fclose(f2);

	do {
		somma = 0;
		count = 0;
		trovato = 0;

		printf("Inserire nome cliente o digitare 'fine' per terminare: ");
		scanf_s("%s", nome, 30);

		for (i = 0; i < N; i++) {
			if (!strcmp(nome, debitori[i].nome)) {
				somma = somma + debitori[i].importo;
				count++;
				trovato = 1;
			}
		}

		if (!trovato && strcmp("fine", nome))
			printf("Cliente non in lista debitori.\n");
		else if (!trovato && !strcmp("fine", nome))
			printf("Chiusara programma.");

		if (trovato) {
			printf("N.ro fatture non pagate e importo totale (cliente %s): \n", nome);
			printf("%d --- %.2f\n", count, somma);
		}

	} while (strcmp("fine", nome) != 0);

	return 0;
}
}

/*6) Funzioni per file.dat */
int leggi(FILE* fp, SCRUCT* dest) {
	return fread(dest, sizeof(SCRUCT), 1, fp);
}
int scrivi(FILE* fp, SCRUCT src) {
	return fwrite(&src, sizeof(SCRUCT), 1, fp);
}

int leggi(FILE* fp, SCRUCT dest[], int dim, char* nome) {
	int temp_size = 0, size = 0, i;
	SCRUCT temp[DIM];

	while (fread(&temp[temp_size], sizeof(Azione), 1, fp) > 0 && temp_size < dim)
		temp_size++;

	for (i = 0; i < temp_size; i++) {
		if (strcmp(temp[i].nome, nome) == 0) {
			dest[size] = temp[i];
			size++;
		}
	}
	return size;
}
/*esempio*/int main{
if ((fp = fopen("azioni.dat", "wb")) == NULL)
exit(-1);
do {
	printf("Azione: inserisci nome, valore apertura, valore chiusura e giorno: ");
	scanf_s("%s %f %f %d", scritt.nome, 30, &(scritt.a_val), &(scritt.c_val), &(scritt.giorno));
	scrivi(fp, scritt);
	printf("Fine? (SI=1, NO=0) : ");
	scanf_s("%d", &fine);
} while (!fine);
fclose(fp);
} 

/*7) Lettura per file con separatore scelto */
int readField(char buffer[], int dim_buffer, char sep, FILE* f)
{
	int i = 0;
	char ch = fgetc(f);
	while (ch != sep && ch != '\n' && i < dim_buffer && ch != EOF) {
		buffer[i] = ch;
		i++;
		ch = fgetc(f);
	}
	buffer[i] = '\0';

	return ch;
}
void lettura(char nomefile[], SCRUCT v[], int* pindice) {
	SCRUCT x;
	BOOLEAN more = TRUE;
	FILE* f = fopen(nomefile, "r");
	*pindice = 0;
	if (f == NULL)
	{
		printf("Impossibile aprire file di ingresso");
		exit(1);
	}
	do
	{
		more = readField(x.cognome, 20, ';', f);
		more = more && readField(x.nome, 20, ';', f);		// qui sotto : doppia struttura
		if (fscanf(f, "%d/%d/%d %c\n", &x.nascita.giorno, &x.nascita.mese, &x.nascita.anno, &x.sesso) == 4)
			more = more && fscanf(f, "%d/%d/%d %c\n", &x.nascita.giorno, &x.nascita.mese, &x.nascita.anno, &x.sesso);

		if (more)
		{
			v[*pindice] = x;
			(*pindice)++;
		}
	} while (more);
	fclose(f);
}
int readElementFromFile(FILE* fp, Element* dest) {
	int result = OK;
	int i;
	char sepRead;
	int lettura1, lettura2;

	sepRead = readField(dest->matricola, 15, ';', fp);
	if (sepRead == ';' && result == OK)
		sepRead = readField(dest->cognome, 64, ';', fp);
	else result = OK;
	if (sepRead == ';' && result == OK)
		sepRead = readField(dest->nome, 64, ';', fp);
	else result = ERROR;
	if (sepRead == ';' && result == OK) {
		lettura1 = fscanf(fp, "%d", &(dest->nro_voti));
		dest->voti = (int*)malloc(sizeof(int) * dest->nro_voti);
		if (dest->voti != NULL) {
			for (i = 0; i < dest->nro_voti && result == OK; i++) {
				lettura2 = fscanf(fp, "%d", &((dest->voti)[i]));
				if (lettura2 != 1)
					result = ERROR;
			}
		}
		if (result == OK)
			fgetc(fp);
	}
	else result = ERROR;

	return result;
}

/*8) Compare tra file e dati esterni (vedi lettura su) */
int main()
{
	Persona elenco[NRO_PERS], utente;
	int indiceElenco = 0, i;
	FILE* fbin;

	lettura("PEOPLE.TXT", elenco, &indiceElenco);
	printf("\n\nNome e cognome: ");

	gets(utente.nome);
	gets(utente.cognome);

	printf("data di nascita (gg/mm/aaaa): ");
	scanf_s("%d/%d/%d",
		&utente.nascita.giorno,
		&utente.nascita.mese,
		&utente.nascita.anno);

	/* sopprime il fine linea rimasto sull'input */
	scanf_s("%*c");
	printf("Inserire il sesso (M/F): ");
	scanf_s("%c%*c", &utente.sesso, 1);

	fbin = fopen("PARTNERS.DAT", "wb");
	if (fbin == NULL)
	{
		printf("Impossibile aprire file di uscita\n");
		exit(2);
	}
	printf("Compatibili con %s %s:\n", utente.nome, utente.cognome);
	for (i = 0; i < indiceElenco; i++)
		if (compatibili(utente, elenco[i]))
		{
			fwrite(&elenco[i], sizeof(Persona), 1, fbin);
			printf("%s %s nato(a) il %d/%d/%d\n",
				elenco[i].nome,
				elenco[i].cognome,
				elenco[i].nascita.giorno,
				elenco[i].nascita.mese,
				elenco[i].nascita.anno);
		}
	fclose(fbin);
}
BOOLEAN compatibili(Persona p1, Persona p2) {
	BOOLEAN compSesso, compAnno;
	compSesso = (p1.sesso != p2.sesso);
	compAnno = abs(p1.nascita.anno - p2.nascita.anno) <= 5;
	return compSesso && compAnno;
}

/*9) Riempimento, lettura e stampa tra vettori e file con gestione errori */void file_vector_witherror{
#define MAXDIM 30
typedef enum { CRITICAL_ERROR_LOAD, NOT_ENOUGH_SPACE, LOAD_OK } LoadResult;
typedef enum { CRITICAL_ERROR_SAVE, SAVE_OK } SaveResult;
typedef enum { NOT_FOUNDED, FOUNDED } FindResult;

typedef struct authorStruct
{
	char name[20];
	char surname[20];
} Author;
typedef struct bookStruct
{
	int code;
	char title[20];
	Author auth;
	int copies;
} Book;

typedef Book BookShop[MAXDIM];

Author loadAuthor() {
	Author a;
	printf("author name: "); scanf_s("%s", a.name, 19);
	printf("author surname: "); scanf_s("%s", a.surname, 19);
	return a;
}
Book loadBook() {
	Book b;
	printf("book ID: "); scanf_s("%d", &b.code);
	printf("book title: "); scanf_s("%s", b.title, 19);
	b.auth = loadAuthor();
	printf("copies number: "); scanf_s("%d", &b.copies);
	return b;
}

LoadResult loadBookShop(BookShop shop, int* num, int maxdim)
{
	int i = 0;
	char get;
	do
	{
		if (i > maxdim)
			return NOT_ENOUGH_SPACE;
		printf("Inserisci un libro\n");
		shop[i] = loadBook();
		i++;
		printf("Altro libro (s/n)? ");
		get = getchar();
	} while (get == 's');
	*num = i;

	return LOAD_OK;
}
int compare(Book b1, Book b2)
{
	return b1.code - b2.code;
}
int binarySearch(BookShop shop, int dim, int toSearch)
{
	int midPos = dim / 2;
	int startPos;
	Book bookToSearch;

	bookToSearch.code = toSearch;

	if (compare(shop[midPos], bookToSearch) == 0)
		return midPos;
	if (midPos == 0)
		return 1;		//prima posizione
	if (compare(shop[midPos], bookToSearch) > 0)
		return binarySearch(shop, midPos, toSearch);
	else
	{
		startPos = midPos + 1;
		return startPos + binarySearch(&shop[startPos], dim - startPos, toSearch);
	}
}
FindResult findCode(BookShop shop, int dim)
{
	int code, pos;
	printf("Insert code: ");
	scanf_s("%d", &code);
	pos = binarySearch(shop, dim, code);
	if (pos < 0)
		return NOT_FOUNDED;
	printBook(shop[pos]);
	return FOUNDED;
}

int main()
{
	BookShop shop;
	int loaded;  // size
	char resp;
	LoadResult lRes;
	FindResult fRes;

	lRes = loadBookShop(shop, &loaded, MAXDIM);
	handleLoadResult(lRes);		// da inserire uno switch con stampa messaggi a seconda dei casi

	if (lRes != LOAD_OK)
		return 1;
	do
	{
		printf("p)\t print\n f)\t find\n e)\t exit\n");
		while (getchar() != '\n');
		resp = getchar();
		switch (resp)
		{
		case 'p':
			printBookShop(shop, loaded);
			break;
		case 'f':
			fRes = findCode(shop, loaded);
			handleFindResult(fRes);
			break;
		case 'e':
			break;
		}
	} while (resp != 'e');
	return 0;
}

SaveResult saveBookShop(BookShop shop, int dim, char* fileName)
{
	int i;
	FILE* f = fopen(fileName, "wb");
	if (f == NULL)
		return CRITICAL_ERROR_SAVE;
	for (i = 0; i < dim; i++)
		fwrite(&shop[i], sizeof(Book), 1, f);
	fclose(f);
}

LoadResult loadBookShopFromFile(BookShop shop, int* dim, char* fileName, int maxdim)
{
	int i = 0, result;
	FILE* f = fopen(fileName, "r");
	if (f == NULL)
		return CRITICAL_ERROR_LOAD;
	do
	{
		if (i > maxdim)
			return NOT_ENOUGH_SPACE;
		result = fread(&shop[i], sizeof(Book), 1, f);
		i++;
	} while (result > 0);
	*dim = i;
	return LOAD_OK;
}

}

/*10) Malloc conteggio numeri/dispari */
int readLength(FILE* f, int* even, int* odd) {
	int temp;
	*even = 0;      // meglio inizializzarli a zero
	*odd = 0;
	while (fread(&temp, sizeof(int), 1, f) == 1) {
		if ((temp % 2) == 0)
			(*even)++;
		else (*odd)++;
	}
	return *even + *odd;
}
int main()
{
	FILE* f;
	int odd, even;
	long int lung;
	int num;
	int* store;
	int i = 0, j = 0, temp;

	if ((f = fopen("valori.dat", "wb")) == NULL) {
		printf("Errore di apertura del file valori.dat");
		exit(-1);
	}
	do {
		printf("Inserire un numero: ");
		scanf_s("%d", &num);
		scrivi(f, num);
	} while (num != 0);

	fclose(f);

	if ((f = fopen("valori.dat", "rb")) == NULL) {
		printf("Errore di apertura del file valori.dat");
		exit(-1);
	}

	lung = readLength(f, &even, &odd);
	rewind(f);

	store = (int*)malloc(sizeof(int) * lung);
	while (fread(&temp, sizeof(int), 1, f) == 1) {
		if (temp % 2 == 0) {
			store[i] = temp;
			i++;
		}
		else {
			store[even + j] = temp;
			j++;
		}
	}

	fclose(f);

	for (i = 0; i < (lung); i++)
		printf("%d ", store[i]);

	free(store);
	return 0;
}

/*11) Scrittura e lettura valori con composizione malloc */void r_w_file_malloc{
typedef struct {
	char name[DIM];
	int points;
} User;

int scrivi(FILE* fp, User src) {
	if (fwrite(&src, sizeof(User), 2, fp) != 0)
		return 1;
	else return 0;
}

int occorenze(char A[], char B[]) {
	int result = 0;
	int trovato = 0;
	int i = 0, j = 0, temp;

	while (B[j] != '\0') {
		if (B[j] == A[i]) {
			trovato = 1;
			temp = j;
			while (A[i] != '\0' && trovato) {
				if (A[i] == B[j]) {
					i++;
					j++;
				}
				else {
					trovato = 0;
				}
			}
			if (trovato) {
				result++;
				printf("%s \n", B);
			}
			j = temp;
			i = 0;
		}
		j++;
	}
	return result;
}

int readPoints(char* usersFile, User results[], int maxDim, int minPoints) {
	FILE* f;
	int logicDim = 0;

	f = fopen(usersFile, "rb");
	if (f == NULL)
		return -1;

	while (logicDim < maxDim && fread(&results[logicDim], sizeof(User), 1, f) > 0) {
		if (results[logicDim].points >= minPoints)
			logicDim++;
	}

	fclose(f);
	return logicDim;
}

int main() {
	int num_users = 0;
	int esito, tot;
	int dimV, min_P, i, fine = 0;
	char A[3];
	User* V, temp;
	FILE* f;


	if ((f = fopen("punti.dat", "wb")) == NULL) {
		printf("Errore di apertura del file punti.dat");
		exit(-1);
	}
	do {
		printf("Inserire nome cliente e numero punti: ");
		scanf_s("%s %d", temp.name, DIM, &temp.points);
		esito = scrivi(f, temp);
		if (esito == 0)
			printf("Scrittura fallita\n");
		else {
			printf("Scritto!\n");
			num_users++;
			printf("Fine? (SI=1, NO=0) : ");
			scanf_s("%d", &fine);
		}
	} while (!fine);

	fclose(f);

	printf("\nNumero utenti registrati: %d", num_users);
	V = (User*)malloc(sizeof(User) * num_users);

	if ((f = fopen("punti.dat", "rb")) == NULL) {
		printf("Errore di apertura del file punti.dat");
		exit(-1);
	}

	printf("\nInserire il punteggio minimo da visualizzare: ");
	scanf_s("%d", &min_P);

	dimV = readPoints("punti.dat", V, num_users, min_P);

	fclose(f);

	printf("\nInserire due lettere iniziali: ");
	scanf_s("%s", A, 3);

	printf("\nClienti con lettere iniziali %s e %d punti:\n", A, min_P);
	for (i = 0; i < dimV; i++)
		tot = occorenze(A, V[i].name);     //print dei nomi incorporata in occorenze
	printf("Totali: %d", tot);

	free(V);
	return 0;
}

}

/*12) R/W file txt/bin con malloc e filtro vett. */void malloc_txt_bin_filtro{
#define BOOLEAN int
#define TRUE 1
#define FALSE 0

typedef struct
{
	char dicitura[36];
	int crediti;
	int voto;
} Esame;
typedef struct
{
	int nro_esami;
	Esame* esami;
} VettoreEsami;

BOOLEAN leggiEsamiTxt(char* nomeFile, VettoreEsami* vett) {
	FILE* fp;
	int i;
	int lettura1, lettura2;

	fp = fopen(nomeFile, "r");
	if (fp == NULL) {
		printf("Errore di apertura del file %s", nomeFile);
		return FALSE;
	}
	lettura1 = fscanf(fp, "%d", &(vett->nro_esami));
		if (lettura1 && vett->nro_esami > 0)
			vett->esami = (Esame*)malloc(sizeof(Esame) * vett->nro_esami);

	for (i = 0; i < vett->nro_esami; i++) {
		fgetc(fp);
		if (vett->esami != NULL) {
			lettura2 = fscanf(fp, "%35c%d%d", vett->esami[i].dicitura, &(vett->esami[i].crediti), &(vett->esami[i].voto));
			vett->esami[i].dicitura[35] = '\0';
		}
	}
	fclose(fp);
	return TRUE;
}
BOOLEAN leggiEsamiBin(char* nomeFile, VettoreEsami* vett) {
	FILE* fp;
	int i;
	int lettura1, lettura2;

	fp = fopen(nomeFile, "rb");
	if (fp == NULL) {
		printf("Errore di apertura del file %s", nomeFile);
		return FALSE;
	}
	lettura1 = fread(&(vett->nro_esami), sizeof(int), 1, fp);
	if (lettura1 && vett->nro_esami > 0)
		vett->esami = (Esame*)malloc(sizeof(Esame) * vett->nro_esami);

	if (vett->esami != NULL) {
	for (i = 0; i < vett->nro_esami; i++) {
		lettura2 = fread(&vett->esami[i], sizeof(Esame), 1, fp);
		vett->esami[i].dicitura[35] = '\0';
		}
	}
	fclose(fp);
	return TRUE;
}

void stampaEsami(VettoreEsami vett) {
	int i;
	printf("Numero esami: %d", vett.nro_esami);
	printf("Materia\tVoto\tCrediti:\n");
	for (i = 0; i < vett.nro_esami; i++) {
		printf("%s\t%d\t%d", vett.esami[i].dicitura, vett.esami[i].crediti, vett.esami[i].voto);
	}
}
float media(VettoreEsami vett) {
	int num = 0, den = 0, i;
	for (i = 0; i < vett.nro_esami; i++) {
		num = num + vett.esami[i].crediti * vett.esami[i].voto;
		den = den + vett.esami[i].crediti;
	}
	return ((float)num) / den;
}

BOOLEAN matches(char* str, char* pattern) {
	return (strstr(str, pattern) != NULL);
}
VettoreEsami filtra(VettoreEsami vett, char* pattern) {
	int i, j = 0, dimFiltro = 0;
	VettoreEsami filtro;

	for (i = 0; i < vett.nro_esami; i++) {
		if (matches(vett.esami[i].dicitura, pattern))
			dimFiltro++;
	}
	filtro.nro_esami = dimFiltro;
	if (dimFiltro > 0)
		filtro.esami = (Esame*)malloc(dimFiltro * sizeof(Esame));

		for (i = 0; i < vett.nro_esami; i++)
		{
			if (matches(vett.esami[i].dicitura, pattern))
			{
				filtro.esami[j] = vett.esami[i];
				j++;
			}
		}

	return filtro;
}

BOOLEAN salvaReport_txt(VettoreEsami vett, char* nomeFile) {
	int i;
	FILE* fp = fopen(nomeFile, "w");
	if (fp == NULL) {
		perror("errore durante il salvataggio: ");
		return FALSE;
	}
	for (i = 0; i < vett.nro_esami; i++)
		fprintf(fp, "%s (%d): %d\n", vett.esami[i].dicitura, vett.esami[i].crediti, vett.esami[i].voto);

	fprintf(fp, "MEDIA: %f", media(vett));
	fclose(fp);
	return TRUE;
}

BOOLEAN salvaReport_bin(VettoreEsami vett, char* nomeFile) {
	FILE* fp = fopen(nomeFile, "wb");
	if (fp == NULL)
	{
		perror("errore durante il salvataggio: ");
		return FALSE;
	}
	fwrite(&vett.nro_esami, sizeof(int), 1, fp);
	fwrite(vett.esami, sizeof(Esame), vett.nro_esami, fp);

	fclose(fp);
	return TRUE;
}
}

/*13) Incrocio file con creazione tramite memoria allocata */void malloc_doppiofile_bin_txt{

typedef struct {
	char tipo[11];
	char marca[11];
	float prezzo;
	int tot_venduti;
} Item;

typedef struct {
	char marca[11];
	float incasso;
} Income;

int leggi(FILE* fp, Item* dest, int size) {
	return fread(dest, sizeof(Item), size, fp);
}

Item* articoli(FILE* listino, FILE* venduti, int* len) {
	char tipo_temp[11] = "" , marca_temp[11] = "";
	Item* res,* resTemp, temp;
	*len = 0;

	while (fscanf(listino, "%s %s %f\n", temp.tipo, temp.marca, &(temp.prezzo)) == 3)
		(*len)++;

	res = (Item*)malloc(sizeof(Item) * (*len));
	resTemp = res;
	rewind(listino);

	while (fscanf(listino, "%s %s %f\n", temp.tipo, temp.marca, &(temp.prezzo)) == 3) {
		temp.tot_venduti = 0;
		while (fscanf(venduti, "%s %s\n", tipo_temp, marca_temp) == 2) {
			if (strcmp(temp.tipo, tipo_temp) == 0)
				if (strcmp(temp.marca, marca_temp) == 0)
					(temp.tot_venduti)++;
		}
		rewind(venduti);
		*(resTemp) = temp;
		resTemp++;
	}
	return res;
}

int scriviArticoli(char* nomeFileBinario, Item* vett, int len) {
	FILE* fp;
	int i;

	fp = fopen(nomeFileBinario, "wb");
	if (fp == NULL) {
		printf("Errore di apertura del file %s", nomeFileBinario);
		return 0;
	}
	for (i = 0; i < len; i++) {
		fwrite(vett + i, sizeof(Item), 1, fp);
	}

	fclose(fp);
	return 1;
}

Income* calcolaIncasso(Item* vett, int lenVett, int* lenIncasso) {
	Income* res;
	int i, j, trovato;
	*lenIncasso = 0;

	res = (Income*)malloc(sizeof(Income) * lenVett);

	for (i = 0; i < lenVett; i++) {
		trovato = 0;
		for (j = 0; j < *lenIncasso && trovato == 0; j++)
			if ((res + j) != NULL)
				if (strcmp((res + j)->marca, vett[i].marca) == 0)
				trovato = 1;
			if (trovato == 0 && (res + (*lenIncasso)) != NULL)
			{
				if ((vett[i].prezzo * vett[i].tot_venduti) != 0) {			//esclude il totale zero degli item NON venduti
					strcpy((res + (*lenIncasso))->marca, vett[i].marca);
					(res + (*lenIncasso))->incasso = (vett[i].prezzo * vett[i].tot_venduti);
					(*lenIncasso)++;
				}
			}
			else if ((res + j - 1) != NULL)
				(res + j - 1)->incasso += (vett[i].prezzo * vett[i].tot_venduti);
	}
	return res;
}

int main() {
	FILE* listino,* venduti,* lett;
	Item* art,* art1;
	Income* totale;
	int i, size, size2, scrittura;

	listino = fopen("listino.txt", "r");
	venduti = fopen("venduti.txt", "r");

	if (listino == NULL || venduti == NULL) {
		printf("Errore di apertura dei file");
		exit(-1);
	}

	art = articoli(listino, venduti, &size);

	scrittura = scriviArticoli("svertebrati.dat", art, size);

	lett = fopen("svertebrati.dat", "r");
	if (lett == NULL) {
		printf("Errore di apertura dei file");
		exit(-1);
	}
	if (size != 0)					// DA VERIFICARE!
		art1 = (Item*)malloc(sizeof(Item) * size);
	else art1 = (Item*)malloc(sizeof(Item));
	leggi(lett, art1, size);

	printf("Articoli venduti: \n");
	if (art1 != NULL) {
		for (i = 0; i < size; i++) {
			printf("%s %s %.2f %d \n", art1[i].tipo, art1[i].marca, art1[i].prezzo, art1[i].tot_venduti);
		}
	}

	totale = calcolaIncasso(art, size, &size2);
	printf("\nTotali venduti: \n");
	for (i = 0; i < size2; i++) {
		printf("%s %.2f\n", totale[i].marca, totale[i].incasso);
	}

	free(totale);
	free(art);
	free(art1);
	fclose(lett);
	fclose(listino);
	fclose(venduti);

	return 0;
}
}

/*14) Creazione file-scruct con nome personalizzato, ordinamento ed elimina duplicati vettore-scruct a più voci,
	  creazione vettore come calcolo di uno esistente*/ void scrivi_mergeS_eliminaDup_reso{

typedef struct {
	int viaggio;
	char tipo[DIMTIPO];
	float importo;
} Spesa;
typedef struct {
	int viaggio;
	Spesa* spese;
	int dim;
} Rimborso;

void scriviSpese(char* nomeFile) {
	FILE* fp;
	Spesa temp;
	char get;

	printf("Inserire la matricola: ");
	scanf_s("%s", nomeFile, 9);

	if (strlen(nomeFile) > 0 && strlen(nomeFile) <= 7)
		strcat(nomeFile, ".txt");
	else {
		printf("Errore nel trattare la matricola: %s.\n",nomeFile);
		get = getchar();
		exit(-1);
	}

	fp = fopen(nomeFile, "wt");

	if (fp == NULL) {
		printf("Errore nell'apertura del file: %s.\n", nomeFile);
		get = getchar();
		exit(-2);
	}

	printf("Inserire la spesa: ");
	scanf_s("%d%s%f", &(temp.viaggio), temp.tipo, DIMTIPO - 1, &(temp.importo));

	while (temp.viaggio != -1) {		// preferibile inserire un'altra variabile (tipo "fine") --- verificare funzionamento
		fprintf(fp, "%d %s %f\n", temp.viaggio, temp.tipo, temp.importo);
		printf("Inserire la spesa: ");
		scanf_s("%d%s%f", &(temp.viaggio), temp.tipo, DIMTIPO - 1, &(temp.importo));
	}

	printf("\nFile spese %s creato correttamente\n", nomeFile);
	fclose(fp);
	return;
}
Spesa* leggiSpese(char* nomeFile, int* dim) {
	FILE* fp;
	Spesa temp;
	Spesa* result,* resTemp;
	char get;
	*dim = 0;

	fp = fopen(nomeFile, "rt");
	if (fp == NULL) {
		printf("Errore nell'apertura in lettura del file %s.\n", nomeFile);
		get = getchar();
		exit(-3);
	}

	while (fscanf(fp, "%d%s%f", &(temp.viaggio), temp.tipo, &(temp.importo)) == 3)
		*dim = *dim + 1;

	result = (Spesa*)malloc(sizeof(Spesa) * (*dim));
	rewind(fp);

	resTemp = result;

	while (fscanf(fp, "%d%s%f", &(temp.viaggio), temp.tipo, &(temp.importo)) == 3) {
		(*resTemp) = temp;
		resTemp++;
	}

	fclose(fp);
	return result;
}

void mergeSort_i(Spesa* v, int first, int last, Spesa* vout) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort_i(v, first, mid, vout);
		mergeSort_i(v, mid + 1, last, vout);
		merge_i(v, first, mid + 1, last, vout);
	}
}
void merge_i(Spesa* v, int i1, int i2, int fine, Spesa* vout) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (compare2(v[i].viaggio, v[j].viaggio) < 0)
			swap(&vout[k], &v[i++]);
		else
			swap(&vout[k], &v[j++]);
		k++;
	}
	while (i <= i2 - 1) { swap(&vout[k], &v[i++]); k++; }
	while (j <= fine) { swap(&vout[k], &v[j++]); k++; }
	for (i = i1; i <= fine; i++) assign(&v[i], vout[i]);
}

void mergeSort_f(Spesa* v, int first, int last, Spesa* vout) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort_f(v, first, mid, vout);
		mergeSort_f(v, mid + 1, last, vout);
		merge_f(v, first, mid + 1, last, vout);
	}
}
void merge_f(Spesa* v, int i1, int i2, int fine, Spesa* vout) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (compare3(v[i].importo, v[j].importo) < 0)
			swap(&vout[k], &v[i++]);
		else
			swap(&vout[k], &v[j++]);
		k++;
	}
	while (i <= i2 - 1) { swap(&vout[k], &v[i++]); k++; }
	while (j <= fine) { swap(&vout[k], &v[j++]); k++; }
	for (i = i1; i <= fine; i++) assign(&v[i], vout[i]);
}

void mergeSort_s(Spesa* v, int first, int last, Spesa* vout) {
	int mid;
	if (first < last) {
		mid = (last + first) / 2;
		mergeSort_s(v, first, mid, vout);
		mergeSort_s(v, mid + 1, last, vout);
		merge_s(v, first, mid + 1, last, vout);
	}
}
void merge_s(Spesa* v, int i1, int i2, int fine, Spesa* vout) {
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		if (compare1(v[i].tipo, v[j].tipo) < 0)
			swap(&vout[k], &v[i++]);
		else
			swap(&vout[k], &v[j++]);
		k++;
	}
	while (i <= i2 - 1) { swap(&vout[k], &v[i++]); k++; }
	while (j <= fine) { swap(&vout[k], &v[j++]); k++; }
	for (i = i1; i <= fine; i++) assign(&v[i], vout[i]);
}


void swap(Spesa* e1, Spesa* e2)
{
	Spesa tmp;
	assign(&tmp, *e1);
	assign(e1, *e2);
	assign(e2, tmp);
}
void assign(Spesa* lvalue, Spesa rvalue)
{
	*lvalue = rvalue;
}
int compare1(char* e1, char* e2)
{
	return strcmp(e1, e2);
}
int compare2(int e1, int e2)
{
	return e1 - e2;
}
float compare3(float e1, float e2)
{
	return e1 - e2;
}

void ordina(Spesa* v, int dim) {
	Spesa* temp;
	int i, j;

	temp = (Spesa*)malloc(sizeof(Spesa) * dim);

	mergeSort_i(v, 0, dim - 1, temp);

	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			if (v[i].viaggio == v[j].viaggio)
				mergeSort_s(v, i, j, temp);
		}
	}

	for (i = 0; i < dim; i++) {
		for (j = 0; j < dim; j++) {
			if (strcmp(v[i].tipo, v[j].tipo) == 0 && (v[i].viaggio == v[j].viaggio))
				mergeSort_f(v, i, j, temp);
		}
	}


	free(temp);
}

int compare_dup(Spesa s1, Spesa s2) {
	int temp;
	temp = s1.viaggio - s2.viaggio;
	if (temp == 0)
		temp = strcmp(s1.tipo, s2.tipo);
	if (temp == 0)
		if (s1.importo - s2.importo < 0)
			temp = -1;
		else
			if (s1.importo == s2.importo)
				temp = 0;
			else
				temp = 1;
	return temp;
}
Spesa* eliminaDuplicati(Spesa* v, int dim, int* dimNew) {
	Spesa* result;
	int i, j;
	int trovato;

	result = (Spesa*)malloc(sizeof(Spesa) * dim);
	*dimNew = 0;

	for (i = 0; i < dim; i++) {
		trovato = 0;
		for (j = 0; j < *dimNew && !trovato; j++)
			if (compare_dup(v[i], result[j]) == 0)
				trovato = 1;
		if (!trovato && result != NULL) {
			result[*dimNew] = v[i];
			(*dimNew)++;
		}
	}

	return result;
}

int contaViaggi(Spesa* v, int dim) {
	// funziona SOLO SE v e’ ordinato in base al viaggio
	int result;
	int i;
	if (dim > 0) {
		result = 1;
		for (i = 1; i < dim; i++)
			if (v[i].viaggio != v[i - 1].viaggio)
				result++;
	}
	else
		result = 0;
	return result;
}
Rimborso* creaRimborsi(Spesa* v, int dim, int* dimRimborsi) {
	Rimborso temp;
	Rimborso* result;
	int start, end, count = 0;
	int i, j, k;
	float calc = 0.0;

	//ricordarsi di ordinare in caso non venga fatto --> ordina(v, dim);

	*dimRimborsi = contaViaggi(v, dim);
	result = (Rimborso*)malloc(sizeof(Rimborso) * (*dimRimborsi));

	start = 0; end = 0; j = 0;
	while (end < dim) {
		while (end < dim && v[end].viaggio == v[start].viaggio)
			end++;
		if (start != end) {
			temp.viaggio = v[start].viaggio;
			temp.spese = (Spesa*)malloc(sizeof(Spesa) * (end - start));
			for (i = start; i < end; i++) {
				temp.spese[i - start].viaggio = v[i].viaggio;
				strcpy(temp.spese[i - start].tipo, v[i].tipo);
				for (k = 0; k < dim; k++) {
					if (v[i].viaggio == v[k].viaggio)
						calc += v[k].importo;
				}
				temp.spese[i - start].importo = calc;
				calc = 0.0;
			}
			temp.dim = end - start;
		}
		start = end;
		if (result != NULL) {
			result[j] = temp;
		}
		j++;
	}

	return result;
}


int main() {
	//char nome[9] = "";
	int size, size2, size3, i;
	Spesa* gen,* gen2;
	Rimborso* rim;

	//scriviSpese(nome);
	gen = leggiSpese("030405.txt", &size);

	//printf("\nFile %s generato: \n", nome);
	for (i = 0; i < size; i++)
		printf("%d %s %.2f\n", gen[i].viaggio, gen[i].tipo, gen[i].importo);

	printf("\nFile ordinato: \n");
	ordina(gen, size);
	for (i = 0; i < size; i++)
		printf("%d %s %.2f\n", gen[i].viaggio, gen[i].tipo, gen[i].importo);

	gen2 = eliminaDuplicati(gen, size, &size2);

	printf("\nFile ordinato senza duplicati: \n");
	for (i = 0; i < size2; i++)
		printf("%d %s %.2f\n", gen2[i].viaggio, gen2[i].tipo, gen2[i].importo);

	rim = creaRimborsi(gen2, size2, &size3);
	printf("\nTotale rimborsi: \n");
	for (i = 0; i < size3; i++)
		printf("%d %.2f\n", rim[i].viaggio, rim[i].spese->importo);

	return 0;
}
	  }
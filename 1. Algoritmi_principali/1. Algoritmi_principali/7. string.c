

/*1) Concatenamento stringhe*/ int conc(char s1[], char s2[], char dest[]) {
	int result = 0;

	while (*s1 != '\0') {
		*dest = *s1;
		dest++; 
		s1++; 
		result++;
	}

	while (*s2 != '\0') {
		*dest = *s2;
		dest++; s2++; result++;
	}
	*dest = '\0';
	return result;
}

/*2) Abbreviazione stringha*/int componiIndirizzo(char* cognome, char* nome, char* nome_cognome, int maxChars) {
	int requiredChars;
	int size;
	resultType result;
	strcpy(nome_cognome, ""); //inizializzazione...
	requiredChars = strlen(cognome) + 1 + strlen(nome);
	if (requiredChars < maxChars)
		result = RESULT_OK;
	else {
		requiredChars = strlen(cognome) + 3;
		if (requiredChars < maxChars)
			result = RESULT_COMPRESSED_NAME;
		else
			result = RESULT_ADDRESS_TOO_LONG;
	}
	if (result == RESULT_OK || result == RESULT_COMPRESSED_NAME) {
		strcat(nome_cognome, cognome);
		strcat(nome_cognome, " ");
		if (result == RESULT_OK)
			strcat(nome_cognome, nome);
		else {
			size = strlen(nome_cognome);
			nome_cognome[size] = nome[0];
			nome_cognome[size + 1] = '.';
			nome_cognome[size + 2] = '\0';
		}
	}
	return result;
}
void handleError(int result) {
	switch (result) {
	case RESULT_OK:
		printf("Nessun errore occorso!\n"); break;
	case RESULT_ADDRESS_TOO_LONG:
		printf("L'indirizzo e' troppo lungo...\n"); break;
	case RESULT_COMPRESSED_NAME:
		printf("Il nome e' stato compresso...\n"); break;
	default:
		printf("Unknown Error!\n");
	}
}

/*3) Occorenze in stringa*/ int occorenze(char A[], char B[]) {
	int result = 0;
	int trovato = 0;
	int i = 0, j = 0, temp;

	while (B[j] != '\0') {							// B = tre tigri contro tre tigri		
		if (B[j] == A[i]) {							// A = tr
			trovato = 1;
			temp = j; // *
			while (A[i] != '\0' && trovato) {
				if (A[i] == B[j]) {
					i++;
					j++;
				}
				else {
					trovato = 0;
				}
			}
			if (trovato)
				result++;
			j = temp;  // * permette di calcolare eventuali occorrenze che si succedono (per es: 
			i = 0;			//  B = bbbbbbbb  e  A = bb , allora result = 7 )
		}
		j++;
	}
	return result;
}

/*4) Print ricorsiva carattere*/ void printchar(char stringa[]) {
	char c_line = stringa[0];

	if (c_line != '\0') {
		printf("%c\n", c_line);
		printchar(&(stringa[1]));
	}
}

/*5) Print parte intera/decimale di un nro*/ int stampaDettagli(float num, int p_int, int p_dec) {
	char stringaFormato[MAX_FORMATO];
	int nCarInt, nCarDec;
	RESULT result;

	nCarInt = ((int)log10(p_int)) + 1;
	nCarDec = ((int)log10(p_dec)) + 1;
	if ((nCarInt + nCarDec + 6) >= MAX_FORMATO)
		result = RESULT_TOO_MANY_CHARS;
	else
	{
		sprintf(stringaFormato, "%%%d.%df\n", p_int, p_dec);
		printf("Formato: %s\n", stringaFormato);
		printf(stringaFormato, num);
		result = RESULT_OK;
	}
	return result;
}
void handleError(int result, char* str)
{
	switch (result)
	{
	case RESULT_OK:
		strcpy(str, "");
		break;
	case RESULT_TOO_MANY_CHARS:
		strcpy(str, "Stringa di formato con troppi caratteri\n");
		break;
	default:
		strcpy(str, "Risultato non gestito.\n");
	}
}

/*6) Print la parte "secret" in maiuscolo*/ BOOLEAN identifica(char* msg, char* secret, char* result) {
	while ((*msg != '\0') && (*secret != '\0')) {
		if (*msg == *secret) {
			secret++;
			*result = *msg - 'a' + 'A';
		}
		else
			*result = *msg;
		msg++;
		result++;
	}
	if (!*secret)
		while (*msg != '\0') {
			*result = *msg;
			msg++;
			result++;
		}
	*result = '\0';
	return (!*secret);
}
int main(void) {
	char result[MAX];
	int i = 0;

	struct messaggio { char mex[MAX], secret[MAX]; } M;

	printf("Inserire messaggio: ");
	while (M.mex[i] != '.') {
		scanf_s("%c", &M.mex[i], MAX);
		i++;
	}
	M.mex[i] = '\0';
	//*M.mex = '\0'; Inserisce il terminatore al posto del primo elemento

	i = 0;
	printf("Inserire segreto: ");
	while (M.secret[i] != '.') {
		scanf_s("%c", &M.secret[i], MAX);
		i++;
	}
	M.secret[i] = '\0';
	//*M.secret = '\0'; Inserisce il terminatore al posto del primo elemento

	identifica(M.mex, M.secret, result);

	printf("Messaggio segreto: %s", result);

	return 0;
}

/*7) Compilazione array tipo scruct classico*/ int main() {
	typedef struct corso { char nome[21]; char prof[16]; int iscritti; } Corso;
	int i, nc, limit;
	float somma, media;
	Corso corsi[N];

	printf("Inserisci il numero dei corsi: ");
	scanf_s("%d", &nc);

	limit = (nc < N) ? nc : N;
	/* inserimento dati */
	for (i = 0; i < limit; i++) {
		printf("Inserisci il nome del corso ");
		scanf_s("%s", corsi[i].nome, 21);

		printf("Inserisci il cognome del docente ");
		scanf_s("%s", corsi[i].prof, 16);

		printf("Inserisci il numero degli iscritti");
		scanf_s("%d", &corsi[i].iscritti);
	}
	somma = 0;
	for (i = 0; i < limit; i++)
		somma = somma + corsi[i].iscritti;
	media = somma / limit;
	for (i = 0; i < limit; i++)
		if (corsi[i].iscritti >= media)
			printf("%s %s\n", corsi[i].nome, corsi[i].prof);

	return 0;
}

/*8) Compilazione array tipo scruct con terminatore*/ int lettura(item prezzi[], int dim_max, int* dim1) {
	typedef struct { char name[N]; float old_price; float new_price; } item;
	char name[N];
	*dim1 = 0;

	printf("Inserire nome prodotto: ");
	scanf_s("%s", name, N);
	*name = *name + '\0';

	while ((strcmp(name, "fine")) && (*dim1 < dim_max)) {
		strcpy(prezzi[*dim1].name, name);
		printf("Inserire old price: ");
		scanf_s("%f", &prezzi[*dim1].old_price);

		printf("Inserire new price: ");
		scanf_s("%f%*c", &prezzi[*dim1].new_price);  /* %*c per escludere caratteri che non siano numeri*/

		(*dim1)++;

		printf("Inserire nome prodotto: ");
		scanf_s("%s", name, N);
	}
	return 0;
}
int main() {
	item v[MAX_ITEM];
	int num, i, result;
	float infl;

	result = lettura(v, MAX_ITEM, &num);
	if (result != 0) {
		printf("Problemi durante la lettura...\n");
	}
	else {
		for (i = 0; i < num; i++) {
			infl = (v[i].new_price / v[i].old_price - 1) * 100;
			printf("Inflazione del prodotto %s: %6.2f%%\n", v[i].name, infl);  /*dove %%\n indica che verrà visualizzato proprio il simbolo e il valore in percentuale*/
		}
	}
	return 0;
}

/*9) Lettura e sottrazione tra tempi*/ time leggi_T() {
	time result;
	printf("Inserire i secondi: ");
	scanf_s("%d", &result.ore);
	printf("Inserire i minuti: ");
	scanf_s("%d", &result.min);
	printf("Inserire le ore: ");
	scanf_s("%d", &result.sec);

	return result;
}
int leggi_moreT(time v[], int dim) {
	int tot = 0;
	time temp;

	do {
		temp = leggi_T();
		if (temp.ore >= 0 && tot < dim) {
			v[tot] = temp;
			tot++;
		}
	} while (temp.ore >= 0 && tot < dim);

	return tot;
}
time subtract(time t1, time t2) {
	int s1, s2, sResult;
	time result;

	s1 = t1.ore * 3600 + t1.min * 60 + t1.sec;
	s2 = t2.ore * 3600 + t2.min * 60 + t2.sec;
	sResult = s1 - s2;
	result.ore = sResult / 3600;
	sResult = sResult % 3600;
	result.min = sResult / 60;
	sResult = sResult % 60;
	result.sec = sResult;

	return result;
}

/*10) Lettura e assegnamento scruct con condizioni*/ int leggi(booking* dest) {

	printf("Inserire il nome: ");
	scanf_s("%s", (*dest).name, MAX);

	if (strcmp("fine", dest->name) == 0)
		return 0;
	else if (strcmp("stampa", dest->name) == 0)
		return -1;

	else {
		printf("Posto preferito: ");
		scanf_s("%d", &(dest->seat));	/* &d(dest->seat) corrisponde ad un versione semplificata di  &((*dest).seat)  */
		return 1;
	}
}
int assegna(booking list[], int* size_list, int dim, char* name, int pref) {
	int i = 0;
	int libero = 0;

	while (i < *size_list && libero == 0) {
		if (list[i].seat == pref)
			libero = 1;
		i++;
	}
	if (libero == 0 && *size_list < dim) {
		strcpy_s(list[*size_list].name, MAX, name);
		list[*size_list].seat = pref;
		(*size_list)++;
		return 0;
	}
	else return 1;
}
int main() {

	booking cliente;
	booking lista_pren[DIM];
	int size_list = 0, i;
	int lettura;



	do {
		lettura = leggi(&cliente);
		if (lettura == 1) {
			if (assegna(lista_pren, &size_list, DIM, cliente.name, cliente.seat) == 1)
				printf("Posto occupato. Reinserire i dati con un altro posto preferito\n");
			else
				printf("Prenotazione eseguita\n");
		}
		else if (lettura == -1 || size_list == DIM) {
			printf("\nLista prenotazioni:\n");
			printf("  %4s%25s\n", "Nome", "N.mro posto");
			for (i = 0; i < size_list; i++) {
				printf("- %4s%21d\n", lista_pren[i].name, lista_pren[i].seat);
			}
		}
	} while (lettura != 0 && lettura != -1 && size_list < DIM);

	return 0;
}

/*11) Min e max tra strutture */
Azione trovaMin(Azione src[], int dim, float* val) {
	int i;
	Azione result;
	result = src[0];

	if (result.a_val < result.c_val)
		*val = result.a_val;
	else
		*val = result.c_val;
	for (i = 1; i < dim; i++) {
		if (src[i].a_val < *val) {
			*val = src[i].c_val;
			result = src[i];
		}
		if (src[i].c_val < *val) {
			*val = src[i].c_val;
			result = src[i];
		}
	}
	return result;
}
Azione trovaMax(Azione src[], int dim, float* val) {
	int i;
	Azione result;
	*val = -1;
	result = src[0];

	for (i = 0; i < dim; i++) {
		if (src[i].a_val > *val) {
			*val = src[i].a_val;
			result = src[i];
		}
		if (src[i].c_val > *val) {
			*val = src[i].c_val;
			result = src[i];
		}
	}
	return result;
}
float media(Azione src[], int dim) {
	int tot = 0;
	int i;
	float sum = 0;
	for (i = 0; i < dim; i++) {
		sum = sum + src[i].a_val + src[i].c_val;
		tot += 2;
	}
	return sum / tot;
}



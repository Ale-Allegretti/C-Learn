

/*1) Riempi/svuota liste con soglia*/ int main(void) {
	FILE* fp;
	list startList, lowList, highList, temp;
	Element voto, soglia;

	if ((fp = fopen("voti.txt", "r")) == NULL) {
		perror("The file does not exist!");
		exit(-1);
	}

	startList = emptyList();
	lowList = emptyList();
	highList = emptyList();

	while (fscanf(fp, "%d", &voto) > 0)
		startList = cons(voto, startList);
	fclose(fp);

	showList(startList);

	printf("Inserire soglia: ");
	scanf_s("%d", &soglia);


	while (!empty(startList)) {
		Element value = head(startList);
		if (value < soglia)
			lowList = cons(value, lowList);
		else
			highList = cons(value, highList);
		startList = tail(startList);
	}

	showList(lowList);
	showList(highList);

	// DEALLOCAZIONE

	while (!empty(startList)) {
		temp = startList;
		startList = tail(startList);
		free(temp);
	}

	while (!empty(lowList)) {
		temp = lowList;
		lowList = tail(lowList);
		free(temp);
	}

	while (!empty(highList)) {
		temp = highList;
		highList = tail(highList);
		free(temp);
	}

	return (0);
}

/*2) Cerca el., intersezione e differenza tra liste*/ void contains_inter_diff{
BOOLEAN contains1(list l, Element e) {

	BOOLEAN found = FALSE;
	while (!empty(l) && !found)
	{
		found = (head(l) == e);
		l = tail(l);
	}
	return found;
}
BOOLEAN contains2(list l, Element e) {		//senza primitive
	BOOLEAN found = FALSE;
	while (l != NULL && !found)
	{
		found = (l->value == e);
		l = l->next;
	}
	return found;
}

list intersect(list l1, list l2) {
	Element value;
	list l3 = emptyList();

	while (!empty(l1)) {
		value = head(l1);
		if (contains1(l2, value) && !contains1(l3, value))
				l3 = cons(value, l3);
		l1 = tail(l1);
	}
	return l3;
}

list diff(list l1, list l2) {		//senza primitive
	Element value;
	list l3 = NULL, temp;

	while (l1 != NULL) {
		value = l1->value;
		if (!contains2(l2, value) && !contains2(l3, value)) {
			temp = (list)malloc(sizeof(item));
			if (temp != NULL) {
				temp->value = value;
				temp->next = temp;
				l3 = temp;
			}
		}
		l1 = l1->next;
	}
	return l3;
}
}

/*3) Cross tra due liste, generandone una terza*/void cross {

	//esempio:    l1(1,3,4)   l2(10, 20, 30, 40, 50) --> l3(10, 30, 40)
int select(list l, unsigned int pos) {
	if (empty(l))
		return -1;
	else if (pos == 1)
		return head(l);
	else return select(tail(l), pos - 1);
}
list crossSelection(list l1, list l2) {
	if (empty(l1))
		return emptyList();
	else
		return cons(select(l2, head(l1)), crossSelection(tail(l1), l2));
}
}

/*4.1) Riempi lista con vett-struct e file*/int main() {
	FILE* fp;
	Archivio V[DIM];
	list L = emptyList();
	list L_inv = emptyList();
	int i = 0, size = 0;
	int disponibili, max, inv, pos = 0;
	float ratio;

	if ((fp = fopen("archivio.txt", "r")) == NULL) {
		perror("Il file non esiste!");
		exit(-1);
	}

	while (fscanf(fp, "%s %s %d %d", V[i].autore, V[i].titolo, &(V[i].num_possedute), &(V[i].num_prestito)) == 4 && size < DIM) {
		i++;
		size++;
	}

	fclose(fp);

	for (i = 0; i < size; i++) {
		printf("%s %s %d %d \n", V[i].autore, V[i].titolo, V[i].num_possedute, V[i].num_prestito);
	}

	for (i = 0; i < size; i++) {
		disponibili = V[i].num_possedute - V[i].num_prestito;
		L = cons(disponibili, L);
	}

	while (!empty(L)) {				// necessario invertire ordine lista (LIFO)
		inv = head(L);
		L_inv = cons(inv, L_inv);
		L = tail(L);
	}
	showList(L_inv);


	i = 0;
	while (!empty(L_inv) && i < size) {
		disponibili = head(L_inv);
		ratio = ((float)disponibili / V[i].num_possedute) * 100;
		printf("Percentuale di disponibilita' del libro %s: %%%.2f \n", V[i].titolo, ratio);
		L_inv = tail(L_inv);
		i++;
	}

	max = -1;
	i = 0;
	while (!empty(L)) {
		if (head(L) > max)
		{
			max = head(L);
			pos = i;
		}
		L = tail(L);
		i++;
	}
	printf("\nRiga di archivio.txt con piu' copie disponibili: %d", (size - pos - 1));

	return 0;
}

/*4.2) Riempi lista direttamente da file */ list leggiIngredienti(char* fileName) {
	FILE* fp;
	char nome[MAX] = "";
	float prezzo;
	Element temp;
	list result = emptyList();

	if ((fp = fopen(fileName, "r")) == NULL)
		return result;
	while (fscanf(fp, "%s %f", nome, &prezzo) == 2)
	{
		strcpy(temp.nome, nome);
		temp.prezzo = prezzo;
		result = cons(temp, result);
	}

	fclose(fp);
	return result;
}

/*5) Lista con condizione e lett/scritt file bin*/void list_filebin_struct{
int scrivi(FILE * fp, Work src) {
	return fwrite(&src, sizeof(Work), 1, fp);
}
list findBills(char* fileName, char* clientName) {
	FILE* fWorks;
	list result;
	Work temp;

	if ((fWorks = fopen(fileName, "rb")) == NULL)
	{
		printf("Error opening the file %s\n", fileName);
		exit(-1);
	}
	result = emptyList();
	while (fread(&temp, sizeof(Work), 1, fWorks) == 1)
		if (strcmp(temp.name, clientName) == 0)
			result = cons(temp.bill, result);
	fclose(fWorks);
	return result;

}
int main() {
	FILE* fImp,* fClients;
	list tempBill;
	Work temp;
	float totalBill;
	char fileClients[DIM] = "", fileImp[DIM] = "", clientName[DIM];
	int fine1 = 0, fine2 = 1;

	//creazione FILE BINARIO importi
	do {
		printf("Inserire nome del mese: ");
		scanf_s("%s", fileImp, DIM - 1);
		fImp = fopen(fileImp, "wb");
		if (fImp == NULL)
			exit(-1);
		do {
			printf("%s: cliente, giorno, importo: ", fileImp);
			scanf_s("%s %d %f", temp.name, DIM - 1, &(temp.day), &(temp.bill));
			scrivi(fImp, temp);
			printf("Fine? (SI=1, NO=0) : ");
			scanf_s("%d", &fine1);
		} while (!fine1);
		fclose(fImp);
		printf("Inserire altro mese? (SI=1, NO=0) : ");
		scanf_s("%d", &fine2);
	} while (fine2);

	printf("Inserire il nome del file dei clienti: ");
	scanf_s("%s", fileClients, DIM - 1);

	if ((fClients = fopen(fileClients, "r")) == NULL)
	{
		printf("Error opening the file %s\n", fileClients);
		exit(-1);
	}

	while (fscanf(fClients, "%s %s", clientName, fileImp) == 2)
	{
		totalBill = 0;
		tempBill = findBills(fileImp, clientName);
		printf("%s: ", clientName);
		showList(tempBill);
		while (!empty(tempBill))
		{
			totalBill = totalBill + head(tempBill);
			tempBill = tail(tempBill);					//tempBill andrebbe deallocata - possibile memory-leak
		}												//andrebbe riscritto in modo tale da poterlo fare			
		printf(" Total bill: %.2f\n", totalBill);		// se c'è structur sharing (approfondire) non è possibile de-allocamento
	}													// lasciare un commento 

	fclose(fClients);

	return 0;
}

}

/*6) Riempi lista da file, aggiorna file da lista, find elemento con condizione*/void file_list_update__find{
void printGames(list games) {
	if (!empty(games)) {
		Element temp = head(games);
		printf("%d) %s \t(%c) %d \t%f\n", temp.cod, temp.titolo, temp.id, temp.disponibili, temp.voto);
		printGames(tail(games));
	}
}

boolean loadFromFile(char* fileName, list * games) {
	FILE* fp = fopen(fileName, "r");
	Element temp;

	if (fp == NULL) {
		printf("Error opening the file %s\n", fileName);
		return 0;
	}
	while (fscanf(fp, "%d%31c%c%d%f", &temp.cod, temp.titolo, &temp.id, &temp.disponibili, &temp.voto) == 5) {
		temp.titolo[31] = '\0';
		*games = cons(temp, *games);
	}
	fclose(fp);
	return 1;
}

Element * findElementByCode(list games, int code)
{
	list cur;
	Element* found = NULL;
	cur = games;
	while (cur != NULL && found == NULL)
	{
		if (cur->value.cod == code)
			found = &cur->value;
		else
			cur = cur->next;
	}
	return found;
}
boolean updateAvailability(char* fileName, list games) {
	FILE* fp = fopen(fileName, "r");
	int codice;
	Element* game;

	if (fp == NULL) {
		printf("Error opening the file %s\n", fileName);
		return 0;
	}
	while (fscanf(fp, "%d", &codice) != 1)
	{
		game = findElementByCode(games, codice);
		if (game != NULL)
			game->disponibili--;
		else
			printf("CODICE NON RICONOSCIUTO: %d\n", codice);
	}
	fclose(fp);
	return 1;
}

list gamesForKids(list games, float threshold)
{
	list kids;
	Element game;
	if (empty(games))
		return emptyList();
	kids = gamesForKids(tail(games), threshold);
	game = head(games);
	if (game.disponibili > 0 && game.id != 'P' && (game.id == 'A' || game.voto >= threshold))
	{
		kids = cons(game, kids);
	}
	return kids;
}

boolean saveOrdersToFile(char* fileName, list games, int qty) {
	FILE* fp;
	int orderNumber;
	Element game;
	list gamesToRead = games;

	if ((fp = fopen(fileName, "w")) == NULL)
	{
		perror("Error opening file: ");
		return 0;
	}
	while (!empty(gamesToRead)) {
		game = head(gamesToRead);
		orderNumber = qty - game.disponibili;
		if (orderNumber > 0)
			fprintf(fp, "%d %s %d\n", game.cod, game.titolo, orderNumber);
		gamesToRead = tail(gamesToRead);
	}
	fclose(fp);
	return 1;
}

int main()
{
	list games = emptyList();
	list kids = emptyList();
	list temp;

	loadFromFile("lista.txt", &games);
	printGames(games);
	printf("-------UPDATE-------\n");
	updateAvailability("acquisti.txt", games);
	printGames(games);
	printf("-------G4KIDS-------\n");
	kids = gamesForKids(games, 4);
	printGames(kids);
	saveOrdersToFile("ordine.txt", games, 5);

	while (!empty(games)) {
		temp = games;
		games = tail(games);
		free(temp);
	}
	while (!empty(kids)) {
		temp = kids;
		kids = tail(kids);
		free(temp);
	}

	return 0;
}

}

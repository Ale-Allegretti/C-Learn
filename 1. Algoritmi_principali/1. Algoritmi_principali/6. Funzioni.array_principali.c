
int pari(int n) {
	if (n % 2 == 0)
		return 1;
	else return 0;
}

int ins_values(int v[], int dim) {
	int num;
	int size = 0;
	do
	{
		printf("Inserire un valore: ");
		scanf_s("%d", &num);
		if (num != 0 && size < dim) {
			v[size] = num;
			size++;
		}
	} while (num != 0 && size < dim);
	return size;
}

void search1(int v[], int dim, int k) {
	int i;
	for (i = 0; i < dim; i++) {
		if (v[i] == k)
			printf("Trovato il valore %d all'indice %d\n", k, i);
	}
}

int search2(int v[], int dim, int el, int* pos) {
	int i;
	int found = 0;
	for (i = 0; i < dim && !found; i++) {
		if (v[i] == el) {
			found = 1;
			*pos = i;
		}
	}
	return found;
}

int search3(int v[], int dim, int el) {
	int i;
	int found = -1;
	for (i = 0; i < dim && found < 0; i++) {
		if (v[i] == el) {
			found = i;
		}
	}
	return found;
}

int eliminaRipetuti(int v[], int dim_v, int single[], int dim_s) {
	int size_s = 0;
	int i, j, trovato;
	for (i = 0; i < dim_v && size_s < dim_s; i++) {
		trovato = 0;
		for (j = 0; j < size_s && !trovato; j++) {
			if (v[i] == single[j])
				trovato = 1;
		}
		if (!trovato) {
			single[size_s] = v[i];
			size_s++;
		}
	}
	return size_s;
}

int* first_last(int v[], int size_v, int first, int last, int* dim) {
	int i = 0;
	int* result;

	while (i < size_v && first > v[i]) {
		i++;
	}
	result = &(v[i]);				//con result comunico l'inizio del nuovo vettore

	*dim = 0;
	while (i < size_v && last >= v[i]) {
		i++;
		*dim = *dim + 1;		//con dim, passata comunque per rif, comunico la sua fine
	}
	return result;
}


/*ricorsive*/
void print(int list[], int length) {
	if (length > 0)
	{
		print(list, length - 1);
		printf("%d\n", list[length - 1]);
	}
}

int som_disp1(int v[], int size, int pos) {
	if (pos >= size)
		return 0;
	else
		return v[pos] + som_disp1(v, size, pos + 2);
}
int som_disp(int v[], int size) {
	return som_disp1(v, size, 1);
}

void somme2(int l1[], int length) {
	if (length < 3)
		return;
	else {
		if (l1[0] == l1[1] + l1[2])
			printf("%d ", l1[0]);
		somme2(&(l1[1]), length - 1);
	}
}


/*con definizione di errore*/

#define RESULT int				// è possibile cambiare velocemente il tipo a seconda della necessità
#define TYPE int

#define DIFFERENT_LENGTH -1
#define EQUAL 0
#define DIFFERENT 1

#define BOOLEAN int
#define TRUE 1
#define FALSE 0

BOOLEAN equals(TYPE el1, TYPE el2) {
	return(el1 == el2); //uguaglianza dipendente dal tipo
}

/*compare el. non ripetuti, ma nello stesso ordine*/
RESULT compareTo1(TYPE v1[], TYPE v2[], int dim1, int dim2) {
	int i;
	RESULT result;
	if (dim1 != dim2)
		result = DIFFERENT_LENGTH;
	else {
		result = EQUAL;
		for (i = 0; i < dim1 && result == EQUAL; i++) {
			if (!equals(v1[i], v2[i]))
				result = DIFFERENT;
		}
	}
	return result;
}

/*compare el. non ripetuti, ma in ordine diverso*/
RESULT compareTo2(TYPE v1[], TYPE v2[], int dim1, int dim2) {
	int i, j;
	BOOLEAN currentEquality = TRUE;
	RESULT result;
	if (dim1 != dim2)
		result = DIFFERENT_LENGTH;
	else {
		for (i = 0; i < dim1 && currentEquality; i++) {
			currentEquality = FALSE;
			for (j = 0; j < dim2 && !currentEquality; j++) {
				currentEquality = equals(v1[i], v2[j]);
			}
		}
		if (currentEquality)
			result = EQUAL;
		else
			result = DIFFERENT;
	}
	return result;
}

/*compare el. anche ripetuti e in ordine diverso*/
RESULT compareTo3(TYPE v1[], TYPE v2[], int dim1, int dim2)
{
	BOOLEAN checked[MAX_DIM];
	BOOLEAN currentEquality = TRUE;
	RESULT result;
	int i, j;

	if (dim1 != dim2)
		result = DIFFERENT_LENGTH;
	else {
		for (i = 0; i < dim1; i++) //uso la dimensione logica
			checked[i] = FALSE;
		for (i = 0; i < dim1 && currentEquality; i++) {
			currentEquality = FALSE;
			for (j = 0; j < dim2 && !currentEquality; j++) {
				if (!checked[j]) {
					currentEquality = equals(v1[i], v2[j]);
					if (currentEquality) {
						checked[j] = TRUE;
					}
				}
			}
		}
		if (currentEquality)
			result = EQUAL;
		else
			result = DIFFERENT;
	}
	return result;
}
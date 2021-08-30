#include "ingredienti.h"
#define N 65

typedef struct {
	char nome[N];
	int num;
	Element ing[10];
} Pizza;

double calcolaPrezzo(Pizza ordinata, list l1);


#include "pizza.h"

double calcolaPrezzo(Pizza ordinata, list l1) {
	double result = 0, temp;
	int i;

	for (i = 0; i < ordinata.num; i++) {
		temp = trovaPrezzo(ordinata.ing[i].nome, l1);
		if (temp <= 0)
			result = 0;
		else 
			result = result + temp;
	}
	return result;
}


#include <math.h>

int mioMin(int a, int b) {

	if (a < b) return a;
	else return b;
}
int mioMax(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

int MCD(int m, int n) {

	int result;
	if (m == n)
		result = m;
	else if (m > n)
		result = MCD(m - n, n);
	else
		result = MCD(m, n - m);

	return result;
}
int mcm(int m, int n) {

	return (m * n) / MCD(m, n);

}


int Sommatoriaric(int x) {
	if (x == 0) return x;
	else
		if (x > 0) return x + Sommatoriaric(x - 1);
		else
			if (x < 0) return x + Sommatoriaric(x + 1);
}
/*sommatoria di sommatoria ricorsiva*/
int somma1(int n) {
	int k, tot1;
	tot1 = 0;
	for (k = 1; k <= n; k++)
		tot1 = tot1 + k;
	return tot1;
}
int somma2(int n) {
	int i, tot2;
	tot2 = 0;
	for (i = 1; i <= n; i++)
		tot2 = tot2 + somma1(i);
	return tot2;
}


int isPrimo(int x) {

	int i, resto = 0;

	if (x == 1)
		return 0;
	else {
		if (x == 2)
			return 1;
		else {
			i = 2;
			do {
				resto = x % i;
				i++;
			} while ((resto != 0) && (i < x));
			return (resto != 0);
		}
	}
}
float calcuteCharges(float hours) {
	float i;
	float charge = 2.0F;

	if (hours >= 24.0F)
		charge = 10.00F;
	else if (hours >= 1.0F && hours <= 3.0F) {
		return charge;
	}
	else if (hours > 3.0F && hours < 24.0F) {
		i = hours - 3.0F;
		charge = charge + (0.5F * i);
	}
	return charge;
}
/*int main() {

	float h1, h2, h3, totH;
	float tot1, tot2, tot3, totM;

	printf("Inserire le ore del cliente 1: ");
	scanf_s("%f", &h1);
	tot1 = calcuteCharges(h1);

	printf("\nInserire le ore del cliente 2: ");
	scanf_s("%f", &h2);
	tot2 = calcuteCharges(h2);

	printf("\nInserire le ore del cliente 3: ");
	scanf_s("%f", &h3);
	tot3 = calcuteCharges(h3);

	totM = tot1 + tot2 + tot3;
	totH = h1 + h2 + h3;

	printf("\n%4s%10s%21s\n", "Car", "Hours", "Guadagno totale");
	printf("\n%4s%10.1f%21.2f\n", "1", h1, tot1);
	printf("\n%4s%10.1f%21.2f\n", "2", h2, tot2);
	printf("\n%4s%10.1f%21.2f\n", "3", h3, tot3);
	printf("\n%4s%10.1f%21.2f\n", "TOTAL", totH, totM);

} */
/*ricerca del numero perfetto: */
/*#include <stdio.h>
#include <math.h>

#define NUM_perfetto 1
#define NUM_nonperfetto 0


int gen_perfect(double n) {
	int perf;
	return perf = (int)(pow(2, (n - 1.0F)) * (pow(2, n) - 1));
}
int perfect(int x) {
	int i, perf = NUM_nonperfetto;
	for (i = 2; i < x; i++) {
		if (x == gen_perfect(i))
			perf = NUM_perfetto;
	}
	return perf;
}

int main() {
	int x, y, tot1;
	long int num = 2, tot2;

	printf("Inserire numero: ");
	scanf_s("%d", &x);

	tot1 = perfect(x);
	switch (tot1)
	{
	case NUM_perfetto:
		printf("Il numero e' perfetto\n");
		break;
	case NUM_nonperfetto:
		printf("Il numero non e' perfetto\n");
		break;
	}

	printf("Inserire un limite per generare numeri perfetti: ");
	scanf_s("%d", &y);
	printf("I numeri perfetti fino a %d sono: \n", y);
	do {
		tot2 = gen_perfect(num);
		printf("%d ", tot2);
		num++;
	} while (tot2 < y);
}*/


int reverse(int num) {
	return reverseRic(num, 0);
}
int reverseRic(int num, int part) {
	if (num == 0)
		return part;
	else {
		return reverseRic(num / 10, part * 10 + num % 10);
	}
}


double logaritmo(float x, int b) {
	double result;
	if (x > 0.0 && b > 0)
		return result = log(x) / log(b);
	else
		return result = 0;
}
/*potenza iterativa*/ int potenza2(int z) {
	int i, prod;
	prod = 1;
	for (i = 1; i <= 2; i++) {
		prod = prod * z;
	}
	return prod;
}
/*sommatoria di potenza iterativa*/int sommaPotenze(int a, int n) {
	int i, prod, som;
	prod = 1;
	som = 0;
	for (i = 1; i <= n; i++) {
		prod = prod * a;
		som = som + prod;
	}
	return som;
}


int fact(int x) {
	int fatt = 1, index;
	for (index = x; index > 0; index--)
		fatt = fatt * index;
	return fatt;
}
int fact_bin(int x, int y) {
	return fact(x) / (fact(y) * (fact(x - y)));
}
/*fattoriale binomiale con errori definiti: */
/*#include <stdio.h>
#define FATTORIALE_RET_TYPE int
#define BINOMIALE_RET_TYPE int
#define SUCCESS 0
#define PARAM_NEGATIVE -1
#define BINOMIALE_INCORRECT_PARAMS -5


FATTORIALE_RET_TYPE fattoriale(int n, int* result)
{
	int fact = 1, index;
	if (n < 0) // CONTROLLO DEI PARAMETRI
	{
		return PARAM_NEGATIVE;
	}
	else
	{
		for (index = n; index > 0; index--)
			fact = fact * index;
		*result = fact;
		return SUCCESS;
	}
}

BINOMIALE_RET_TYPE binomiale(int n, int k, int* result)
{
	int numeratore, denominatore1, denominatore2, funOK;
	funOK = fattoriale(n, &numeratore);
	if (funOK == SUCCESS) {
		funOK = fattoriale(k, &denominatore1);
		if (funOK == SUCCESS) {
			funOK = fattoriale(n - k, &denominatore2);
			if (funOK == SUCCESS) {
				*result = numeratore / (denominatore1 * denominatore2);
				return SUCCESS;
			}
			else return BINOMIALE_INCORRECT_PARAMS;
		}
		else return funOK;
	}
	else return funOK;
}

int main() {
	int x, tot;

	printf("Inserire i due coefficenti binomiali: ");
	scanf_s("%d", &x);

	fattoriale(x, &tot);

	printf("Calcolo: %d", tot);
}*/


/*operazioni triangoli*/
float perimetro(float a, float b, float c) {
	return a + b + c;
}
float area(float a, float b, float c) {

	float per, ar;

	per = perimetro(a, b, c);

	ar = (float)sqrt((per) * (per - a) * (per - b) * (per - c));
	return ar;
}
int isTerna(int a, int b, int c) {

	int cateto1, cateto2, ipotenusa;
	int prod;

	cateto1 = mioMin(a, b);
	cateto2 = mioMin(a + b - cateto1, c);
	ipotenusa = a + b + c - cateto1 - cateto2;
	prod = cateto1 * cateto1 + cateto2 * cateto2;

	if (prod == ipotenusa * ipotenusa)
		return 1;
	else
		return 0;
}
/*per Terna int main() {

	int i, j, k;
	int limit;

	printf("Inserire il valore limite: ");
	scanf_s("%d", &limit);

	for (i = 1; i <= limit; i++) {
		for (j = 1; j <= i; j++) {
			for (k = 1; k <= j; k++) {
				if (isTerna(i, j, k))
					printf("Terna: %d %d %d\n", i, j, k);
			}
		}
	}

	return 0;
} */
/*calcolo di un triangolo con errori definiti*/
/*
#include <stdio.h>
#include <math.h>

#define CALCULATE_RET_TYPE int
#define TRIANGOLO_NV1 -1
#define TRIANGOLO_NV2 -2
#define TRIANGOLO_OK 0

CALCULATE_RET_TYPE calculate(double a, double b, double c, double* area, double* perimeter)
{
	double s;
	if (a < 0 || b < 0 || c < 0 || a > b + c || b > a + c || c > a + b)
		return TRIANGOLO_NV1;
	if (a == 0 || b == 0 || c == 0 || a == b + c || b == a + c
		|| c == a + b)
		return TRIANGOLO_NV2;
	*perimeter = a + b + c;
	s = *perimeter / 2;
	*area = sqrt(s * (s - a) * (s - b) * (s - c));
	return TRIANGOLO_OK;
}

void printCalculation(double a, double b, double c)
{
	double area, perimeter;
	CALCULATE_RET_TYPE result;
	result = calculate(a, b, c, &area, &perimeter);
	switch (result)
	{
	case TRIANGOLO_NV1:
		printf("Triangolo non valido\n");
		break;
	case TRIANGOLO_NV2:
		printf("Triangolo limite\n");
		break;
	case TRIANGOLO_OK:
		printf("Perimetro: %.2f, Area: %.2f\n", perimeter, area);
	}
}

int main() {
	float a, b, c;

	printf("Inserire i tre lati: ");
	scanf_s("%f %f %f", &a, &b, &c);

	printCalculation(a, b, c);

}*/


/*integrali ricorsivi e iterarivi - da definire sempre f(x)*/
double f(double x) {
	return sin(x);
}
double rettangoliIt(double a, double b, int n) {
	double delta;
	double result = 0;
	delta = (b - a) / n; // possibile errore di rappresentazione
	while (a + delta <= b) {
		result = result + (delta * f(a));
		a = a + delta;
	}
	return result;
}
double rettangoliRic(double a, double b, int n) {
	double delta;
	if (n <= 0)
		return 0;
	else {
		delta = (b - a) / n;
		return delta * f(a) + rettangoliRic(a + delta, b, n - 1);
	}
}
double trapeziIt(double a, double b, int n) {
	double delta;
	double result = 0;
	delta = (b - a) / n; // possibile errore di rappresentazione
	while (n > 0) {
		if (n > 1)
			result = result + (f(a) + f(a + delta)) * (delta) / 2;
		else
			result = result + (f(a) + f(b)) * (b - a) / 2;
		a = a + delta;
		n = n - 1;
	}
	return result;
}
double trapeziRic(double a, double b, int n) {
	double delta;
	if (n <= 0)
		return 0;
	else {
		delta = (b - a) / n;
		return (delta * (f(a) + f(a + delta))) / 2 + trapeziRic(a + delta, b, n - 1);
	}
}




/*
int reverseChars2() {
	char c;
	int partialResult;
	c = getchar();
	if (c == '\n')
		return 0;
	else {
		partialResult = reverseChars2();
		printf("%c", c);
		return partialResult + 1;
	}
} */
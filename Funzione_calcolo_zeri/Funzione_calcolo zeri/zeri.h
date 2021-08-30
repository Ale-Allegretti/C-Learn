
#define CODICEUSCITA int
#define OK 0
#define TROPPEITERAZIONI 1
#define INTERVALLONONVALIDO 2


void printCodiceUscita(CODICEUSCITA code);

CODICEUSCITA bisezione(double a, double b, int maxIterazioni, double epsilon, double* xZero);
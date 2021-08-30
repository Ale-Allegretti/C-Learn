
#include <stdio.h>
#include "zeri.h"
#include "common.h"
#include "funzione.h"


void printCodiceUscita(CODICEUSCITA code)
{
	switch (code)
	{
	case OK: printf("Ok.");
		break;
	case TROPPEITERAZIONI: printf("Troppe iterazioni.");
		break;
	case INTERVALLONONVALIDO: printf("Intervallo non valido.");
		break;
	default: printf("Codice sconosciuto.");
		break;
	}
}

double doubleAbs(double value)
{
	return ((value < 0) ? -value : value);
}


CODICEUSCITA bisezione(double a, double b, int maxIterazioni, double epsilon, double* xZero)
{
	int i;
	double xa, xb; //Estremi correnti
	double fa, fb; //Valori di f agli estremi correnti
	double xm, fm; //Valore medio estremi + corrisp. valore di f
	BOOLEAN stop = FALSE;

	if (a > b)
	{ //Estremi non ordinati --> scambiare
		xb = a;
		xa = b;
	}
	else
	{
		xa = a;
		xb = b;
	}
	if (funzione(xa) * funzione(xb) >= 0)
	{
		return INTERVALLONONVALIDO;
	}
	for (i = 0; i < maxIterazioni && !stop; i++)
	{
		fa = funzione(xa);
		fb = funzione(xb);
		xm = (xa + xb) / 2;
		fm = funzione(xm);
		if (fm * fa < 0)
			xb = xm;
		else
			xa = xm;
		stop = ((fm == 0.0) || (doubleAbs(xb - xa) < epsilon));
	}
	if (stop)
	{
		*xZero = xm;
		return OK;
	}
	else
	{
		return TROPPEITERAZIONI;
	}
}

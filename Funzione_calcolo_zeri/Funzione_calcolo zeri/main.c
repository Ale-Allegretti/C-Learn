#include <stdio.h>
#include <math.h>
#include "common.h"
#include "zeri.h"

int main(void)
{
	double zero;
	CODICEUSCITA code;
	code = bisezione(0, 2, 30, 0.0001, &zero);

	if (code == OK)
	{
		printf("Zero: %.10f\n\n", zero);
	}
	else
	{
		printCodiceUscita(code);
		printf("\n\n");
	}
	return (0);
}
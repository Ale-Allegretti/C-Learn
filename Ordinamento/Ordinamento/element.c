
#include "element.h"
#include <stdio.h>
#include <string.h>		//necessario se il tipo è stringa

int compareCounter = 0;
int swapCounter = 0;

void incrementCompareCounter()
{
	compareCounter++;
}

void incrementSwapCounter()
{
	swapCounter++;
}

void assign(Element* lvalue, Element rvalue)
{
	*lvalue = rvalue;
}

void swap(Element* e1, Element* e2)
{
	Element tmp;
	assign(&tmp, *e1);
	assign(e1, *e2);
	assign(e2, tmp);
	incrementSwapCounter();
}

/*
int compare(Element e1, Element e2)
{
	incrementCompareCounter();
	return e1 - e2;
}
*/

void printElement(Element e)
{
	printf(" %s\n", e);			// per le stringhe sostituire con %s
}

int compare(Element e1, Element e2)
{
	incrementCompareCounter();
	return strcmp(e1, e2);
}
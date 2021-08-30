
#include "el_def.h"		// sostituire con "char_def.h" in caso si lavori con stringhe

#ifndef ELEMENT
#define ELEMENT
int compare(Element e1, Element e2);
void swap(Element* e1, Element* e2);
void assign(Element* lvalue, Element rvalue);
void printElement(Element e);
void printStatistics();
#endif


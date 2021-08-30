#pragma once
#ifndef LISTH
#define LISTH

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "element_Allegretti_Alessandro_0000974745.h"


typedef struct list_element {
	Element value; struct list_element* next; } item;

typedef item* list;

typedef int boolean;

/* PRIMITIVE  */
list emptyList(void);
boolean empty(list);
list cons(Element, list);
Element head(list);
list tail(list);
void freelist(list l);
void printElement(Element el);
void showList2(list l);

int equals(Element el1, Element el2);
int compareElement(Element el1, Element el2);
boolean member(Element el, list l);
list insord(Element el, list l);
list eliminaRipetuti(list l);

#endif
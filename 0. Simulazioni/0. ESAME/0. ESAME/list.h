// Allegretti Alessandro - Matricola: 0000974745 - MODULO 2

#pragma once
#ifndef LISTH
#define LISTH

#include "element.h"


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
void showList(list l);


#endif
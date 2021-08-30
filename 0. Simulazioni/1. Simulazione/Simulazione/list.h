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

void showList(list l);
void freelist(list l);
int member(Element el, list l);

//list insord_p(element el, list l);

#endif
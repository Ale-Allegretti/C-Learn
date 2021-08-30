/*
* Mantovani Federico 0000977019 Prova 1A
*
*/
#pragma once
#ifndef LIST_H
#define LIST_H
#include "element.h"

typedef struct list_element { // nodo
	negozio value; // valore del nodo, in questo esempio un int
	struct list_element* next; // puntatore al prossimo nodo della lista
}item;

typedef item* list;
typedef int boolean; // non c'entra ma è utile

/* Funzioni primitive */
list emptyList();
boolean isEmpty(list l);
list addToHead(negozio el, list l); // costruttore
negozio head(list l);
list tail(list l);

void showList(list l);
list append(list l1, list l2);
int length(list l);
list reverse(list l);
void freelist(list l);
list copy(list l);
boolean member(negozio el, list l);
//int member(int v, list l); TODO //list insord_p(int v, list l); // non so cosa sia
#endif
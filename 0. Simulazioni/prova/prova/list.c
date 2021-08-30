/*
* Mantovani Federico 0000977019 Prova 1A
*
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "element.h"
/* Funzioni primitive */

list emptyList() { // costruttore lista vuota
	return NULL;
}

boolean isEmpty(list l) { /* verifica se la lista è vuota */
	return (l == NULL);
}

list addToHead(negozio el, list l) {
	list t; /* costruttore che aggiunge in testa alla lista */
	t = (list)malloc(sizeof(item));
	t->value = el;
	t->next = l;
	return (t);
}

negozio head(list l) { // selettore testa lista
	if (isEmpty(l)) exit(-2); // lista vuota
	else return (l->value);
}

list tail(list l) { // selettore coda lista
	if (isEmpty(l)) exit(-1);
	else return(l->next);
}

/* Funzioni non primitive */

void showList(list l) {
	negozio tmp;
	if (!isEmpty(l)) {
		tmp = head(l);
		printNegozio(tmp);
		showList(tail(l));
		return;
	} else {
		printf("\n");
	}
}

int length(list l) {
	int n = 0;
	while (!isEmpty(l)) {
		n++; 
		l = tail(l);
	}
	return n;
}

list append(list l1, list l2) {
	if (isEmpty(l1)) return l2;
	else return addToHead(head(l1), append(tail(l1), l2));
}

list reverse(list l) {
	if (isEmpty(l)) return emptyList();
	else return append(reverse(tail(l)),
		addToHead(head(l), emptyList()));
}

void freelist(list l) {
	if (isEmpty(l))
		return;
	else {
		freelist(tail(l));
		free(l);
	}
	return;
}

list copy(list l) {
	if (isEmpty(l)) return l;
	else return addToHead(head(l), copy(tail(l)));
}

boolean member(negozio el, list l) {
	/*while (!isEmpty(l)) {
		if (el == head(l)) return 1;
		else l = tail(l);
	} return 0;*/
}


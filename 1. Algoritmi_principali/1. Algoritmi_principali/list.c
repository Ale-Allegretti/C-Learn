#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/* OPERAZIONI PRIMITIVE */
list emptyList(void)		/* costruttore lista vuota */
{
	return NULL;
}

boolean empty(list l)	/* verifica se lista vuota */
{
	return (l == NULL);
} 

list cons(Element e, list l) {
	list t;       /* costruttore che aggiunge in testa alla lista */
	t = (list)malloc(sizeof(item));
	if (t != NULL) {
		t->value = e;
		t->next = l;
	}
	return(t);
}

Element head(list l) /* selettore testa lista */
{
	if (empty(l)) exit(-2);
	else return (l->value);
}

list tail(list l)         /* selettore coda lista */
{
	if (empty(l)) exit(-1);
	else return (l->next);
}

void showList(list l) {
	Element temp;
	if (!empty(l)) {
		temp = head(l);
		printf("%.2f \n", temp);
		showList(tail(l));
		return;
	}
	else {
		printf("\n\n");
		return;
	}
}

void freelist(list l) {
	if (empty(l))
		return;
	else {
		freelist(tail(l));
		free(l);
	}
	return;
}

/*
int member(element el, list l) {
	int result = 0;
	while (!empty(l) && !result) {
		result = (el.id == head(l).id);
		if (!result)
			l = tail(l);
	}
	return result;
}
*/

/*
list insord_p(element el, list l) {
	list pprec = NULL, patt = l, paux;
int trovato = 0;

	while (patt != NULL && !trovato) {
		if (el.costo > patt->value.costo)
				trovato = 1;
		else {
			pprec = patt;
			patt = patt->next;
		}
	}
	paux = (list)malloc(sizeof(item));
	paux->value = el;
	paux->next = patt;
	if (patt == l)
		return paux;
	else {		pprec->next = paux;
		return l;
	}
}
*/
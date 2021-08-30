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

void freelist(list l) {
	if (empty(l))
		return;
	else {
		freelist(tail(l));
		free(l);
	}
	return;
}

void printElement(Element el) {
	printf("%d\t%s\t%s", el.id, el.s_ing, el.s_usc);
}
void showList2(list l) {
	/* VERSIONE ITERATIVA: */
	while (!empty(l)) {
		printElement(head(l));
		printf("\n");
		l = tail(l);
	}
}

// funzioni LIST aggiuntive, personalizzate per la struct in questione

int equals(Element el1, Element el2) {
	if (strcmp(el1.s_ing, el2.s_ing) == 0 && strcmp(el1.s_usc, el2.s_ing) == 0 && el1.id == el2.id)
		return 1;
	else
		return 0;
}

boolean member(Element el, list l)
{
	if (empty(l)) 
		return 0;
	else {
		if (equals(el, head(l))) 
			return 1;
		else 
			return member(el, tail(l));
	}
}
// Allegretti Alessandro - Matricola: 0000974745 - MODULO 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

/* OPERAZIONI PRIMITIVE */
list emptyList(void)		
{
	return NULL;
}

boolean empty(list l)	
{
	return (l == NULL);
} 

list cons(Element e, list l) {
	list t;       
	t = (list)malloc(sizeof(item));
	if (t != NULL) {
		t->value = e;
		t->next = l;
	}
	return(t);
}

Element head(list l) 
{
	if (empty(l)) exit(-2);
	else return (l->value);
}

list tail(list l)         
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

void showList(list l) {
	Element temp;
	if (!empty(l)) {
		temp = head(l);
		printf("Nome negozio: %s\t\tTipo: %c\n", temp.nome, temp.tipo);
		showList(tail(l));
		return;
	}
	else {
		printf("\n\n");
		return;
	}
}

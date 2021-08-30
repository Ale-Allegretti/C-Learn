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

// funzioni LIST aggiuntive, personalizzate per la struct in questione
/*
int equals(Element el1, Element el2) {
	if (strcmp(el1.matricola, el2.matricola) == 0 && strcmp(el1.cognome, el2.cognome) == 0 &&
		strcmp(el1.nome, el2.nome) == 0)
		return 1;
	else
		return 0;
}
int compareElement(Element el1, Element el2) {
	int result;
	result = strcmp(el1.cognome, el2.cognome);
	if (result == 0) {
		result = strcmp(el1.nome, el2.nome);
		if (result == 0) {
			result = strcmp(el1.matricola, el2.matricola);
			if (result == 0) {
				if (el1.nro_voti < el2.nro_voti)
					result = -1;
				else
					if (el1.nro_voti > el2.nro_voti)
						result = 1;
			}
		}
	}
	return result;

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
list insord(Element el, list l) {
	if (empty(l)) 
		return cons(el, l);
	else if (compareElement(el, head(l)) <= 0) 
		return cons(el, l);
	else 
		return cons(head(l), insord(el, tail(l)));
}

list eliminaRipetuti(list l) {
	list lOrd = emptyList();
	list result = emptyList();
	list temp;

	while (!empty(l)) { // ordino la lista
		lOrd = insord(head(l), lOrd);
		l = tail(l);
	}
	temp = lOrd; // elimino i ripetuti
	while (!empty(lOrd)) {
		if (!member(head(lOrd), tail(lOrd)))
			result = insord(head(lOrd), result);
		lOrd = tail(lOrd);
	}
	lOrd = temp; //de-alloco la lista temporanea lOrd
	while (!empty(lOrd)) {
		temp = tail(lOrd);
		free(lOrd);
		lOrd = temp;
	}
	return result;
}	*/
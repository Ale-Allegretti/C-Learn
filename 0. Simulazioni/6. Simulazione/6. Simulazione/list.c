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
	int i;
	if (!empty(l)) {
		temp = head(l);
		printf("%d %c %.2f %d %d ", temp.id, temp.tipo, temp.mq, temp.piano, temp.vani);
		for (i = 0; i < temp.vani; i++)
			printf("%.2f ", temp.calp[i]);
		printf("\n");
		showList(tail(l));
		return;
	}
	else {
		printf("\n\n");
		return;
	}
}


// funzioni LIST aggiuntive, personalizzate per la struct in questione

/*
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
} */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

list leggiIngredienti(char* fileName);

int scriviIngredienti(char* fileName, list l1);

double trovaPrezzo(char* nomeIng, list l1);

list aggiornaPrezzo(list l1, char* nomeIng, double newP);
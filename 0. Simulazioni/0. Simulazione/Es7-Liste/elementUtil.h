#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

#define READ_CODE int
#define OK 1
#define ERROR 0

void printElement(Element el);
void showList2(list l);


int readField(char buffer[], int dim_buffer, char sep, FILE* f);
READ_CODE readElementFromFile(FILE* fp, Element* dest);


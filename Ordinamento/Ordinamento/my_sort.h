
#include "element.h"
#include "common_def.h"	

void printArray(Array a, int dim);

void scambia(Element* a, Element* b);
int trovaPosMax(Array v, int size_v);

void naiveSort(Array v, int size_v);

void bubbleSort(Array v, int size_v);

void insertSort(Array v, int size_v);
void insOrd(Array v, int pos);

void mergeSort(Array v, int first, int last, Array vout);
void merge(Array v, int i1, int i2, int fine, Array vout);

void quickSort(Array v, int dim);
void quickSortR(Array v, int iniz, int fine);
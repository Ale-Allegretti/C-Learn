
#include "my_sort.h"
#include <stdio.h>



int main(void) {
	Array v;

	v[0] = "Gino";
	v[1] = "Carla";
	v[2] = "Alessandro"; 
	v[3] = "Bino";

	quickSort(v, 4);
	printArray(v, 4);


	return (0);
}
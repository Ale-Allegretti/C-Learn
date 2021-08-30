#ifndef ELEMENTH
#define ELEMENTH
#define DIM 2048
#define NCOMP 10

typedef struct {
	int id;
	char contenuto[DIM];
	char tipo;
	int disp;
	float costo;
} Set;

typedef struct {
	int id;
	int semplici[NCOMP];		//array di soli id semplici
	int size;
} Complex;

typedef Set Element;


#endif
#ifndef ELEMENTH
#define ELEMENTH
#define DIM 256

typedef struct {
	int id;
	char s_ing[DIM];
	char s_usc[DIM];
} Evento;

typedef struct {
	float costo;
	char s_ing[DIM];
	char s_usc[DIM];
} Tariffa;

typedef Evento Element;


#endif
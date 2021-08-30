#ifndef ELEMENTH
#define ELEMENTH
#define DIM 10

typedef struct {
	int min;
	int hour;
} Time;

typedef struct {
	Time inizio;
	Time fine;
} Event;

typedef struct {
	int cod;
	char nome[20];
	Event impegni[DIM];
	int nEventi;
} Worker;

typedef struct {
	int tot;
	int cod;
	int min;
} Request;

typedef Worker Element;

#endif
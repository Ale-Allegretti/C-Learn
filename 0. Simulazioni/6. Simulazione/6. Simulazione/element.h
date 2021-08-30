#define _CRT_SECURE_NO_WARNINGS
#pragma once

#ifndef ELEMENTH
#define ELEMENTH
#define DIM 2048

typedef struct {
	int id;
	char tipo;
	float mq;
	int piano;
	int vani;   //max 5
	float calp[5];
} Appartamento;

typedef struct {
	int id;
	char nom_cog[DIM];
	float offerta;
} Offerta;


typedef Appartamento Element;


#endif
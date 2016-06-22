#pragma once

#define MAX_CAR 100+1
#define MAX_ELEM 1000
#define MAX_CITTA 5
#define MAX_PERCORSO 1000

typedef struct{
	double x;
	double y;
}coordinate;

typedef struct{
	char nomeCitta[MAX_CAR];
	char nomeRegione[MAX_CAR];
	int abitanti;
	double superficie;
	coordinate coord;
}luoghi;

typedef struct{
    luoghi citta[MAX_ELEM];
    int numCitta;
}paese;

typedef struct{
    char percorsoHtml[MAX_PERCORSO];
    char percorsoPdf[MAX_PERCORSO];
}config;
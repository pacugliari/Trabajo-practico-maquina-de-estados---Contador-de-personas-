
#ifndef CODIGO_LIB_LIB_H_
#define CODIGO_LIB_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  espera,
  puertaCerrada,
  puertaAbierta
}estados_t;

typedef enum{
	true = 1,
	false = 0,
	error = 2
}bool;

typedef struct {
	int contador;
	bool sensor1;
	bool sensor2;
	int limiteMaximoPersonas;
}personas_t;


personas_t inicio(void);
personas_t seteo(char*);
/*
estados_t puertaAbierta(personas_t);
estados_t puertaCerrada(personas_t);
estados_t espera(personas_t);*/


#endif

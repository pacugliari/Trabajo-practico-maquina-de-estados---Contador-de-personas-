
#ifndef CODIGO_LIB_LIB_H_
#define CODIGO_LIB_LIB_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  espera=0,
  puertaCerrada=1,
  puertaAbierta=2
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


estados_t funcionPuertaAbierta(personas_t*);
estados_t funcionPuertaCerrada(personas_t*);
estados_t funcionEspera(personas_t*);


#endif

#include "../lib/lib.h"


void mensajePuertaAbierta(void){
	printf("La puerta se encuentra abierta al publico \n");
}

void mensajePuertaCerrada(void){
	printf("La puerta se encuentra cerrada al publico, espere que salga alguna persona \n");
}

void mensajeContador(personas_t* personas){
	printf ("La cantidad de personas dentro es: %d \n",personas->contador);
	printf("La cantidad maxima permitida dentro es: %d \n",personas->limiteMaximoPersonas);
}

int leerIngreso (void){
	int ingreso;
	do{
		scanf("%d",&ingreso);
		if (ingreso > 1 || ingreso < 0)
			printf ("Error valor ingresado, debe ser 1 o 0 \n");
	}while (ingreso > 1 || ingreso < 0);
	return ingreso;
}

void leerSensor(personas_t* personas,int sensor){
	mensajeContador(personas);
	personas->sensor1 =0;
	personas->sensor2 =0;
	if (sensor == 0){
		printf ("Sensor 1 (puerta de entrada): \n1-Sensor detecto persona\n0-No hay ingreso de persona\n");
		personas->sensor1 = leerIngreso();
	}
	printf ("Sensor 2 (puerta de salida): \n1-Sensor detecto persona\n0-No salio ninguna persona\n");
	personas->sensor2 = leerIngreso();
	personas->contador = personas->contador + personas->sensor1 - personas->sensor2;
}

personas_t inicio (void){
	personas_t configuracionInicial;
	configuracionInicial = seteo ("codigo/configuracion.conf");
	return configuracionInicial;
}


estados_t funcionPuertaAbierta(personas_t* personas){
	leerSensor(personas,0);//0 lee ambos sensores, 1 lee sensor de salida
	if (personas->contador == personas->limiteMaximoPersonas){
		mensajePuertaCerrada();
		return puertaCerrada;
	}
	mensajePuertaAbierta();
	return puertaAbierta;
}


estados_t funcionPuertaCerrada(personas_t* personas){
	leerSensor(personas,1);//0 lee ambos sensores, 1 lee sensor de salida
	if (personas->contador < personas->limiteMaximoPersonas){
		mensajePuertaAbierta();
		return puertaAbierta;
	}
	mensajePuertaCerrada();
	return puertaCerrada;
}

estados_t funcionEspera(personas_t* personas){
	if (personas->contador < personas->limiteMaximoPersonas){
		mensajePuertaAbierta();
		return puertaAbierta;
	}
	mensajePuertaCerrada();
	return puertaCerrada;
}

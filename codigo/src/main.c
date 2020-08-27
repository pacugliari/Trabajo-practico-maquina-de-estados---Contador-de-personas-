#include "../lib/lib.h"

int main(){

	personas_t configuracion;
	configuracion = inicio();
	//estados_t estado = espera; // primer estado

	printf("Maquina de estados- Contador de personas \n");
	printf ("Prueba configuracion inicial: contador=%d \nlimiteMax=%d \n",configuracion.contador,configuracion.limiteMaximoPersonas);

	if (configuracion.sensor1 == true){
		printf ("Sensor1 : True \n");
	}else if (configuracion.sensor1 == false){
		printf ("Sensor1 : False \n");
	}else{
		printf ("Sensor1 : Error \n");
	}
	if (configuracion.sensor2 == true){
		printf ("Sensor2 : True \n");
	}else if (configuracion.sensor2 == false){
		printf ("Sensor2 : False \n");
	}else{
		printf ("Sensor2 : Error \n");
	}


	//estados_t (*fsm[])(tempertura_t) = {f_espera, f_calentar}
	//while(1) estado = (*fsm[estado])(config);

	return 0;
}

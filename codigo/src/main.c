#include "../lib/lib.h"

int main(){
	setvbuf(stdout, NULL, _IONBF, 0);//AGREGADO PARA EVITAR BUG CONSOLA ECLIPSE
	personas_t configuracion;
	configuracion = inicio();
	estados_t estado = espera;

	printf("Maquina de estados- Contador de personas \n");

	estados_t (*contador[])(personas_t*) = {funcionEspera,funcionPuertaCerrada,funcionPuertaAbierta};
	while(1) estado = (*contador[estado])(&configuracion);

	return 0;
}

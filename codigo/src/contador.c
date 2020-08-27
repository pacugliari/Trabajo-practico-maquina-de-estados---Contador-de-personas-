#include "../lib/lib.h"


personas_t inicio (void){
	personas_t configuracionInicial;
	configuracionInicial = seteo ("codigo/configuracion.conf");
	return configuracionInicial;
}

#include "../lib/lib.h"

char* obtenerClave (char* clave){
	char i=0;
	while (*(clave+i)!=' '){
		i++;
	}
	*(clave+i)=0;
	return clave+i+1;
}

personas_t seteo(char* nombreArchivo){
	FILE *archivo;
	char cadena[40],*clave,*valor;
	char variables[2][25]={"limiteMaximoPersonas","personas"};
	personas_t configuracion;
	char errorLimite = false, errorPersonas = false;

	//seteo
	configuracion.contador = 0;
	configuracion.limiteMaximoPersonas = 0;
	configuracion.sensor1 = false;
	configuracion.sensor2 = false;


	if ((archivo = fopen (nombreArchivo,"rt")) == NULL){
		printf ("Error en la apertura archivo configuracion : %s \n",nombreArchivo);
		errorLimite = true;
		errorPersonas = true;
	}else{

		fgets(cadena,40,archivo);

		do{
			clave = cadena;
			if (*(clave) != '#' && strlen(clave)>0){
				valor = obtenerClave (clave);
				for (int i=0;i<2;i++){
					if (!strcmp (clave,variables[i])){
						switch(i){
							case 0:
								configuracion.limiteMaximoPersonas = atoi(valor);
							break;
							case 1:
								if (configuracion.limiteMaximoPersonas < atoi(valor))
									configuracion.contador = configuracion.limiteMaximoPersonas;
								else
									configuracion.contador = atoi(valor);
							break;
						}
					}
				}
			}
			fgets(cadena,40,archivo);
		}while(!feof(archivo));
	}

	if (errorLimite == true && errorPersonas== true){
		//setear valores de error
		configuracion.contador = -1;
		configuracion.limiteMaximoPersonas = -1;
		configuracion.sensor1 = error;
		configuracion.sensor2 = error;
	}

	fclose (archivo);
	return configuracion;
}

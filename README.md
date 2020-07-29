# Trabajo practico maquina de estados "Contador de personas"

## Memoria Descriptiva 

El objetivo del sistema propuesto es modelar la automatizacion de un proceso, en este caso un contador de personas dentro de un local utilizando el concepto de maquina de estados, permitiendo el acceso de personas dentro del local cuando no se haya alcanzado un limite el cual es configurable, y cerrando las puertas cuando el contador interno haya alcanzado el mismo. El ingreso y egreso de las personas es llevado a cabo por dos sensores, uno en la entrada del local y otro en la salida (consideramos que la puerta de entrada y salida son distintas).
Ademas de poseer la capacidad de configurar la cantidad de personas dentro del local antes de arrancar el sistema(en el caso de que haya personas dentro).

## Diagrama

![./recursos/diagrama.png](https://github.com/pacugliari/TrabajoPracticoMaquinaDeEstados_ContadorDePersonas/blob/master/recursos/diagrama.png)

 - __seteo__: Bandera de fin de inicialización
 - __contador__: Lleva la cuenta de las personas dentro del local
 - __s1__: Sensor puerta de entrada,vale 1 si entra una persona 0 caso contrario
 - __s2__: Sensor puerta de salida,vale 1 si entra una persona 0 caso contrario
 - __limiteMax__: Limite maximo configurable permitido de personas dentro del local

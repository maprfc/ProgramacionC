/*
  Practica 3
  Mario Arturo Perez Rangel
  Calcular la fecha correspondiente al ultimo valor que se puede almacenar en la variable time_t

  NOTA: Despues de asignar el valor maximo a la variable de tiempo el programa termina con un error. Investigando
        encontre que en ese caso la funcion ctime regresa un apuntador NULL. Con prueba y error llegue al valor
	0x00efffffffffffff como el ultimo posible valor con el cual ctime regresa una cadena correspondiente
	a una fecha.
	
*/

#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <time.h>
#include <unistd.h>

int main()
{
  time_t tiempo=0x00efffffffffffff;

  printf("Ultima fecha representable: %s\n", ctime(&tiempo));

  tiempo=LONG_MAX;
  printf("Una variable time_t puede representar aproxamadamente hasta %lu anios.\n", ((((tiempo/60)/60)/24)/365));
}

// Practica 9
// Mario Arturo Perez Rangel
// Ultimo argumento en linea de comandos.
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
  if (argc<2) {
    printf ("Debe proporcionar al menos un argumento.\n");
    exit (1);
  }
  // argc es el numero de arguemtos, incluyendo el nombre del programa.
  // argc menos uno es el ultimo argumento en el arreglo de argumentos.
  printf("Ultimo argumento en linea de comandos: %s\n", argv[argc-1]);
}

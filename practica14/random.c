#if 0
// Practica 14
// Mario Arturo Perez Rangel
// Generador de un numero aleatorio.
#endif
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
  int rndfd,tmp;
  char *devrnd = "/dev/random\0";
  int *buff = (int *)calloc(sizeof(int),1);

  rndfd = open(devrnd, O_RDONLY);
  if (rndfd == -1) {
    fprintf (stderr,"No se pudo abrir el generador de numeros aleatorios.\n");
    exit (1234);
  }

  if (read(rndfd, buff,sizeof(int)) != sizeof(int)) {
    fprintf(stderr, "No se pudo leer del dispositivo.\n");
  } else {
    printf("Numero generado %d\n", buff);
  }

  if (close (rndfd) == -1){
    fprintf (stderr, "No se pudo cerrar el dispositivo.");
  }
  
}

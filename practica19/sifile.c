#ifdef 0
// Practica 19
// Mario Arturo Perez Rangel
// Muestra el tamano de un archivo en bits, bytes y kilo bytes.
//
// En linea de comandos recibe el nombre del archivo y si existe calcula la informacion
// requerida apoyandose en lseek.
#endif

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main (int ac, char *v[])
{
  char *archivo;
  struct stat *st = (struct stat *)malloc(sizeof(struct stat));
  int sifd;
  unsigned tamarchivo;

  //
  // El usuario debe proporcionar el nombre de un archivo
  if (ac != 2) {
    fprintf (stderr, "Uso: %s <archivo>\n", v[0]);
    exit(100);
  }

  // Inicializamos las variables que usan memoria
  memset (st, '\0', sizeof(struct stat));
  archivo = (char *)malloc(sizeof(char)*strlen(v[1])+1);
  strcpy(archivo, v[1]);

  // Vemos si el archivo existe
  stat (archivo, st);

  // Si no existe no tiene caso continuar.
  if (st->st_nlink < 1) {
    fprintf (stderr, "No existe el archivo %s.\n", archivo);
    exit (102);
  }

  // Si es posible abrimos el archivo.
  if ((sifd = open(archivo, O_RDONLY)) == -1) {
    perror("Problems openning the file");
    exit (101);
  }


  lseek(sifd,0,SEEK_SET); // Asegura que estamos al inicio del archivo
  tamarchivo = lseek(sifd, 0, SEEK_END); // Va hasta el final del archivo

  // Si todo sale bien tamarchivo tiene el numero de bytes que tiene el archivo
  if (tamarchivo == -1) {
    perror ("Something is wrong");
    exit (103);
  }

  // Entregamos los resultados.
  printf ("El archivo %s mide:\n", archivo);
  printf ("  %u\t bits\n", tamarchivo*8);
  printf ("  %u\t bytes\n", tamarchivo);
  printf ("  %4.2f\t kbytes\n", tamarchivo/1024.0);
}

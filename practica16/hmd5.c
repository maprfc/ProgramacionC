#if 0
// Practica 16
// Mario Arturo Perez Rangel
// Calculo MD5 de un archivo.

// Recibe como argumento el nombre de un archivo.
// Entrega la suma MD5 del archivo.
// Mediante la llamada al sistema stat obtenemos informacion relevante del archivo como:
//   -- verificar la existencia del mismo
//   -- el tipo de archivo (particularmente que sea archivo regular)
//   -- los permisos del archivo
//   -- el tamanio del archivo
//
// Mediante las funciones MD5_Init, MD5_Update y MD5_Final obtenemos la suma MD5 del aarchivo sin
// preocuparnos del tamanio del archivo.
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TAMBUFF   128 // El tamanio de los trozos de informacion a manejar.

int main(int argc, char *argv[])
{
  MD5_CTX mictx;
  unsigned char digest[MD5_DIGEST_LENGTH];
  char mdString[33];
  int archivo, leidos, n;
  struct stat finfo;
  char pmem[TAMBUFF];
  
  if (argc != 2) { // Se recibieron mas parametros de los deseados o no hubo tal.
    fprintf (stderr, "Uso:  %s <archivo>\n", argv[0]);
    fprintf (stderr, "Donde archivo es el nombre de un archivo a cifrar con MD5\n");

    exit (101);
  }

  stat(argv[1], &finfo);   // Consultar informacion del archivo.

  if (finfo.st_nlink < 1) { // Si el numero de ligas al archivo es cero, este no existe.
    fprintf (stderr, "El archivo '%s' no existe.\n", argv[1]);
    exit (102);
  }
  if ((finfo.st_mode & S_IFMT) != S_IFREG) { // No se trata de un archivo regular (es liga, pipe, device u otro tipo)
    fprintf (stderr, "'%s' no es un archivo regular.\n", argv[1]);
  }
  // Revisar que podemos abrir el archivo
  if ((!(finfo.st_mode & S_IRUSR)) &&
      (!(finfo.st_mode & S_IRGRP)) &&
      (!(finfo.st_mode & S_IROTH))
      ) {
    fprintf (stderr, "No contamos con permisos de lectura.\n");
  }

  #if 0
  En este punto sabemos que el archivo existe y lo podemos abrir.
  Se abre y vamos obteniendo partes del archivo. Posteriormente vamos actualizando el calculando MD5.
  #endif
  archivo = open(argv[1], O_RDONLY);

  if (!MD5_Init(&mictx)) { // Preparar la estructura para el MD5
    fprintf (stderr, "Problemas iniciando el calculo MD5.");
  }

  leidos = read(archivo, pmem, TAMBUFF);

  if (leidos == TAMBUFF) { // Hacer el calculo parcial con la parte obtenida.
    if (!MD5_Update(&mictx, (const void *)pmem, leidos)) {
      fprintf (stderr, "Problemas con el calculo MD5, terminando...");
      exit (103);
    }
  } else {
    fprintf (stderr, "Problemas leyendo del archivo, terminando la ejecucion...\n");
    exit (104);
  }

  // Continuamos a lo largo del archivo.
  while (leidos < finfo.st_size) {
    n = read(archivo, pmem, TAMBUFF);

    if (!MD5_Update(&mictx, (const void *)pmem, n)) {
      fprintf (stderr, "Problemas con el calculo MD5, terminando...");
      exit (103);
    }
    leidos += n;
  }
  close (archivo);

  // Terminando de leer del archivo se termina el calculo de la suma MD5.
  if (!MD5_Final((unsigned char*)&digest, &mictx)) {
    fprintf (stderr, "Problemas con el calculo MD5, terminando...");
    exit (104);
  }

  // Se prepara el resultado y se entrega.
  for(int i = 0; i < 16; i++)
    sprintf(&mdString[i*2], "%02x", (unsigned int)digest[i]);

  printf("md5 digest: %s\n", mdString);
  return 0;
}

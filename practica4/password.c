/*
  Practica 4
  Validar una frase (password)
  Mario Arturo Perez Rangel
*/

#include <stdio.h>
#include <string.h>

char *contrasena = "hola123.,";

int main()
{
  unsigned char frase[40];

  printf("Contrasena: ");
  scanf("%*s", frase);
  printf("%s\n", (!strcmp(contrasena,frase))?"OK":"GTFOH!");
}

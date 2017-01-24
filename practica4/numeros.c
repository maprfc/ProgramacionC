/*
  Practica 4
  imprimir numeros del  0  al n.
  Mario Arturo Perez Rangel
*/

#include <stdio.h>

int main()
{
  int i,n;

  printf("Escriba un numero positivo: ");
  scanf("%u", &n);
  for (i=0;i<=n;i++) {
    printf ("%u\n", i);
  }
}

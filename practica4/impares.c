/*
  Practica 4
  Impresion de los numeros nones hasta un numero "n".
  Mario Arturo Perez Rangel
*/

#include <stdio.h>

int main ()
{
  int i,n;

  printf("Escriba un numero positivo: ");
  scanf("%u", &n);
  for (int i=1; i<=n;i++) {
    printf((i&1)?"%d\n":"",i);
  }
}

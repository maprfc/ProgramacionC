/*
  Practica 4
  imprimir un caracter en hexadecimal
  Mario Arturo Perez Rangel
*/

#include <stdio.h>

int main()
{
  unsigned char c;

  printf("Escriba un caracter: ");
  scanf("%c", &c);
  printf("El caracter en hexadecimales: 0x%02x\n", c);
}

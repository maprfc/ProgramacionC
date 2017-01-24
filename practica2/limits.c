/*
  Practica 2
  Mario Arturo Perez Rangel
*/

#include <stdio.h>
#include <limits.h>

int main()
{
  printf ("Valor minimo de un char con signo: %d\n", SCHAR_MIN);
  printf ("Valor maximo de un char con signo: %d\n", SCHAR_MAX);

  printf ("Valor maximo de un char sin signo: %u\n", UCHAR_MAX);

  printf ("Valor minimo un entero corto con signo: %d\n", SHRT_MIN);
  printf ("Valor maximo un entero corto con signo: %d\n", SHRT_MAX);

  printf ("Valor minimo un entero con signo: %d\n", INT_MIN);
  printf ("Valor maximo un entero con signo: %d\n", INT_MAX);

  printf ("Valor maximo un entero sin signo: %u\n", UINT_MAX);

  printf ("Valor minimo un entero largo con signo: %ld\n", LONG_MIN);
  printf ("Valor maximo un entero largo con signo: %ld\n", LONG_MAX);

}

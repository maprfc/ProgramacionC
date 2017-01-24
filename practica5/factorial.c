/*
  Practica 5
  Mario Arturo Perez Rangel

  Calculo del factorial de manera recursiva.
  Solo se puede calcular el factorial de numeros naturales. Puede llegar a ser un numero muy grande.
*/

#include <stdio.h>

unsigned long int factorial(unsigned long int);

int main()
{
  unsigned long int n;

  printf("Numero para calcular el factorial: ");
  scanf("%ul", &n);
  printf("%d! = %lu\n", n, factorial(n));
}

/*
  El factorial de un numero natural n se calcula como n multiplicado por el factorial de n-1.
 */
unsigned long int factorial(unsigned long int n)
{
  return ((!n)?1:n--*factorial(n));
}

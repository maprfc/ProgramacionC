/*
  Practica 4
  Impresion de los numeros nones hasta un numero "n".
  Mario Arturo Perez Rangel
*/

#include <stdio.h>

int esprimo(int p);

int main ()
{
  int i,n,p=1; // 1 es un numero primo

  printf("Cuantos primos: ");
  scanf("%u", &n);
  for (i=1;p<=n;i++)
    if (esprimo(i)) {
      printf ("%d es primo\n", i);
      p++;
    }
}

/*
  Regresa 1 cuando p es un numero primo.
  Regresa 0 cuando p no es numero primo.
*/
int esprimo (int p)
{
  int i,d=0;

  for (i=1;i<=p;i++) {
    (!(p%i))?d++:d;
    if (d>2)
      return 0;
  }
  return 1;
}

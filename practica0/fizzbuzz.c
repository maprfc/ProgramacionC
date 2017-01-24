/*
  Practica 0
  Mario Arturo Perez Rangel
*/

#include <stdio.h>

int main (int argc, char *argv)
{
  int n;

  for (n=1; n<=30; n++) {
    (!(n%3))?printf("Fizz"):1;
    (!(n%5))?printf("Buzz"):1;
    ((n%3)&&(n%5))?printf("%d",n):1;
    printf("\n");
  }
}

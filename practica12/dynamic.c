// Practica12
// Mario Arturo Perez Rangel

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  // Guardamos 
  char *cptr=calloc(strlen("hola")+1,sizeof(char));
  strcpy(cptr,"hola");
  for (;*cptr!=0;cptr++)
    printf("%c\n",*cptr);
}

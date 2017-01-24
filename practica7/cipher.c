//
// Practica 7
// Mario Arturo Perez Rangel
// Cifrado de una cadena con complemento a 1.

#include <stdio.h>
#include <string.h>

int main()
{
  unsigned char cadena[100];

  printf("Frase a cifrar: ");
  scanf("%[a-zA-Z0-9-/.,;:!?¿¡ ]s", cadena);

  for (int i=0; i<strlen(cadena); i++) {
    cadena[i] = ~cadena[i];  // Aplicar complemento a 1 cada caracter.
  }
  printf("Cadena cifrada: %s\n\n", cadena);

  for (int i=0; i<strlen(cadena); i++) {
    cadena[i] = ~cadena[i];  // Aplicar complemento a 1 para regresar.
  }
  printf("Cadena original: %s\n", cadena);
}

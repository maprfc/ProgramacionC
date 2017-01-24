/*
  Practica 4
  Calcular el area de figuras trigonometricas
  Mario Arturo Perez Rangel
*/

#include <stdio.h>
#include <math.h>


float area_triangulo (float, float, float);
float area_rectangulo (float, float);


int main()
{
  unsigned int op;
  
  printf("Calculo de areas.\n");
  printf("1) Triangulo\n");
  printf("2) Cuadrado\n");
  printf("3) Rectangulo\n");
  printf("Elija del menu una figura: ");
  scanf("%u", &op);
  if(op==1) {
    float lado1, lado2, lado3;

    printf("Proporcione la longitud de los tres lados: ");
    scanf("%f %f %f", &lado1, &lado2, &lado3);
    printf ("El area del triangulo es: %4.3f\n",
	    area_triangulo(lado1, lado2, lado3));
  } else {
    if(op==2) { // Un cuadrado es un caso particular del rectangulo
                    // donde todos los lados son iguales
      float lado;

      printf("Proporcione la longitud de un lado: ");
      scanf("%f", &lado);
	printf ("El area del cuadrado es: %4.3f\n",
		area_rectangulo(lado, lado));
    } else {
      if (op==3) {
	float ladoa,ladol;

	printf("Proporcione la longitud de dos lados: ");
	scanf("%f %f", &ladoa, &ladol);
	  printf ("El area del cuadrado es: %4.3f\n",
		area_rectangulo(ladoa, ladol));
      }
    }
  }
}

/*
  Calculo del area de un triangulo conociendo sus tres lados usando la formula de Heron.
  s=(a+b+c)/2
  base*altura/2 = sqrt(s*(s-a)*(s-b)*(s-c))
*/

float area_triangulo (float lado1, float lado2, float lado3)
{
  float area,altura,s;

  s=0.5*(lado1+lado2+lado3);
  altura=(2*sqrt(s*(s-lado1)*(s-lado2)*(s-lado3)))/lado1;
  return(lado1*altura*0.5);
}

/*
  El area de un rectangulo es lado mayor por lado menor.
 */
float area_rectangulo (float ladoa, float ladob)
{
  printf ("Lados del poligono: %4.3f %4.3f\n", ladoa, ladob);
  return (ladoa*ladob);
}

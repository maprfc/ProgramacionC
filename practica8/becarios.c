// Practica 8
// Mario Arturo Perez Rangel
// Base de datos de becarios.
// Se muestra informacion de los becarios. Cada linea corresponde a los
// del becario separados por el caracter ':'.

#include<stdio.h>
#include<string.h>

// Agrupamos varios atributos de un becario en una estructura.
// Asignamos un nombre a dicha estructura
typedef struct {
	char nombre[15];
	int edad;
	float promedio;
	char procedencia[12];
	int generacion;
        unsigned int proyecto:1;  // Bandera. 1: tiene; 0: no tiene proyecto.
} becario;

int main()
{
  // Inicializar el arreglo donde se guarda la informacion de los becarios.
  becario bec[] = { {"Fernando", 24, 9.0, "FIUNAM", 11, 1},
		      {"Saine", 23, 9.7, "FIUNAM", 11, 1},
		      {"Yeudiel", 24, 9.1, "FIUNAM", 11, 1},
		      {"Jennifer", 23, 9.2, "FCAUNAM", 11, 0},
		      {"Virgilio", 23, 9.6, "FIUNAM", 11, 1},
		      {"Diana Olivia", 23, 9.9, "FCUNAM", 11, 1},
		      {"Gonzalo", 23, 9.7, "FIUNAM", 11, 0},
		      {"Diana Laura", 23, 9.5, "FIUNAM", 11, 1},
		      {"Jorge", 24, 9.3, "FIUNAM", 11, 0},
		      {"Ivan", 32, 9.3, "ESIME", 11, 1}
  };

  // Mostrar en la terminal la informacion de los becarios, uno por linea.
  printf("Nombre:Edad:Promedio:Procedencia:Generacion:Proyecto\n");
  for (int i=0;i<sizeof(bec)/sizeof(becario);i++) {
    printf ("%s:%d:%.2f:%s:%d:%s\n", bec[i].nombre, bec[i].edad,
	    bec[i].promedio, bec[i].procedencia, bec[i].generacion,
	    (bec[i].proyecto&1)?"si":"no");
  }
}

// Practica 8
// Mario Arturo Perez Rangel
// Base de datos de becarios.
// Crea una base de datos llamada becarios.db con una tabla becarios
// en sqlite3


#include <sqlite3.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializa_tabla(sqlite3 *);

// Agrupamos varios atributos de un becario en una estructura.
// Asignamos un nombre a dicha estructura
typedef struct {
        unsigned int  id_becario;
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
  becario bec[] = { {1,"Fernando", 24, 9.0, "FIUNAM", 11, 1},
		    {2,"Saine", 23, 9.7, "FIUNAM", 11, 1},
		    {3,"Yeudiel", 24, 9.1, "FIUNAM", 11, 1},
		    {4,"Jennifer", 23, 9.2, "FCAUNAM", 11, 0},
		    {5,"Virgilio", 23, 9.6, "FIUNAM", 11, 1},
		    {6,"Diana Olivia", 23, 9.9, "FCUNAM", 11, 1},
		    {7,"Gonzalo", 23, 9.7, "FIUNAM", 11, 0},
		    {8,"Diana Laura", 23, 9.5, "FIUNAM", 11, 1},
		    {9,"Jorge", 24, 9.3, "FIUNAM", 11, 0},
		    {10,"Ivan", 32, 9.3, "ESIME", 11, 1}
  };

  sqlite3 *bdbec;
  sqlite3_stmt *sql;
  char *linea;

  // Creamos la conexion a la base de datos
  int res = sqlite3_open("becarios.db", &bdbec);

  if (res != SQLITE_OK) {
    fprintf(stderr, "No se pudo abrir la base de datos %s\n", sqlite3_errmsg(bdbec));
    sqlite3_close (bdbec);

    return 101;
  }

  // Preparamos la tabla
  inicializa_tabla(bdbec);

  // Insertamos una tupla por cada una de las entradas del arreglo.
  for (int i=0;i<sizeof(bec)/sizeof(becario);i++) {
    printf("Insertando registro %d en la tabla Becarios\n", i+1);

    // Preparamos la instruccion SQL para agregar una tupla
    sprintf (linea, "INSERT INTO Becarios VALUES(%d,'%s', %d, %.2f, '%s', %d, %d);",
		   bec[i].id_becario, bec[i].nombre, bec[i].edad,bec[i].promedio,
		   bec[i].procedencia, bec[i].generacion,bec[i].proyecto);
    res = sqlite3_prepare_v2 (bdbec, linea, -1, &sql, 0);

    if (res != SQLITE_OK) {
      fprintf(stderr, "No se pudo ejecutar la accion %s\n", sqlite3_errmsg(bdbec));
      sqlite3_close (bdbec);

      return 102;
    }

    // Se manda a ejecutar la instruccion SQL.
    res = sqlite3_step(sql);

    // Si el manejador devuelve un renglon lo capturamos aqui.
    if (res == SQLITE_ROW) {
      printf ("%s\n", sqlite3_column_text(sql,0));
    }
  }
  sqlite3_finalize(sql);
  sqlite3_close(bdbec); // Terminanos las inserciones.
}

/*
  Crea una tabla nueva llamada Becarios dentro de la base de datos becarios.db.

  Recibe el apuntador a la base de datos.
*/
void inicializa_tabla(sqlite3 *bdbec)
{
  char *error = 0;
  // Preparar la instruccion SQL para la tabla
  char *sql = "DROP TABLE IF EXISTS Becarios;"
              "CREATE TABLE Becarios (id_becario INT PRIMARY KEY,"
              "nombre TEXT NOT NULL, edad INT NOT NULL, promedio REAL NOT NULL,"
              "procedencia TEXT NOT NULL, generacion INT NOT NULL, proyecto INT NOT NULL);";

  // Ejecutamos la instruccion
  int res = sqlite3_exec (bdbec, sql, 0, 0, &error);

  if (res != SQLITE_OK) {// Si hubo problemas no tiene caso continuar
    fprintf(stderr, "Se obtuvo un error: %s\n", error);
    sqlite3_free(error);

    exit (103);
  }
}

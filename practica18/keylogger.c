#if 0
  // Practica 18
  // Mario Arturo Perez Rangel
  // Keylogger
#endif

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <linux/input.h>
#include <sys/types.h>
#
int main()
{
  struct input_event e;
  int kbd;
  char *archivo="/dev/input/event4"; // Dispositivo del teclado

  kbd = open (archivo, O_RDONLY);
  if (kbd == -1) {
    fprintf (stderr, "No se tiene acceso al teclado.\n");
  }

    for (;;) {
      if (read(kbd, &e, sizeof(struct input_event)) == sizeof(struct input_event)) {
	if (e.type == EV_KEY && e.value == 1) { // Se presiono una tecla
	  if (e.code == KEY_H) {
	    fprintf(stderr, "h");
	  }
	  if (e.code == KEY_O) {
	    fprintf(stderr, "o");
	  }
	  if (e.code == KEY_L) {
	    fprintf(stderr, "l");
	  }
	  if (e.code == KEY_A) {
	    fprintf(stderr, "a");
	  }
	}
      }
      else
	printf (".");
    }
  close (kbd);
  exit (0);
}

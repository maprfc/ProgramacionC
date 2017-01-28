#define MAX_ENTRIES 256

struct kbmap {
  __u16 code;
  char  letra;
};

void inicia_kbmap (struct kbmap *);

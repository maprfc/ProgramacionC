FUENTES = hmd5.c
OBJS = hmd5.o
PROGRAMA = hmd5
BIBLIOTECAS = -lcrypto

all: ${OBJS} ${BIBLIOTECAS}
	gcc -o ${PROGRAMA} ${OBJS} ${BIBLIOTECAS}

${OBJS}: ${FUENTES}
	gcc -g -c ${FUENTES}

clean:
	rm -f ${PROGRAMA} *.o


FUENTES = keylogger.c
OBJS = keylogger.o
PROGRAMA = keylogger
BIBLIOTECAS = -lcrypto

${OBJS}: ${FUENTES}
	gcc -g -c ${FUENTES}

${PROGRAMA}: ${OBJS} ${BIBLIOTECAS}
	gcc -o ${PROGRAMA} ${OBJS} ${BIBLIOTECAS}

all: ${PROGRAMA}

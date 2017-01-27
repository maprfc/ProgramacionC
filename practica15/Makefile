FUENTES = becarios.c
OBJS = becarios.o
PROGRAMA = becarios
BIBLIOTECAS = -lsqlite3

${OBJS}: ${FUENTES}
	gcc -g -c ${FUENTES}

${PROGRAMA}: ${OBJS} ${BIBLIOTECAS}
	gcc -o ${PROGRAMA} ${OBJS} ${BIBLIOTECAS}
